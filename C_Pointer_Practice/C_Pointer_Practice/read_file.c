#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// �������̊��蓖�ăT�C�Y
#define ALLOC_SIZE (256)

// read_line.h �t�@�C�����C���N���[�h
#include "read_line.h"

// �e�L�X�g�f�[�^�ɐV�����s��ǉ�����֐�
char** add_line(char** text_data, char* line, int* line_alloc_num, int* line_num)
{
    // ���݂̔z��̃T�C�Y���s�������e�ł��邱�Ƃ��m�F
    assert(*line_alloc_num >= *line_num);

    // �z��̃T�C�Y���s���Ɠ����ꍇ�́A�T�C�Y�𑝂₷
    if (*line_alloc_num == *line_num) {
        text_data = realloc(text_data, (*line_alloc_num + ALLOC_SIZE) * sizeof(char*));
        *line_alloc_num += ALLOC_SIZE;
    }

    // ���̋󂫈ʒu�ɍs���i�[���A�s�����C���N�������g
    text_data[*line_num] = line;
    (*line_num)++;

    // �X�V���ꂽ�e�L�X�g�f�[�^��Ԃ�
    return text_data;
}

// �t�@�C������e�L�X�g��ǂݍ��ފ֐�
char** read_file(FILE* fp, int* line_num_p)
{
    // �e�L�X�g�f�[�^�̔z���������
    char** text_data = NULL;
    int line_num = 0;
    int line_alloc_num = 0;
    char* line;

    // �t�@�C������1�s���ǂݍ���
    while ((line = read_line(fp)) != NULL) {
        // �V�����s���e�L�X�g�f�[�^�ɒǉ�
        text_data = add_line(text_data, line, &line_alloc_num, &line_num);
    }

    // �t�@�C���̏I�[�ɒB������A�z��̃T�C�Y���s���ɍ��킹�Ē���
    text_data = realloc(text_data, line_num * sizeof(char*));
    // �ǂݍ��񂾍s�����|�C���^�Ɋi�[���ĕԂ�
    *line_num_p = line_num;

    // �X�V���ꂽ�e�L�X�g�f�[�^��Ԃ�
    return text_data;
}

// ���C���֐�
int main(void) {
    char** text_data;
    int line_num;
    int i;

    // �t�@�C������e�L�X�g��ǂݍ��݁A�e�L�X�g�f�[�^�ƍs�����擾
    text_data = read_file(stdin, &line_num);

    // �e�L�X�g�f�[�^���o��
    for (i = 0; i < line_num; i++) {
        printf("%s\n", text_data[i]);
    }

    // �g�p���������������
    free_buffer();

    // �v���O�����̐���I��
    return 0;
}