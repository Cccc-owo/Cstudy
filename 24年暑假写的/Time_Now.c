#include <stdio.h>

int main(){
    error:
    printf("������4λʱ��:");
    int TIME;
    scanf("%d", &TIME);
    if(TIME > 2400){
        printf("���һ����24��Сʱ����?������!\n");
        goto error;
    }
    int HOUR = TIME/100;
    int MIN = TIME - HOUR*100;
    if(HOUR <= 24 && MIN <=60){
        if(HOUR < 13){
            printf("������:����%d��%d��.", HOUR, MIN);
        }else if(HOUR < 18){
            HOUR -= 12;
            printf("������:����%d��%d��.", HOUR, MIN);
        }else if(HOUR < 23){
            HOUR -= 12;
            printf("������:����%d��%d��.", HOUR, MIN);
        }else{
            HOUR -= 12;
            printf("������:��ҹ%d��%d��.", HOUR, MIN);
        }
    }else{
        printf("�������˸�ʲô����?������!\n");
        goto error;
    }
}
