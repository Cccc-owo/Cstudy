//4.9
#include <stdio.h>

int main(){
    int num, mod, backup, i = 0, weight = 1;
    printf("������һ���Ǹ�����:");
    scanf("%d", &num);
    backup = num;
    printf("����Ϊ:");
    do{
        mod = backup % 10;
        backup /= 10;
        i++;
        weight *= 10;
        printf("%d", mod);
    }while(backup >= 1);
    weight /= 10;
    printf("\n����һ��%dλ��", i);
    printf("\n��λ���ֱַ�Ϊ:");
    do{
        printf("%d ", num / weight);
        num -= (num / weight) * weight;
        weight /= 10;
    }while(weight >= 1);
    printf("\n");
    return 0;
}