// ���յ�C���Ա�׼: C99
// ���õ�ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ����ĺ�
#define ALL_KEYWORD 37  // ���йؼ��ʵ�����
#define DATAFILES 16    // ��������ļ���
#define ALL_SYMBOL 27   // ��������������޷����߼���
#define ALL_COMMAND 13  // ����Ԥ����ָ��
#define NUMBER 10       // ��������
#define KEYWORD_CODE 0  // �ؼ��ֵ��ֱ�����ʼ��
#define SYMBOL_CODE 37  // ���ַ��ŵ��ֱ�����ʼ��
#define NUMBER_CODE 64  // ���ֵ��ֱ�����ʼ��
#define COMMAND_CODE 74 // Ԥ����ָ����ֱ�����ʼ��
#define STRING_CODE 87  // �ַ����ֱ���
#define STRUCT_CODE 88  // �ṹ���ֱ���
#define FUNC_CODE 89    // �����ֱ���
#define ENUM_CODE 90    // ö���ֱ���
#define HEADER_CODE 91  // ͷ�ļ��ֱ���
#define OTHER_CODE 92   // Ԥ����ָ��������ı�ʶ���ֱ���
#define MAX_LEN 4096    // ��Ԫ�������



/*��Ԫ���ֱ������
 * 0 ~ 36  - �ؼ���
 * 37 ~ 63 - ���ַ���
 * 64 ~ 73 - ����
 * 74 ~ 86 - Ԥ����ָ��
 * 87 ------ �ַ������
 * 88 ------ �ṹ����
 * 89 ------ �������
 * 90 ------ ö�ٱ��
 * 91 ------ ͷ�ļ����
 * 92 ------ Ԥ����ָ��������ı�ʶ��
 * ͬʱ��ʹ�ö�Ԫ����д洢
 * e.g. int main(){printf("helloworld"); return 0;}
 * (3, "int"), (89, "main"), ... */



// ���ݴ��·��
char *DATA_ADDR = "/data/";

// �����ش���·��
char *CHECKFILE = "/check/";

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
char *COMMANDS[] = {"#if", "endif", "#include", "#define", "#error", "#else", "#ifdef",
                      "ifndef", "#undef", "#line", "#include_next", "#pragma", "#warning"
                    };

struct Tuple { // ��Ԫ��
    int count;
    char *word;
} TUPLE[MAX_LEN];

void compare(){

}

void fileProcessor(){

}

int main(){
    printf("**�뽫ģ��C���Գ������data�ļ����ڣ������صĳ������check�ļ�����**\n");
    printf("**��ʼ�����ݽ��д���**");
}