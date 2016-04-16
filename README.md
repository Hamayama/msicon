# msicon

## 概要
- Gauche の Windows 版で、ウィンドウの左上に表示されるアイコンを設定するための  
  モジュールです。


## インストール方法
1. 事前準備  
   事前に、Gauche および開発環境がインストールされている必要があります。  
   また、開発環境に MSYS2/MinGW-w64 (64bit/32bit) を使用する場合には、  
   Gauche の開発最新版のソースの取得、および、コンパイルも必要になります。  
   開発環境のインストールと、Gauche のコンパイルについては、以下のページを参照ください。  
   ＜開発環境に MinGW (32bit) を使う場合＞  
   https://gist.github.com/Hamayama/19d7e779cec0480af0cf  
   ＜開発環境に MSYS2/MinGW-w64 (64bit/32bit) を使う場合＞  
   https://gist.github.com/Hamayama/6666e5d2c8d5167d22f7

2. ファイルのダウンロード  
   本サイト( https://github.com/Hamayama/msicon )のソースを、  
   (Download Zip ボタン等で)ダウンロードして、作業用のフォルダに展開してください。  
   例えば、作業用のフォルダを c:\work とすると、  
   c:\work\msicon の下にファイル一式が配置されるように展開してください。  
   (注意) 作業用フォルダのパスには、空白を入れないようにしてください。

3. コンパイルとインストール  
   MinGW (32bit) 環境であれば、コマンドプロンプトを開いて、以下のコマンドを実行してください。  
   また、MSYS2/MinGW-w64 (64bit) 環境であれば、c:\msys64\mingw64_shell.bat を起動して、  
   以下のコマンドの bash 以外を実行してください。  
   また、MSYS2/MinGW-w64 (32bit) 環境であれば、c:\msys64\mingw32_shell.bat を起動して、  
   以下のコマンドの bash 以外を実行してください。
   ```
     bash
     cd /c/work/msicon
     ./configure    # Makefile等を生成します
     make           # コンパイルを実行します
     make install   # Gaucheのライブラリフォルダにインストールします
     make check     # テストを実行します
   ```
   (注意) コンパイルには、Gauche をコンパイルした開発環境と同じ開発環境を使用してください。  
   例えば、Gauche を MinGW (32bit) 環境でコンパイルして、  
   本モジュールを MSYS2/MinGW-w64 (64bit) 環境でコンパイルすると、  
   エラーが発生して正常に動作しません。  
   
   (注意) 環境によっては make install を実行すると、  
   「*** ERROR: mkstemp failed」というエラーが発生します。  
   このエラーは c:\Program Files (x86) のフォルダに 書き込み権限がないとき等に発生します。  
   その場合は、コマンドプロンプトやバッチファイルを実行するときに、  
   右クリックして、「管理者として実行」を選択してください。  
   そして再度上記のコマンドを実行してください。

- 以上です。


## 使い方
```
  (use msicon) ; モジュールをロードします
  (set-window-icon #f "title" "icon1.ico")
               ; ウィンドウにアイコンファイルを設定します
               ; 第1引数にはウィンドウのクラス名を指定します。#fだと未指定になります。
               ; 第2引数にはウィンドウのタイトル名を指定します。#fだと未指定になります。
               ; 第3引数にはアイコンファイルのパスを指定します。
```


## 注意事項
1. アイコンファイルは、ico ファイルフォーマットである必要があります。  
   また、リソースファイルに埋め込んだアイコンについては、非対応です。

2. 本モジュールは、Windows API の FindWindow を使用して、ウィンドウを検索しています。  
   set-window-icon の第1引数と第2引数は、この API の引数になります。  
   また、この API の制約のため、うまく検索できないケースがあります。

3. タスクバーに表示されるアイコンについては、変更されないケースがあります。


## 環境等
- OS
  - Windows 8.1 (64bit)
- 環境
  - MinGW (32bit) (gcc v4.8.1)
  - MSYS2/MinGW-w64 (64bit) (gcc version 5.3.0 (Rev1, Built by MSYS2 project))
  - MSYS2/MinGW-w64 (32bit) (gcc version 5.3.0 (Rev1, Built by MSYS2 project))
- 言語
  - Gauche v0.9.4
  - Gauche v0.9.5_pre1

## 履歴
- 2016-4-16 v1.00 (初版)
- 2016-4-16 v1.01 デバッグ用処理一部修正


(2016-4-16)
