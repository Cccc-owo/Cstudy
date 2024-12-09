// ���յ�C���Ա�׼: C99
// ���õ�ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ����ĺ�
#define MAX_LEN 4096     // ��Ԫ����󳤶�
#define SEN_LEN 256      // ��䳤
#define FILES 2          // ���ļ�����
#define ALL_KEYWORD 37   // ���йؼ��ʵ�����
#define ALL_SYMBOL 27    // ��������������޷����߼���
#define ALL_COMMAND 13   // ����Ԥ����ָ��
#define NUMBER 10        // ��������
#define KEYWORD_CODE 1   // �ؼ��ֵ��ֱ�����ʼ��
#define SYMBOL_CODE 38   // ���ַ��ŵ��ֱ�����ʼ��
#define NUMBER_CODE 65   // ���ֵ��ֱ�����ʼ��
#define COMMAND_CODE 75  // Ԥ����ָ����ֱ�����ʼ��
#define STRING_CODE 88   // �ַ����ֱ���
#define STRUCT_CODE 89   // ��ʶ���ֱ���
#define OTHER_CODE 93    // Ԥ����ָ��������ı�ʶ���ֱ���

/* ��Ԫ���ֱ������
 * 1 ~ 37  - �ؼ���
 * 38 ~ 64 - ���ַ���
 * 65 ~ 74 - ����
 * 75 ~ 87 - Ԥ����ָ��
 * 88 ------ �ַ������
 * 89 ------ ��ʶ��
 * 0 ------- ������ֹ��
 * ͬʱ��ʹ��ʹ�ö�Ԫ����д洢
 * e.g. int main(){printf("helloworld"); return 0;}
 * (4, int), (89, main) ...) */

// ���ݴ��·��
const char *DATAFILE = "Data.c";

// �����ش���·��
const char *CHECKFILE = "TestCode.c";

// ���ڴ洢����������ͷֽ��
char *SYMBOLS[] = {"+", "-", "*", "/", "%", "=", "<", ">", ">=", "<=",
                    "!=", "==", ";", ":", "[", "]", "{", "}", "(", ")",
                   "&", "|", ",", "'", "\"", "!", ".",
                    };

// ���ڴ洢���йؼ���
char *KEYWORDS[] = {"float", "double", "char", "int", "long", "short",
                    "struct", "union", "enum", "void", "signed", "unsigned", "const",
                    "while", "for", "continue", "break", "if", "else", "do",
                    "goto", "case", "switch", "return", "default", "break",
                    "sizeof", "extern", "register", "static", "auto", "volatile",
                    "inline", "typedef", "_Bool", "_Complex", "_Imaginary",
                    };

// ���ڴ洢����Ԥ����ָ��
char *COMMANDS[] = {"if", "endif", "include", "define", "error", "else", "ifdef",
                      "ifndef", "undef", "line", "include_next", "pragma", "warning"
                    };

// ������
char *buffer;

// ���������
char *word_A, *word_B, *word_C;

// ���ڼ���Ķ�Ԫ��
typedef struct {
    int code[MAX_LEN];
    char str[MAX_LEN];
} TUPLE[FILES];

int isNum(char *words){
    if(words[0] >= '0' && words[0] <= '9')
        return 1;
    return 0;
}

/* TODO
 * �������ƶȼ��㺯�� */
double cosCalculate(){

}

/* TODO
 * �ȽϺ���
 * ʹ�����ɺõ������������ */
void compare(){

}

/* TODO
 * �����ļ���������ת�������� */
void fileProcessor(FILE *fp){
    int count = 0;
    while(fgets(buffer, SEN_LEN, fp) != NULL){
        word_A = strtok(buffer, " \t\n");
        while(word_A != NULL){
            printf("%s\n\n", word_A);

            word_B = word_A;
            strchr(word_B, );
            while(*word_B != '\0'){

                word_B++;
            }

            word_A = strtok(NULL, " \t\n");
            count++;
        }
    }
}

int main(){
    printf("**�뽫ģ��C���Գ������data�ļ����ڣ������صĳ������check�ļ�����**\n");
    printf("**��ʼ�����ݽ��д���**\n");
    // �����ʼ���
    FILE *fp = NULL;
    fp = fopen(DATAFILE, "r");
    if(fp != NULL){
        fileProcessor(fp);
        if(fclose(fp)){
            perror("�ļ��޷������رգ�\n");
            return EXIT_FAILURE;
        }else
            printf("�ļ��ѹر�\n");
    }else{
        perror("�ļ���ʧ�ܣ������ļ��Ƿ�������Data.c�ļ��Ƿ����!\n");
        return EXIT_FAILURE;
    }
    return 0;
}