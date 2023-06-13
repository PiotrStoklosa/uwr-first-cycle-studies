#lang racket
(define sum-pi
  (lambda (a b c) (if (> b c) a (sum-pi (* a (/ (* (- b 1) (+ b 1))(* b b))) (+ b 2) c))))
(define (product val next start end)
  (if (> start end) 1.0 (* (val start) (product val next (next start) end))))
(define (next x) (+ x 2))
(define (val x) (/ (* (- x 1) (+ x 1))(* x x)))