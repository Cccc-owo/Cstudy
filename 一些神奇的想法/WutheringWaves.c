#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 32 // �������������
#define REWARDS 15 // �ܽ�������
#define UP 0 // up������
#define SMALL 10 // С����
#define BIG 80 // �󱣵�
#define MAX_TIME 160 // һ�������鿨�Ĵ���
#define FIVE_STAR 6 // 5�ǵĸ���
#define FOUR_STAR 7 // 4�ǵĸ���
#define TRASH 14 // ����װ��

char REWARD[REWARDS][MAX_LEN] = {"��", "������", "����", "ѩ��", "����", "�ߺ���", "�ƿ���",
                                 "���", "����", "����װ��1", "����װ��2", "����װ��3", "�Შ���ߺ���", "�Შ���ƿ���",
                                 "��������װ��"};

int result[MAX_TIME];

int main(){
    srand(time(NULL));
    int goldenBalls, count_1 = 1, count_2 = 1, check = 0, isBIG = 0;
    double random;
    printf("����Ҫ�鼸��:");
    scanf("%d", &goldenBalls);
    for(int i = 0; i < goldenBalls; i++){
        if(count_2 == BIG && isBIG){
            result[i] = UP;
            count_2 = 1, check = 1, isBIG = 0;
        }else if(count_2 == BIG){
            result[i] = rand() % (FIVE_STAR + 1);
            check = 1, isBIG = 1, count_2 = 1;
        }
        else if(count_1 == SMALL){
            result[i] = FIVE_STAR + 1 + rand() % FOUR_STAR;
            check = 1, count_1 = 1, count_2++;
        }
        // ���׼���
        if(check){
            check = 0;
            continue;
        }
        // ���Ѿ����б��׼��㣬���������ѭ��
        random = rand() % 1000 / 1000.0;
        if(count_2 >= 70)
            random += (count_2 - 69) * 0.001;
        if(random <= 0.932){
            result[i] = TRASH;
            count_1++, count_2++;
        }else if(random <= 0.992){
            result[i] = FIVE_STAR + 1 + rand() % FOUR_STAR;
            count_1 = 1, count_2++;
        }else{
            result[i] = rand() % (FIVE_STAR + 1), count_1++;
            if(result[i] == UP)
                count_2 = 1, isBIG = 0;
            else if(isBIG){
                result[i] = UP;
                count_2++, isBIG = 0;
            }else if(result[i] != UP)
                count_2 = 1, isBIG = 1;
        }
        // ��ͨ�鿨����
    }
    for(int i = 0; i < goldenBalls; i++)
        printf("��%d��: %s\n", i + 1, REWARD[result[i]]);
    printf("\n���г���4�Ǽ����Ͻ����ĳ���Ϊ:\n\n");
    for(int i = 0; i < goldenBalls; i++)
        if(result[i] < FOUR_STAR + FIVE_STAR + 1)
            printf("��%d��: %s\n", i + 1, REWARD[result[i]]);
    printf("\n���г���5�Ǽ����Ͻ����ĳ���Ϊ:\n\n");
    for(int i = 0; i < goldenBalls; i++)
        if(result[i] < FIVE_STAR + 1)
            printf("��%d��: %s\n", i + 1, REWARD[result[i]]);
    return 0;
}