;; set window icon test

(display #\cr)(flush) ; allocate console for windows
(use os.windows)
(use msicon)

(set-window-icon #f (sys-get-console-title) "icon1.ico")

(print "HIT ENTER KEY!")
(flush)
(read-line)

