#include <stdio.h>

int main(){
    printf("����������Ҫת��Ϊʮ�����Ƶ�ʮ��������");
    int DEC,neige_A;
    scanf("%d", &DEC);
    int HEX[64];
    int neige_B = 0;

    do{
        neige_A = DEC % 16;
        DEC /= 16;
        HEX[neige_B++] = neige_A; //��ÿһλ�ó����������洢��������
    }while(neige_A == DEC);
    neige_B -= 1;
    for(;neige_B >= 0;neige_B--){ //�����������
        switch(HEX[neige_B]){ //��ÿһλ�������Ϊ��Ӧ��16������
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", HEX[neige_B]);
                break;
        }
    }
    printf("\nת���ɹ�!");
    return 0;
}