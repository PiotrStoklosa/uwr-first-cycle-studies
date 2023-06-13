#lang racket
(define (cont-frac num den k)
(define (cfrek i k)
         (/ (num i)
            (+ (den i) (if (< i k)
               (cfrek (+ i 2) k )0.0))))
  (+ 3 (cfrek 1 k))
  )
(cont-frac (lambda (x) (* x x)) (lambda (x) 6) 26)