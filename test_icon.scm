;; set window icon test

(display #\cr)(flush) ; allocate console for windows
(use os.windows)
(use msicon)

(define (make-fpath . paths)
  (fold (lambda (p1 path)
          (cond ((equal? path "") p1)
                ((#/[\/\\]$/ path) (string-append path p1))
                (else (string-append path "/" p1))))
        ""
        paths))

(define *app-dpath* (if-let1 path (current-load-path) (sys-dirname path) ""))

(define *icon-file-path* (make-fpath *app-dpath* "icon1.ico"))
(print  *icon-file-path*)

(set-window-icon #f (sys-get-console-title) *icon-file-path*)

(print "HIT ENTER KEY!")
(flush)
(read-line)

