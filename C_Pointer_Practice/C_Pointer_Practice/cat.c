#define _CRT_SECURE_NO_WARNINGS  // Visual Studio�ɂ�����t�@�C�������Ɋւ���Z�L�����e�B�x���𖳎�����

#include<stdio.h>  // �W�����o�͊֐����܂�
#include<stdlib.h> // �W�����C�u�����֐����܂�

// �t�@�C���̓��e���o�͂���֐�
void type_one_file(FILE* fp) {
    int ch;
    while ((ch = getc(fp)) != EOF) {    // �t�@�C���̏I�[�ɒB����܂Ń��[�v
        putchar(ch);                    // �e�������R���\�[���ɏo��
    }
}

int main(int argc, char** argv) {
    if (argc == 1) {  // �R�}���h���C���������^�����Ȃ������ꍇ
        type_one_file(stdin);  // �W�����͂̓��e���o��
    }
    else {  // �R�}���h���C���������^����ꂽ�ꍇ
        int i;
        FILE* fp;

        // �v���O�������������e�R�}���h���C�������ɑ΂��ă��[�v����
        for (i = 1; i < argc; i++) {
            fp = fopen(argv[i], "rb");  // �ǂݍ��ݗp�Ƀo�C�i�����[�h�Ńt�@�C�����J��

            // �t�@�C���̃I�[�v���Ɏ��s�����ꍇ
            if (fp == NULL) {  
                fprintf(stderr, "%s:%s ���J���܂���B\n", argv[0], argv[i]);   // �W���G���[�X�g���[���ɃG���[���b�Z�[�W���o��
                exit(1);                                                    // �G���[�X�e�[�^�X�Ńv���O�������I��
            }

            // �J�����t�@�C���̓��e���o��
            type_one_file(fp);  
        }
    }
    return 0;  // �����X�e�[�^�X��Ԃ�
}