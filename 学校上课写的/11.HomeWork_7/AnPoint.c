// 6.8
#include <stdio.h>

int main(){
    int doubleArr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++)
            printf("%d ", doubleArr[i][j]);
        printf("\n");
    }
//    for(int i = 0; i < 3; i++)
//        for(int j = 0; j < 4; j++)
//            scanf("%d", &doubleArr[i][j]);
    // �����ж�����
    int checkCol[3][4] = {0};
    int checkRow[3][4] = {0};
    // ÿ���ж����
    for(int i = 0; i < 3; i++){
        int key = 0;
        for(int k = 0; k < 4; k++){
            if (doubleArr[i][k] > doubleArr[i][key])
                key = k;
        }
        checkCol[i][key]++;
    }
    // ÿ���ж���С
    for(int i = 0; i < 4; i++){
        int key = 0;
        for(int k = 0; k < 3; k++){
            if(doubleArr[k][i] < doubleArr[key][i])
                key = k;
        }
        checkRow[key][i]++;
    }
    // ���
    int check = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
            if(checkCol[i][j] && checkRow[i][j]){
                printf("����Ϊ%d���ڵ�%d�е�%d����\n", doubleArr[i][j], i + 1, j + 1);
                check = 1;
            }
    if(!check)
        printf("�ް���\n");
    return 0;
}
