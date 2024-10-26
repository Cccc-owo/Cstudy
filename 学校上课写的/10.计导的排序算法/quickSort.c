#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��������
void quickSort(int array[], int left, int right){
    int key = array[left], start = left, end = right;
    // ��¼ key, ���ҵ�ֵ

    while(left < right){
        while(left < right && array[right] >= key)
            right--;
        array[left] = array[right]; // ���ұ߱����С��ʱ���滻
        while(left < right && array[left] <= key)
            left++;
        array[right] = array[left]; // ����߱��ұߴ��ʱ���滻
    }
    array[left] = key; // ���ҷ�����ɣ�������λ�ù黹��һ��ֵ
    // keyֵ���ҷֱ�ݹ�

    if(left > start)
        quickSort(array, start, left - 1);
    if(right < end)
        quickSort(array, right + 1, end);
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
    quickSort(ranArray, 0, len - 1);
    end = clock();
    printf("������ɣ���ʱ:%dms\n", end - start);
    // ���򲢼�ʱ

    free(ranArray); // �ͷ������ڴ�
    return 0;
}
