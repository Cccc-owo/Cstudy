// 7.19
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RMAX 35
#define RN 5
#define BMAX 12
#define BN 2

void swap(int array[], int p1, int p2){
    int temp = array[p1];
    array[p1] = array[p2];
    array[p2] = temp;
}

void init(int array[], int n){
    for(int i = 0; i < n; i++)
        array[i] = i + 1;
}

int myRand(int array[], int end, int pos){
    int k = rand() % (end - pos);
    swap(array, k, end - pos);
    return array[end - pos];
}

void choice(int array[], int choice[], int len, int amount){
    for(int i = 0; i < amount; i++)
        choice[i] = myRand(array, len - 1, i);
}

// ��������
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
    int sheet, blueBalls[BMAX], redBalls[RMAX], redChoice[RN], blueChoice[BN], copy;
    srand(time(NULL));
    printf("How many lotteries do you want to buy(1~9):");
    scanf("%d", &sheet);
    copy = sheet;
    printf("They are:\n");
    for(int i = 1; i <= sheet; i++){
        init(blueBalls, BMAX);
        init(redBalls, RMAX);
        // ��ʼ������������ID
        choice(blueBalls, blueChoice, BMAX, BN);
        choice(redBalls, redChoice, RMAX, RN);
        // ���ѡȡ5�������2������
        quickSort(redChoice, 0, RN - 1);
        quickSort(blueChoice, 0, BN - 1);
        // ��������
        printf("<%d> ", i);
        for(int j = 0; j < RN; j++)
            printf("%02d ", redChoice[j]);
        printf("-- ");
        for(int j = 0; j < BN; j++)
            printf("%02d ", blueChoice[j]);
        printf("\n");
    }
    return 0;
}