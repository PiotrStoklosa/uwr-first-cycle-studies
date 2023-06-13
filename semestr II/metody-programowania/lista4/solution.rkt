#lang racket

(define (inc n)
  (+ n 1))

;;; tagged lists
(define (tagged-list? len-xs tag xs)
  (and (list? xs)
       (= len-xs (length xs))
       (eq? (first xs) tag)))

;;; ordered elements
(define (make-elem pri val)
  (cons pri val))

(define (elem-priority x)
  (car x))

(define (elem-val x)
  (cdr x))

;;; leftist heaps (after Okasaki)

;; data representation
(define leaf 'leaf)

(define (leaf? h) (eq? 'leaf h))

(define (hnode? h)
  (and (tagged-list? 5 'hnode h)
       (natural? (caddr h))))

(define (make-hnode elem heap-a heap-b)
  (let* ((ra (rank heap-a)) (rb (rank heap-b)) (test (>= ra rb)))
  (list 'hnode elem (if test (inc rb) (inc ra)) (if test heap-a heap-b) (if test heap-b heap-a))))

(define (hnode-elem h)
  (second h))

(define (hnode-left h)
  (fourth h))

(define (hnode-right h)
  (fifth h))

(define (hnode-rank h)
  (third h))

(define (hord? p h)
  (or (leaf? h)
      (<= p (elem-priority (hnode-elem h)))))

(define (heap? h)
  (or (leaf? h)
      (and (hnode? h)
           (heap? (hnode-left h))
           (heap? (hnode-right h))
           (<= (rank (hnode-right h))
               (rank (hnode-left h)))
           (= (rank h) (inc (rank (hnode-right h))))
           (hord? (elem-priority (hnode-elem h))
                  (hnode-left h))
           (hord? (elem-priority (hnode-elem h))
                  (hnode-right h)))))

(define (rank h)
  (if (leaf? h)
      0
      (hnode-rank h)))

;; operations

(define empty-heap leaf)

(define (heap-empty? h)
  (leaf? h))

(define (heap-insert elt heap)
  (heap-merge heap (make-hnode elt leaf leaf)))

(define (heap-min heap)
  (hnode-elem heap))

(define (heap-pop heap)
  (heap-merge (hnode-left heap) (hnode-right heap)))

(define (heap-merge h1 h2)
  (cond
   [(leaf? h1) h2]
   [(leaf? h2) h1]
   [(<= (elem-priority (heap-min h1)) (elem-priority (heap-min h2))) (make-hnode (heap-min h1) (hnode-left h1) (heap-merge (hnode-right h1) h2))]
   [(make-hnode (heap-min h2) (hnode-left h2) (heap-merge h1 (hnode-right h2)))]))


(define (heapsort lista)
  
  (define (pop-all heap1)
    (define (new-list lista heap)
      (if (heap-empty? heap)
          lista
          (new-list (append lista (list (elem-val (heap-min heap)))) (heap-pop heap))))
    (new-list '() heap1))
  
  (define (insert-all lista1)
    (define (new-heap heap lista)
      (if (eq? lista '())
          heap
          (new-heap (heap-insert (make-elem (car lista) (car lista)) heap) (cdr lista))))
    (new-heap empty-heap lista1))

  (pop-all (insert-all lista)))

(define (sorted? xs)
  (cond [(null? xs)              true]
        [(null? (cdr xs))        true]
        [(<= (car xs) (cadr xs)) (sorted? (cdr xs))]
        [else                    false]))

;Testy

(heapsort (list 9 8 7 0 19 -98 1234 988888 0 0 8))
(heapsort (list 10 9 8 7 6 5 4 3 2 1))
(heapsort (list 1 2 3 4 5 6 7 8 9 10))
(heapsort (list 9 89 7 98 -6 19 24 998))
(heapsort (list 10 9 8 7 6 5 4 3 2 1))
(heapsort (list 9898 764 -98 21 98 8888 12))