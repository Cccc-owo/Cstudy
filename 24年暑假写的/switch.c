#include <stdio.h>

int main(){
    int level;
    scanf("%d", &level);

    switch (level){
    case 100:
        printf("nb");
        break;
    case 80:
        printf("������");
        break;
    case 60:
        printf("ɵ��");
        break;
    case 40:
        printf("ʷ");
        break;
    default:
        printf("�������˸�ʲôʺ?");
        break;
    }

    int a = 58;
    if( a > 50 ) printf("A");
    if( a > 40 ) printf("B");
    if( a > 30 ) printf("C");

    return 0;
}