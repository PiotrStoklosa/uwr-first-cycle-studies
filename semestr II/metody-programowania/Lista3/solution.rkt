#lang racket

(define (merge list1 list2)
  (define (help counter_list1 counter_list2)
    (cond
      [(and (< counter_list1 (length list1)) (< counter_list2 (length list2)))
       (if (< (list-ref list1 counter_list1) (list-ref list2 counter_list2))
           (append (list (list-ref list1 counter_list1)) (help (+ 1 counter_list1) counter_list2))
           (append (list (list-ref list2 counter_list2)) (help counter_list1 (+ 1 counter_list2))))]
      [(and (= counter_list1  (length list1)) (= counter_list2  (length list2)))
       null]
      [(< counter_list1 (length list1))
       (append (list (list-ref list1 counter_list1)) (help (+ 1 counter_list1) counter_list2))]
      [(< counter_list2 (length list2))
       (append (list (list-ref list2 counter_list2)) (help counter_list1 (+ 1 counter_list2)))]
      ))
  (help 0 0))

(define (split lista)
  (let ((size (length lista)))
  (if (> size 1)
      (cons (drop-right lista (floor (/  size 2))) (take-right lista (floor (/ size 2))))
      lista)))

(define (mergesort lista)
  (if (> (length lista) 1)
      (merge (mergesort (car(split lista))) (mergesort (cdr(split lista))))
      lista))

(provide merge split mergesort)

;Testy

(merge (list 1 3 6 98 98) (list 2 6 7 98 108))
(merge (list -9 2 17 100 1000) (list 7 114 222 333 444))
(display "\n")

(car (split (list 9 8 17 67 13 87 12))) (cdr (split (list 9 8 17 67 13 87 12)))
(car (split (list 98 87 65 2 1))) (cdr (split (list 98 87 65 2 1)))
(display "\n")

(mergesort (list 1 45 98 0 87 -7 987 9 9 1 9))
(mergesort (list 98))
(mergesort (list 98 19))
(mergesort (list))
(mergesort (list 1 98 02 54 -117 9853 22 98765 22 1))
(mergesort (list 987 60 48 22 -9 -78 22 1 -1))
(mergesort (list 1 2 3 4 5 6 7 8 9 10))
(mergesort (list 10 9 8 7 6 5 4 3 2 1))