#lang racket
 (define (accumulate combiner null-value term a next b)
  (if ( > a b)
      null-value
      (combiner (term a) (accumulate combiner null-value term (next a) next b))))

(define (product-new val next start end) (accumulate * 1.0 val start next end))