#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ����ĺ�
#define MAX_LEN 4096     // ��Ԫ����󳤶�
#define SEN_LEN 256      // ��䳤
#define FILES 2          // ���ļ�����
#define ALL_KEYWORD 37   // ���йؼ��ʵ�����
#define ALL_SYMBOL 24    // ��������������޷����߼���
#define ALL_COMMAND 13   // ����Ԥ����ָ��
#define KEYWORD_CODE 1   // �ؼ��ֵ��ֱ�����ʼ��
#define SYMBOL_CODE 38   // ���ַ��ŵ��ֱ�����ʼ��
#define COMMAND_CODE 62  // Ԥ����ָ���ֱ�����ʼ��
#define NUMBER_CODE 75   // ���ֵ��ֱ�����ʼ��
#define STRING_CODE 76   // �ַ����ֱ���
#define IDEN_CODE 77     // ��ʶ���ֱ���

/* ��Ԫ���ֱ������
 * 1 ~ 37  - �ؼ���
 * 38 ~ 61 - ���ַ���
 * 62 ~ 74 - Ԥ����ָ��
 * 75 ------ ����
 * 76 ------ �ַ������
 * 77 ------ ��ʶ��
 * 0 ------- ������ֹ��
 * ͬʱ��ʹ��ʹ�ö�Ԫ����д洢
 * e.g. int main(){printf("helloworld"); return 0;}
 * (4, int), (89, main) ...) */

// ���ݴ��·��
const char *DATAFILE = "Data.c";

// �����ش���·��
const char *CHECKFILE = "TestCode.c";

// ���ڴ洢����������ͷֽ��
char *SYMBOLS[] = {"+", "-", "*", "/", "%", "=", "<", ">",
                   ";", ":", "[", "]", "{", "}", "(", ")",
                   "&", "|", ",", "'", "\"", "!", ".", "#"
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

// ���仺����
char BUFFER[SEN_LEN];

// ���ֻ�����
char WORD[SEN_LEN];

// ���ڼ���Ķ�Ԫ��
typedef struct {
    int code[MAX_LEN];
    char str[MAX_LEN][SEN_LEN];
} TUPLE[FILES];

TUPLE tuples;

// �ж��Ƿ�Ϊ����
int isNum(char *word){
    if (word[0] >= '0' && word[0] <= '9')
        return 1;
    return 0;
}

// �ж��Ƿ�Ϊ�ؼ���
int isKeyword(char *word){
    for (int i = 0; i < ALL_KEYWORD; i++)
        if (!strcmp(word, KEYWORDS[i]))
            return KEYWORD_CODE + i;
    return 0;
}

// �ж��Ƿ�Ϊ����
int isSymbol(char *word){
    for(int i = 0; i < ALL_SYMBOL; i++)
        if(!strcmp(word, SYMBOLS[i]))
            return SYMBOL_CODE + i;
    return 0;
}

// �ж��Ƿ�Ϊ��ʶ��
int isIdentifier(char *word){
    if(isalpha(word[0]) || word[0] == '_')
        return IDEN_CODE;
    return 0;
}

int isCommand(char *word){
    for(int i = 0; i < ALL_COMMAND; i++)
        if(!strcmp(word, COMMANDS[i]))
            return COMMAND_CODE + i;
    return 0;
}

// �����ļ���������ִʣ�������ת��������
int fileProcessor(FILE *fp, int fileIndex){
    int count = 0, code, inComment = 0, len; // count:��¼��¼��Ĵ���; code:��ʱ�洢�жϺ�����ֵ; inComment:���ڱ���Ƿ��ڶ���ע����
    char *start, *ptr, symbol[2]; // start:��¼���ֺ͵��ʵ���ʼ��ַ; ptr:ָ��; symbol: ���ڴ洢���ţ����ڻ�ɾ��

    while (fgets(BUFFER, SEN_LEN, fp) != NULL) {
        ptr = BUFFER; // ��ָ��ָ��˾����
        while (*ptr != '\0') {
            if (!strncmp(ptr, "//", 2)) {// ��������ע��
                break; // �������м��
            }if(!strncmp(ptr, "/*", 2)){ // ��⵽�Ƕ���ע�Ϳ�ͷ����inComment��Ϊ1
                inComment = 1, ptr += 2;
                continue; // ����������ѭ��
            }if(!strncmp(ptr, "*/", 2)){ // ��鵽�Ƕ���ע����ֹ���ţ���inComment�ĳ�0
                inComment = 0, ptr += 2;
                continue; // ����������ѭ��
            }if(inComment){
                ptr++;
                continue;
            } // ��������ע��

            if(isalnum(*ptr) || *ptr == '_'){ // ��ȡ���ֺ͵���
                start = ptr;
                while(isalnum(*ptr) || *ptr == '_')
                    ptr++;
                len = ptr - start;
                strncpy(WORD, start, len); // �����ʺ����ֿ��������ʻ�����
                WORD[len] = '\0';
                // ���ڽ�ȡ���ֻ�ؼ��ֻ��ʶ��
                code = isKeyword(WORD);
                if(!code && isNum(WORD))
                    code = NUMBER_CODE; // ��������
                if(!code)
                    code = isCommand(WORD);
                if(!code)
                    code = isIdentifier(WORD); // �����ʶ��
                if(code){
                    tuples[fileIndex].code[count] = code;
                    strcpy(tuples[fileIndex].str[count++], WORD); // ����ؼ��֡���ʶ����Ԥ����ָ��
                }
            }else{ // �������
                if(*ptr == '"'){
                    ptr++;
                    while(*ptr != '\"' || *ptr == '\"' && *(ptr - 1) == '\\')
                        ptr++;
                    tuples[fileIndex].code[count] = STRING_CODE;
                    strcpy(tuples[fileIndex].str[count++], "STRING");
                }else{
                    symbol[0] = *ptr, symbol[1] = '\0';
                    code = isSymbol(symbol);
                    if(code){
                        tuples[fileIndex].code[count] = code;
                        strcpy(tuples[fileIndex].str[count++], symbol);
                    }
                }
                ptr++;
            }
        }
    }
    return count;
}

int main() {
    printf("**�뽫ģ��C���Գ�������Ϊ Data.c�������س�������Ϊ TestCode.c��Ȼ�����Ǻͱ��������һ��**\n");
    printf("**��ʼ�����ݽ��д���**\n");
    // ����ʼ
    FILE *fp = fopen(DATAFILE, "r");
    int count[FILES];
    if(fp != NULL){
        count[1] = fileProcessor(fp, 1);
        fclose(fp);
        printf("�ļ��ѹر�\n");
    }else{
        perror("�ļ���ʧ�ܣ������ļ��Ƿ������� Data.c �ļ��Ƿ����!\n");
        return EXIT_FAILURE;
    } // ��ԭ������д���

    fp = fopen(CHECKFILE, "r");
    if(fp != NULL){
        count[0] = fileProcessor(fp, 0);
        fclose(fp);
        printf("�ļ��ѹر�\n");
    }else{
        perror("�ļ���ʧ�ܣ������ļ��Ƿ������� TestCode.c �ļ��Ƿ����!\n");
        return EXIT_FAILURE;
    } // �Ա����س�����д���

    for(int i = 0; i < FILES; i++){
        printf("File: %s\n", !i ? CHECKFILE : DATAFILE);
        for(int j = 0; j < MAX_LEN && tuples[i].code[j] != 0; j++)
            printf("(%d, %s)\n", tuples[i].code[j], tuples[i].str[j]);
    } // �����ȡ�Ķ�Ԫ�飬����debug�Ͳ鿴Ч��

    return 0;
}
