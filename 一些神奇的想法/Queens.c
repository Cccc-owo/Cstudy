#include <stdio.h>
#define QUEEN 4

int solutions;
int placed[QUEEN][QUEEN];
int placedX[QUEEN];
int placedDiagLeft[QUEEN * 2];
int placedDiagRight[QUEEN * 2];

void print(){ // ���
    solutions++;
    for(int i = 0; i < QUEEN; i++){
        for(int j = 0; j < QUEEN; j++)
            printf("%3d", placed[i][j]);
        printf("\n");
    }
    printf("\n");
}

void NQueen(int queen){
    if(queen == QUEEN){ // ˵�������ˣ����������
        print();
        return;
    }
    for(int x = 0; x < QUEEN; x++){
        if(!placedX[x] && !placedDiagLeft[queen - x + QUEEN] && !placedDiagRight[queen + x]){ // ����ֱ����˵y - kx = C����y - kx������Ϊ�Խ��ߵı�ǣ�ͬʱqueen - x�ټ�queen��Ϊ��������С��0
            placed[queen][x] = 1; // ����к������Խ���
            placedX[x] = 1;
            placedDiagRight[queen + x] = 1;
            placedDiagLeft[queen - x + QUEEN] = 1;
            NQueen(queen + 1); // �ʺ������ɣ�����һ��
            placed[queen][x] = 0; // ����
            placedX[x] = 0;
            placedDiagRight[queen + x] = 0;
            placedDiagLeft[queen - x + QUEEN] = 0;
        }
    }
}

int main(){
    NQueen(0);
    printf("һ����%d�ֽⷨ\n", solutions);
    return 0;
}