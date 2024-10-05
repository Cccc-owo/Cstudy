#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Bubble(int arr[], int arrLength){ // ����ͨͨ��ð���������
    int TEMP;
    for(int n = 0;n < arrLength - 1;n++){
        if(arr[n + 1] < arr[n]){
            TEMP = arr[n + 1];
            arr[n + 1] = arr[n];
            arr[n] = TEMP;
        }
    }
}

int Dichotomy(int arr[], int arrLength, int target){ // ����ͨͨ�Ķ��ַ�����
    int right = arrLength - 1;
    int left = 0;
    int mid;
    while(1){
        mid = (right + left) / 2;
        if(arr[mid] > target){
            right = mid - 1;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            break;
        }
    }
    return mid;
}

int sum(int arr[], int length){
    int sum = 0;
    for(int n = 0;n < length;n++){
        sum += arr[n];
    }
    return sum;
}

int main(){
    srand(time(NULL)); // �����������������
    int length, testTime, startTime, endTime, targetPosition, maxTime, minTime;

    printf("����������Ҫ���ɵ�������鳤��");
    scanf("%d", &length);
    printf("����������Ҫ���ԵĴ���");
    scanf("%d", &testTime);

    int *ranArray = malloc(length * 8); // ���䶯̬�����ڴ�
    int *timeArray = malloc(testTime * 8);

    for(int runTime = 0;runTime < testTime;runTime++){
        for(int ELEMENT = 0;ELEMENT < length;ELEMENT++){
            ranArray[ELEMENT] = rand() % 10000;
        }
        // ����ָ�����ȵ��������

        startTime = clock();
        Bubble(ranArray, length);
        targetPosition = Dichotomy(ranArray, length, rand() % 10000);
        endTime = clock();

        timeArray[runTime] = endTime - startTime;
        printf("�� %d �β�����ɣ���ʱ %d ms, Ŀ������λ�ڵ� %d λ", runTime + 1, timeArray[runTime], targetPosition);
    }

    Bubble(timeArray, testTime);
    maxTime = timeArray[testTime - 1];
    minTime = timeArray[0];
    printf("������ɣ����β�������ʱ %d ms, ��С��ʱ %d ms, ƽ����ʱ %d ms", maxTime, minTime, sum(timeArray, testTime) / testTime);

    free(ranArray); // �ͷ������ڴ�
    free(timeArray);
    return 0;
}