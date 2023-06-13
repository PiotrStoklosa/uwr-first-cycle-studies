#lang racket
(define (cont-frac num den k)
(define (cfrek i k)
         (/ (num i)
            (+ (den i) (if (< i k)
               (cfrek (+ i 1) k )0.0))))
  (cfrek 0 k)
  )
(cont-frac (lambda (x) 1) (lambda (x) 1) 5000)