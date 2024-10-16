#include <stdio.h>
#include <time.h>

long long fibonacci(int n){
    if(n <= 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int term, end, start;
    printf("���뿴��쳲��������еĵڼ���:");
    scanf("%d", &term);
    start = clock();
    for(int i = 1; i <= term;i++)
        printf("F[%d] = %lld\n", i, fibonacci(i));
    end = clock();
    printf("��ʱ: %dms\n", end - start);
}