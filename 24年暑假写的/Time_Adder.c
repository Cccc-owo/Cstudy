#include <stdio.h>

int main(){
    int TIME_1, TIME_2, TIME;
    printf("���������ڵ�ʱ��: ");
    scanf("%d", &TIME_1);
    printf("����������ӵ�ʱ��: ");
    scanf("%d", &TIME_2);

    int HOUR_1 = TIME_1 / 100;
    int MIN_1 = TIME_1 - HOUR_1 * 100;
    int HOUR_2 = TIME_2 / 100;
    int MIN_2 = TIME_2 - HOUR_2*100;
    int MIN = MIN_2 + MIN_1;
    int HOUR = HOUR_1 + HOUR_2;

    if(MIN >= 60){
        HOUR = HOUR + MIN / 60;
        MIN = MIN % 60;
        if(HOUR * 100 + MIN > 2400){
            int DAY = HOUR / 24;
            HOUR = HOUR % 24;
            printf("�����ǵ� %d ���� %d �� %d ��", DAY, HOUR, MIN);
            return 0;
        }else{
            printf("������ %d �� %d ��", HOUR, MIN);
            return 0;
        }
    }else{
        if(HOUR * 100 + MIN > 2400){
            int DAY = HOUR / 24;
            HOUR = HOUR % 24;
            printf("�����ǵ� %d ��� %d �� %d ��", DAY, HOUR, MIN);
            return 0;
        }else{
            printf("������ %d �� %d ��", HOUR, MIN);
            return 0;
        }
    }
    return 0;
}