//дһ������ʹ���ܹ���������ĳɼ���ӡ���ȼ���ͨ������ȼ���ʾ
//����������ĸõȼ��ĳɼ���(�ɼ�ȡ������0-59Ϊ'D��,60-79Ϊ'C����
//80-89Ϊ'B����90-100 Ϊ'A����ÿ���ȼ������ʮ���ɼ�)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char studentMark[161];
    int a = 0, b = 0, c = 0, d = 0, temp, A[10], B[10], C[10], D[10];
    const char WALL[1] = " ";
    printf("���������ѧ���ĳɼ�:");
    fgets(studentMark, 162, stdin);
    // ��ʼ������ ������Ϣ
    temp = atoi(strtok(studentMark, WALL));
    while(temp != NULL){
        if(temp < 60){
            D[d] = temp;
            d++;
        }else if(temp < 80){
            C[c] = temp;
            c++;
        }else if(temp < 90){
            B[b] = temp;
            b++;
        }else if(temp <= 100){
            A[a] = temp;
            a++;
        }
        temp = atoi(strtok(NULL, WALL));
    }
    // ��Ϣ����
    printf("�뿴�ɼ���\nA: ");
    for(int i = 0;i < a;i++){
        printf("%d ", A[i]);
    }
    printf("\nB: ");
    for(int i = 0;i < b;i++){
        printf("%d ", B[i]);
    }
    printf("\nC: ");
    for(int i = 0;i < c;i++){
        printf("%d ", C[i]);
    }
    printf("\nD: ");
    for(int i = 0;i < d;i++){
        printf("%d ", D[i]);
    }
    printf("\n");
    // �������
    return 0;
    // �˳�����
}