#include <stdio.h>
#include <math.h>
#include <string.h>

//int main(){
//    printf("������һ��ʮ��������");
//    char HEX[64];
//    int neige_A = 0;
//    for(;;neige_A++){
//        printf("\n�������%dλ: ", neige_A + 1);
//        scanf("%c", &HEX[neige_A]);
//        printf("\nget����,������!�������ֹ,������K");
//        getchar();
//        if(HEX[neige_A] == 'K'){
//            break;
//        }
//    }
//
//    int neige_C = 0;
//    neige_A -= 1;
//    int DEC[64];
//    for(;neige_A >= 0;neige_A--){
//        if(HEX[neige_A] == 'A'){
//            DEC[neige_C] = 10;
//        }else if(HEX[neige_A] == 'B'){
//            DEC[neige_C] = 11;
//        }else if(HEX[neige_A] == 'C'){
//            DEC[neige_C] = 12;
//        }else if(HEX[neige_A] == 'D'){
//            DEC[neige_C] = 13;
//        }else if(HEX[neige_A] == 'E'){
//            DEC[neige_C] = 14;
//        }else if(HEX[neige_A] == 'F'){
//            DEC[neige_C] = 15;
//        }else if(HEX[neige_A] == '1'){
//            DEC[neige_C] = 1;
//        }else if(HEX[neige_A] == '2'){
//            DEC[neige_C] = 2;
//        }else if(HEX[neige_A] == '3'){
//            DEC[neige_C] = 3;
//        }else if(HEX[neige_A] == '4'){
//            DEC[neige_C] = 4;
//        }else if(HEX[neige_A] == '5'){
//            DEC[neige_C] = 5;
//        }else if(HEX[neige_A] == '6'){
//            DEC[neige_C] = 6;
//        }else if(HEX[neige_A] == '7'){
//            DEC[neige_C] = 7;
//        }else if(HEX[neige_A] == '8'){
//            DEC[neige_C] = 8;
//        }else if(HEX[neige_A] == '9'){
//            DEC[neige_C] = 9;
//        }
//        neige_C++;
//    }
//
//    neige_C -= 1;
//    int total = 0;
//    for(;neige_A <= neige_C;neige_A++){
//        total += DEC[neige_A]*pow(16,neige_A);
//    }
//    printf("\n���Ϊ:%d", total);
//    return 0;
//}
// ����������ʺɽ����Ҫ�ã��������
// ����İ汾���� Re-remake �˹���������Ϊ֮ǰ���и�����ʺɽ��

int main(){
    long long Dec = 0;
    char Hex[16];
    printf("������һ��ʮ��������(������ 15 λ):");
    fgets(Hex, 16, stdin); // ֻ���ȡǰ�� 15 λ������Ļ��Զ��ϵ���
    char *ptr = Hex;
    ptr += strlen(Hex) - 2;
    Hex[strlen(Hex) - 1] = '\0'; // �������ģ����һ��Ԫ����'\n'���ٺ������EOF
    for(int i = 0;Hex[i];i++) {
        if ((*ptr) == 48 && i == 0){
            break;
        }else if(49 <= (*ptr) && (*ptr) <= 57){
            Dec += ((*ptr) - 48) * (long long)pow(16, i);
        }else if(65 <= (*ptr) && (*ptr) <= 70){
            Dec += ((*ptr) - 55) * (long long)pow(16, i);
        }else{
            printf("����!���������,�������˳�");
            return 1;
        }
        ptr--;
    }
    printf("��Ӧʮ������Ϊ: %lld\n", Dec);
    return 0;
} // ��űȽϺð�
