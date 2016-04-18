;; set window icon test

(display #\cr)(flush) ; allocate console for windows
(use os.windows)
(use msicon)

(define get-data-path
  (let1 dir (if-let1 path (current-load-path)
              (string-append (sys-dirname path) "/") "")
    (lambda (fname) (string-append dir fname))))

(define *icon-file-path* (get-data-path "icon1.ico"))
(print  *icon-file-path*)

(set-window-icon #f (sys-get-console-title) *icon-file-path*)

(print "HIT ENTER KEY!")
(flush)
(read-line)

