#include <stdio.h>

void isPrime(int IN){
    for(int checkNumber = 2;checkNumber < IN;checkNumber++){
        if(IN %  checkNumber == 0){
            return;
        }
    }
    printf("%d ������\n", IN);
}

int main(){
    printf("�����鵽�����ķ�Χ: ");
    int numRange;
    scanf("%d", &numRange);

    for(int check = 2;check <= numRange;check++){ // ��һ����Ƿ�Ϊ����
        isPrime(check);
    }
    getchar();
}
