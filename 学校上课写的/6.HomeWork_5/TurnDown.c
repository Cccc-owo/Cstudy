//4.9
#include <stdio.h>

int main(){
    long long num, mod, backup, i = 0, weight = 1;
    printf("������һ���Ǹ�����:");
    scanf("%llu", &num);
    backup = num;
    printf("����Ϊ:");
    do{
        mod = backup % 10;
        backup /= 10;
        i++;
        weight *= 10;
        printf("%llu", mod);
    }while(backup >= 1);
    weight /= 10;
    printf("\n����һ��%dλ��", i);
    printf("\n��λ���ֱַ�Ϊ:");
    do{
        printf("%llu ", num / weight);
        num -= (num / weight) * weight;
        weight /= 10;
    }while(weight >= 1);
    printf("\n");
    return 0;
}