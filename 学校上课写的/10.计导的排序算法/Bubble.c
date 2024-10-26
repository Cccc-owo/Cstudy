#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int length){
    int temp;
    for(int i = 0;i < length - 1;i++){
        for(int j = 0;j < length - i - 1;j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){
    int start, end, len, *ranArray;
    srand(time(NULL)); // ��������
    printf("�����������ɶ೤������:");
    scanf("%d", &len);
    ranArray = (int *)malloc(len * sizeof(int));
    for(int n = 0;n < len;n++)
        ranArray[n] = rand() % 1000000;
    // �������ݣ������������

    printf("��ʼ����...\n");
    start = clock();
    bubbleSort(ranArray, len);
    end = clock();
    printf("������ɣ���ʱ:%dms\n", end - start);
    // ���򲢼�ʱ

    free(ranArray); // �ͷ������ڴ�
    return 0;
}