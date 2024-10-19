// ʹ�õ�ʱ��ע�����
// ��ʹ�� gbk �� gb2312
#include "stdio.h"
#include "stdlib.h"

const int REG_LEN = 94;           // ÿ��(��)�� 94 λ(��)
const int FONT_WEIGHT  = 16;      // ���ֵ�����(����)
const int FONT_HEIGHT = 16;       // ���ֵ���߶�(����)
const int DOT_SIZE = 16 * 16 / 8; // һ�����ֵ�����ռ���ֽ���
const int SUB_CODE = 0xA0;        // ����������λ��Ĳ�ֵ

char *FONT_FILE_NAME = "chs16.fon"; // �����ֿ��ļ���
char BIN_DOT[16 * 16 / 8] = {0};    // �洢������Ϣ������

// ��˳����������ÿһλ��Ϣ
void printCharBinDot(char* binDot, int len)
{
    int bitNum = 0;  // �Ѷ�ȡ��λ��
    int bitIndex =0; // ��ǰλ��
    int bitValue;    // ��ǰλ��ֵ
    int charNum;     // ��ǰ�ֽں�
    for (charNum =0; charNum < len; ++charNum)
    {
        // �Ӹߵ���˳�����һ���ֽڵ�ÿλ��Ϣ
        for(bitIndex = 7; bitIndex >= 0; --bitIndex)
        {
            // �����ǰ�ֽڵ� bitIndex λ��ֵ
            bitValue  = ((binDot[charNum] >> bitIndex) & 0x1 );
            printf("%c ", bitValue + 'H');

            // �� 12 λ���һ��
            if ((++bitNum % 16) == 0)
                printf("\n");
        }
    }
}

int main()
{
    FILE *fp = fopen(FONT_FILE_NAME, "rb");
    int stringSize = FONT_WEIGHT * FONT_HEIGHT;
    // ����ģ��
    int byte;
    printf("��������Ҫ���뼸����:");
    scanf("%d", &byte);
    byte = byte * 2 + 1;
    char *STR = (char *)malloc(byte);
    getchar();
    printf("���������: ");
    fgets(STR, byte, stdin);

    int i = 0;
    int offset = 0;
    unsigned char regCode; // ����
    unsigned char bitCode; // λ��

    for(;STR[i];i+=2){
        // ������λ�룬
        regCode = (unsigned char)STR[i] - SUB_CODE;
        bitCode = (unsigned char)STR[i + 1] - SUB_CODE;
        // �ټ��㺺�����ֿ��е�λ�ã������ó����ַ������������ļ��е�ƫ��
        offset = ((regCode - 1) * REG_LEN + bitCode - 1) * DOT_SIZE;

        // ���ֿ��ļ��ж�ȡ���������
        fseek(fp, offset, SEEK_SET);
        fread(BIN_DOT, sizeof(BIN_DOT), 1, fp);

        //����������Ϣ
        printCharBinDot(BIN_DOT, DOT_SIZE);
        printf("\n");
    }

    fclose(fp);
    free(STR);
    system("pause");
    return 0;
}

