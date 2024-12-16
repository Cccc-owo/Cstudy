// 10.13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 1000

const char *DATAFILE = "vote.dat";

struct vote {
    char voterName[20];
    int goodsID;
    float point;
};

struct vote voter[M];
struct vote buffer;

struct count {
    float sum;
    int n;
} goods[N];

void dataIn(){
    int id, count = 0;
    char name[20];
    while(1){
        printf("ͶƱ������:");
        scanf("%s", name);
        if(!strcmp(name, "exit")){
            break;
        }
        while(1){
            printf("\n��Ʒ���:");
            scanf("%d", &id);
            if(!id)
                break;
            else if(id > N || id < 0){
                printf("��������!����������!\n");
                continue;
            }
            strcpy(voter[count].voterName, name);
            voter[count].goodsID = id;
            while(1){
                printf("����:");
                scanf("%f", &voter[count].point);
                if(voter[count].point >= 0 && voter[count].point <= 10)
                    break;
                else
                    printf("��������!���������(0 ~ 10)\n");
            }
            count++;
        }
    }
    putchar('\n');
    // ��������

    FILE *fp = fopen(DATAFILE, "a+b");
    if(fp == NULL){
        perror("�޷��������ļ�!");
        exit(EXIT_FAILURE);
    }
    fwrite(voter, sizeof(struct vote), count, fp);
    fclose(fp);
    // ����¼��
}

void dataOut(){
    FILE *fp = fopen(DATAFILE, "r+b");
    if(fp == NULL){
        perror("�޷��������ļ�!");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while(fread(&buffer, sizeof(struct vote), 1, fp))
        voter[count++] = buffer;
    for(int i = 0; i < count; i++)
        printf("%-12s %-6d    %-6.1f\n", voter[i].voterName, voter[i].goodsID, voter[i].point);
    for(int i = 0; i < count; i++){
        goods[voter[i].goodsID - 1].n++;
        goods[voter[i].goodsID - 1].sum += voter[i].point;
    }
    putchar('\n');
}

void printAll(){
    printf("****��Ʒ������Ϣһ����****\n");
    for(int i = 0; i < N; i++)
        if(goods[i].n)
            printf("%2d.       %-4d    %.2f\n", i + 1, goods[i].n, goods[i].sum / goods[i].n);
    putchar('\n');
}

void process(){
    float max = -1, ave;
    int id;
    for(int i = 0; i < N; i++)
        if(goods[i].n >= 2 && (ave = goods[i].sum / goods[i].n) > max)
            max = ave, id = i;
    printf("���ܻ�ӭ����Ʒ��Ϣ(��������������2��):\n%2d       %-4d    %.2f\n", id + 1, goods[id].n, max);
}

int main(){
    dataIn();
    dataOut();
    printAll();
    process();
    return 0;
}