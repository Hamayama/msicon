;; -*- coding: utf-8 -*-
;;
;; msicon.scm
;; 2016-4-22 v1.02
;;
;; ＜内容＞
;;   Gauche の Windows 版で、ウィンドウの左上に表示されるアイコンを設定するための
;;   モジュールです。
;;
;;   詳細については、以下のページを参照ください。
;;   https://github.com/Hamayama/msicon
;;
(define-module msicon
  (export
    test-msicon
    set-window-icon
    ))
(select-module msicon)

;; Loads extension
(dynamic-load "msicon")

;;
;; Put your Scheme definitions here
;;

