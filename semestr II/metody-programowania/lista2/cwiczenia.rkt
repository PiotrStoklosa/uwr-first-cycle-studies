#lang racket


(define (inc x)
  (+ x 1))

(define (square x)
  (* x x))

;;złożenie fukncji f1 i f2
(define (compose f1 f2)
  (lambda (x)
    (f1 (f2 x))))
;;przykłady składania funkcji
((compose square inc) 5)
((compose inc square) 5)

(define (identity x)
  x)

;;n-te złożenie funkcji p
(define (repeated p n)
  (if (= n 0)
      identity
      (compose p (repeated p (- n 1)))))

;;przykład
((repeated inc 5) 1)
      
;;wersja rekurencyjna funkcji product
(define (product val next start end)
  (if (> start end)
      1.0
      (* (val start)
         (product val next (next start) end))))

;;wersja iteracyjna funkcji product
(define (product-iter val next start end)
(define (product-iter-help val next start end ans)
  (if (> start end)
      ans
      (product-iter-help val next (next start) end (* ans (val start)))))
   (product-iter-help val next start end 1.0))
  
;;testy funkcji product
(define (new-sum-pi a b f)
  (define (pi-term x)
    (/ (* x (+ x 2)) (* (+ x 1) (+ x 1))))
  (f pi-term (lambda(x) (+ x 2)) a b))

(* 4 (new-sum-pi 2 213818 product))
(* 4 (new-sum-pi 2 213818 product-iter))

;;accumulate rekurencyjny
(define (accumulate combiner null-value term a next b)
  (if ( > a b)
      null-value
      (combiner (term a) (accumulate combiner null-value term (next a) next b))))

(define (product-new val next start end) (accumulate * 1.0 val start next end))

(* 4 (new-sum-pi 2 213818 product-new))

;;accumulate iteracyjny
(define (accumulate-iter combiner null-value term a next b)
  (define (accumulate-iter-help a b ans)
    (if (> a b)
        ans
        (accumulate-iter-help (next a) b (combiner ans (term a)))))
  (accumulate-iter-help a b null-value))

(define (product-new-iter val next start end) (accumulate-iter * 1.0 val start next end))

(* 4 (new-sum-pi 2 213818 product-new-iter))

;;ułamki piętrowe dodaje plus 2 żeby pi działało, PAMIĘTAĆ O TYM!
(define (cont-frac num den k)
  (define (cont-frac-help it k)
    (/ (num it) (+ (den it)
                   (if (< it k)
                       (cont-frac-help (+ it 1) k)
                       0.0))))
  (cont-frac-help 0 k))

(cont-frac (lambda (i) 1.0) (lambda (i) 1.0) 100000)

;;ułamki piętrowe pi
(define (next-a x)
  6)

(define (next-b x)
  (square (+ (* x 2) 1)))

(+ 3 (cont-frac next-b next-a 25))

;;ułamki piętrowe iteracyjnie
(define (cont-frac-iter num den k)
  (define (cont-frac-iter-help ans curr)
    (if (= curr 0)
        ans
        (cont-frac-iter-help
         (/ (num (- curr 1))
            (+ (den (- curr 1)) ans)) (- curr 1))))
  (cont-frac-iter-help 0.0 k))

;;testowanie ułamków piętrowych iteracyjnie
(cont-frac-iter (lambda (i) 1.0) (lambda (i) 1.0) 100000)
(+ 3 (cont-frac-iter next-b next-a 14))

;;ułamki piętrowe arctg(x)


;;ułamki piętrowe repeated-build nie wiem czy to dobrze
( define ( build n d b )
(/ n (+ d b ) ) )

(define (repeated-build k n d b)
  (if (= k 0)
      identity
      (build n d (repeated-build (- k 1) n d b))))




;;zad1

(define (close-enough? x y)
  (< (abs (- x y)) 0.00001))
(define (funkcja num den)
  (define (A n-1 n-2 iter)
    (+ (* (den iter) n-1)(* (num iter) n-2)))
  (define (B n-1 n-2 iter)
    (+ (* (den iter) n-1)(* (num iter) n-2)))
  (define (pom An An-1 Bn Bn-1 F i)
    (if (close-enough? F (/ (A An An-1 i) (B Bn Bn-1 i))) F
        (pom (A An An-1 i) An (B Bn Bn-1 i) Bn (/ (A An An-1 i) (B Bn Bn-1 i) ) (+ i 1))))
  (pom 0 1 1 0 0 1))
    



