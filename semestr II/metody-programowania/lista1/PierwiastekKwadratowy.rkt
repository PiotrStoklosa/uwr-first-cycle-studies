#lang racket
(define (avarage x y) (/ (+ x y) 2))
(define (improve guess x) (avarage guess (/ x guess)))
(define (abs x) (if (< x 0) (- x) x))
(define (square x) (* x x))
(define (good-enough? guess x) (< (abs (- (square guess) x)) 0.01))
(define (sqrt-iter guess x) (if (good-enough? guess x) guess (sqrt-iter(improve guess x)x)))
(define (sqrt x) (sqrt-iter 1.0 x))
