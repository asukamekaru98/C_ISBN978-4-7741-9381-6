#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// メモリの割り当てサイズ
#define ALLOC_SIZE (256)

// read_line.h ファイルをインクルード
#include "read_line.h"

// テキストデータに新しい行を追加する関数
char** add_line(char** text_data, char* line, int* line_alloc_num, int* line_num)
{
    // 現在の配列のサイズが行数を収容できることを確認
    assert(*line_alloc_num >= *line_num);

    // 配列のサイズが行数と同じ場合は、サイズを増やす
    if (*line_alloc_num == *line_num) {
        text_data = realloc(text_data, (*line_alloc_num + ALLOC_SIZE) * sizeof(char*));
        *line_alloc_num += ALLOC_SIZE;
    }

    // 次の空き位置に行を格納し、行数をインクリメント
    text_data[*line_num] = line;
    (*line_num)++;

    // 更新されたテキストデータを返す
    return text_data;
}

// ファイルからテキストを読み込む関数
char** read_file(FILE* fp, int* line_num_p)
{
    // テキストデータの配列を初期化
    char** text_data = NULL;
    int line_num = 0;
    int line_alloc_num = 0;
    char* line;

    // ファイルから1行ずつ読み込む
    while ((line = read_line(fp)) != NULL) {
        // 新しい行をテキストデータに追加
        text_data = add_line(text_data, line, &line_alloc_num, &line_num);
    }

    // ファイルの終端に達した後、配列のサイズを行数に合わせて調整
    text_data = realloc(text_data, line_num * sizeof(char*));
    // 読み込んだ行数をポインタに格納して返す
    *line_num_p = line_num;

    // 更新されたテキストデータを返す
    return text_data;
}

// メイン関数
int main(void) {
    char** text_data;
    int line_num;
    int i;

    // ファイルからテキストを読み込み、テキストデータと行数を取得
    text_data = read_file(stdin, &line_num);

    // テキストデータを出力
    for (i = 0; i < line_num; i++) {
        printf("%s\n", text_data[i]);
    }

    // 使用したメモリを解放
    free_buffer();

    // プログラムの正常終了
    return 0;
}