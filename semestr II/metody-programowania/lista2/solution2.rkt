;Piotr Stoklosa
#lang racket

(define (repeated p n)
  (if (= n 0)
      identity
      (compose p (repeated p (- n 1)))))

(define (avarage-damp f)
  (lambda (x) (avarage x (f x))))

(define (avarage x y)
  (/ (+ x y) 2))

(define (fixed-point f first-guess)
  
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) 0.00001))
  
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  
  (try first-guess))

(define (nth-root n x)
  (fixed-point ((repeated avarage-damp (floor (log n 2))) (lambda (y) (/ x (expt y (- n 1))))) 1.0))

(define (nth-root_with_suppression_test n x suppression)
 (fixed-point ((repeated avarage-damp suppression) (lambda (y) (/ x (expt y (- n 1))))) 1.0))

(provide nth-root)
(provide nth-root_with_suppression_test)

;Testy

(nth-root 8 256)
;(nth-root_with_suppression_test 8 256 2); Podczas uruchomienia tego testu program zapetli sie.
(nth-root_with_suppression_test 8 256 3);
(nth-root 2 100);
(nth-root 17 (expt 6.8 17));
;(nth-root_with_suppression_test 17 (expt 6.8 17) 3); Podczas uruchomienia tego testu program ponwnie zapetli sie.
(nth-root_with_suppression_test 17 (expt 6.8 17) 4);
(nth-root 18 (expt 3.5 18))
(nth-root 7 2187)
(nth-root 5 10)
;(nth-root_with_suppression_test 5 10 1); Ponownie program zapetli sie.
(nth-root_with_suppression_test 5 10 2)

;Eksperymentalnie przy testach dla tlumienia mniej razy niz floor(log2(n)) program zapetlal sie.
;Funkcje avarage, avarage-damp, fixed-point, close-enough? wziete sa z podrecznika.