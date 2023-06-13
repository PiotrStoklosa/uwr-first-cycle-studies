;;Cwiczenie 10 Lista 2

#lang racket
(define (square x) (* x x))


(define (close-enough? x y)
  (< (abs (- x y)) 0.00001))


(define (cont-frac num den)
  
  (define (A n-1 n-2 iter)
    (+ (* (den iter) n-1)(* (num iter) n-2)))
  
  (define (B n-1 n-2 iter)
    (+ (* (den iter) n-1)(* (num iter) n-2)))
  
  (define (main An-1 An-2 Bn-1 Bn-2 i)
    (if (close-enough? (/ An-1 Bn-1) (/ (A An-1 An-2 i) (B Bn-1 Bn-2 i))) (/ An-1 Bn-1)
        (main (A An-1 An-2 i) An-1 (B Bn-1 Bn-2 i) Bn-1 (+ i 1))))
  
  (main 0 1 1 0 1))

(provide cont-frac)

;TESTY

(cont-frac (lambda(x) 1.0) (lambda (x) 1.0)) ; 1/φ

(+ 3 (cont-frac (lambda (x) (* (- (* 2 x) 1.0) (- (* 2 x) 1.0)))  (lambda(x) 6.0))) ; π

(define (arctangens x)
  (cont-frac (lambda (z) (if (= z 1) x (square ( * (- z 1) x )))) (lambda (z) (- (* 2.0 z) 1.0))))

(arctangens 0.5) ;arctg(0.5)