;;;
;;; Test msicon
;;;

(use gauche.test)

(test-start "msicon")
(use msicon)
(test-module 'msicon)

;; The following is a dummy test code.
;; Replace it for your tests.
(test* "test-msicon" "msicon is working"
       (test-msicon))

;; If you don't want `gosh' to exit with nonzero status even if
;; the test fails, pass #f to :exit-on-failure.
(test-end :exit-on-failure #t)




