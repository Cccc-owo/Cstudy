#include <stdio.h>
#include <time.h>

int main(){
    long long a = 1,b = 0,c;
    int term, start, end;
    printf("�������뿴��쳲��������еĵڼ���:");
    scanf("%d", &term);
    start = clock();
    for(int i = 1;i <= term;i++){
        printf("F[%d] = %lld\n", i, a);
        c = b;
        b = a;
        a += c;
    }
    end = clock();
    printf("��ʱ: %dms\n", end - start);
    return 0;
}