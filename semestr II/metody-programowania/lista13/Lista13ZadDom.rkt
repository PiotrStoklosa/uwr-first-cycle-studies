#lang typed/racket

(provide parse typecheck)

(define-type Expr (U const binop bool var-expr comp logic let-ex if-ex))
(define-type Value Number)
(define-type BinopSym (U '+ '- '* '/))
(define-type CompSym (U '< '> '= '<= '>=))
(define-type LogicSym (U 'and 'or))
(define-type LetSym 'let)
(define-type IfSym 'if)
(define-type EType (U 'real 'boolean))

(struct const ([val : Real]) #:transparent)
(struct binop ([op : BinopSym] [l : Expr] [r : Expr]) #:transparent)
(struct bool ([val : Boolean]) #:transparent)
(struct var-expr ([id : Symbol]) #:transparent)
(struct comp ([op : CompSym] [l : Expr] [r : Expr]) #:transparent)
(struct logic ([op : LogicSym] [l : Expr] [r : Expr]) #:transparent)
(struct let-ex ([x : Symbol] [e1 : Expr] [e2 : Expr]) #:transparent)
(struct if-ex ([e1 : Expr] [e2 : Expr] [e3 : Expr]) #:transparent)

(define-predicate binop-sym? BinopSym)
(define-predicate expr? Expr)
(define-predicate value? Value)
(define-predicate comp-sym? CompSym)
(define-predicate logic-sym? LogicSym)
(define-predicate let-sym? LetSym)
(define-predicate if-sym? IfSym)

;; Składnia konkretna                   #t   != 'true

(: parse (-> Any Expr))
(define (parse q)
  (match q
    [`(,op ,e1 ,e2)
     #:when (binop-sym? op)
     (binop op (parse e1) (parse e2))]
    [`(,op ,e1 ,e2)
     #:when (comp-sym? op)
     (comp op (parse e1) (parse e2))]
    [`(,op ,e1 ,e2)
     #:when (logic-sym? op)
     (logic op (parse e1) (parse e2))]
    [`(,sym ,e ,e2)
     #:when (let-sym? sym)
     (match e
       [`(,x ,e1)
        #:when (symbol? x)
        (let-ex x (parse e1) (parse e2))])]
    [`(,sym ,e1 ,e2 ,e3)
     #:when (if-sym? sym)
     (if-ex (parse e1) (parse e2) (parse e3))]
    [_ #:when (eq? q 'true)
       (bool #t)]
    [_ #:when (eq? q 'false)
       (bool #f)]
    [_ #:when (symbol? q) (var-expr q)]
    [_ #:when (real? q) (const q)]
  
    ))

(define-type Env environ)
(struct environ ([xs : (Listof (Pairof Symbol(U EType #f)))]))
(: env-empty Env)
(define env-empty (environ null))
(: env-add (-> Symbol (U EType #f) Env Env))
(define (env-add x v env)
  (environ (cons (cons x v) (environ-xs env))))
(: env-lookup (-> Symbol Env (U EType #f)))
(define (env-lookup x env)
  (: assoc-lookup (-> (Listof (Pairof Symbol (U EType #f))) (U EType #f)))
  (define (assoc-lookup xs)
    (cond [(null? xs) (error "Unknown identifier" x)]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup (environ-xs env)))



(: typecheck-t (-> Expr Env (U EType #f)))
(define (typecheck-t e env)
  (match e
    [(const n) (if (real? n) 'real #f)]
    [(bool n) (if (boolean? n) 'boolean #f)]
    [(var-expr x) (env-lookup x env)]
    [(binop op l r) (if (and (eq? (typecheck-t l env) 'real)
                             (eq? (typecheck-t r env) 'real))
                        'real
                        #f)]
    [(comp op l r) (if (and (eq? (typecheck-t l env) 'real)
                            (eq? (typecheck-t r env) 'real))
                       'boolean
                       #f)]
    [(logic op l r) (if (and (eq? (typecheck-t l env) 'boolean)
                             (eq? (typecheck-t r env) 'boolean))
                        'boolean
                        #f)]
    [(let-ex x e1 e2) (if (eq? (typecheck-t e1 env) #f)
                          #f
                          (typecheck-t e2 (env-add x (typecheck-t e1 env) env)))]
    [(if-ex e1 e2 e3) (if (eq? (typecheck-t e1 env) 'boolean)
                          (if (eq? (typecheck-t e2 env) (typecheck-t e3 env))
                              (typecheck-t e2 env)
                              #f)
                          #f)]
  ))

(: typecheck (-> Expr (U EType #f)))
(define (typecheck e) (typecheck-t e env-empty))

(typecheck (parse '(+ 2 3)))
(typecheck (parse '(let (x 2) (and x true))))

