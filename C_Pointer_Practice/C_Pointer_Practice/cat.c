#define _CRT_SECURE_NO_WARNINGS  // Visual Studioにおけるファイル処理に関するセキュリティ警告を無視する

#include<stdio.h>  // 標準入出力関数を含む
#include<stdlib.h> // 標準ライブラリ関数を含む

// ファイルの内容を出力する関数
void type_one_file(FILE* fp) {
    int ch;
    while ((ch = getc(fp)) != EOF) {    // ファイルの終端に達するまでループ
        putchar(ch);                    // 各文字をコンソールに出力
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {  // コマンドライン引数が与えられなかった場合
        type_one_file(stdin);  // 標準入力の内容を出力
    }
    else {  // コマンドライン引数が与えられた場合
        int i;
        FILE* fp;

        // プログラム名を除く各コマンドライン引数に対してループ処理
        for (i = 1; i < argc; i++) {
            fp = fopen(argv[i], "rb");  // 読み込み用にバイナリモードでファイルを開く

            // ファイルのオープンに失敗した場合
            if (fp == NULL) {  
                fprintf(stderr, "%s:%s が開けません。\n", argv[0], argv[i]);   // 標準エラーストリームにエラーメッセージを出力
                exit(1);                                                    // エラーステータスでプログラムを終了
            }

            // 開いたファイルの内容を出力
            type_one_file(fp);  
        }
    }
    return 0;  // 成功ステータスを返す
}