#include <stdio.h>

int main(){
    int foot,inch;
    printf("�������㼸��:");
    scanf("%d", &foot);
    printf("�������㼸��:");
    scanf("%d", &inch);
    float height = (foot + inch/12.0)*0.3048;
    printf("��������:%f cm", height);
}