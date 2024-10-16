// ����һ���ĸ����������㷨���
#include <stdio.h>
#include <time.h>
#include <math.h>

int isPrime1(int n){ // 1.�������
    if(n < 2)
        return 0;
    for(int i = 2;i < n;i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int isPrime2(int n){ // 2.�����ҵ�Ŀ�����Ŀ���
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
    else
        for(int i = 2;i < sqrt(n) + 1;i++)
            if(n % i == 0)
                return 0;
    return 1;
}

int isPrime3(int n){ // 3.����2�����������Ϊ���������Խ����ż����ͬ�������ҵ�Ŀ�����Ŀ�����Ŀǰ��õķ���
    if(n == 2)
        return 1;
    else if(n < 2 || n % 2 == 0)
        return 0;
    else
        for(int i = 3;i < sqrt(n) + 1;i += 2)
            if(n % i == 0)
                return 0;
    return 1;
}

int main(){
    int start, end, term = 1000000, count = 0;
    start = clock();
    for(int i = 1;i <= term;i++){ // ����㷨��ĺ��ã����鲻Ҫ����
        if(isPrime1(i) == 1){
            count++;
        }
    }
    printf("һ����%d������\n", count);
    end = clock();
    count = 0;
    printf("��ʱ:%dms\n", end - start);
    start = clock();
    for(int i = 1;i <= term;i++){
        if(isPrime2(i) == 1){
            count++;
        }
    }
    printf("һ����%d������\n", count);
    end = clock();
    count = 0;
    printf("��ʱ:%dms\n", end - start);
    start = clock();
    for(int i = 1;i <= term;i++){
        if(isPrime3(i) == 1){
            count++;
        }
    }
    printf("һ����%d������\n", count);
    end = clock();
    printf("��ʱ:%dms\n", end - start);
}