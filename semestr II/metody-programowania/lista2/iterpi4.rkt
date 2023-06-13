#lang racket
(define (product-iter val next start end)
(define (product-iter-help val next start end ans)
  (if (> start end)
      ans
      (product-iter-help val next (next start) end (* ans (val start)))))
   (product-iter-help val next start end 1.0))