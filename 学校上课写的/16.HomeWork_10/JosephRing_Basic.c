// 8.5
#include <stdio.h>
#define N 100

void josephRing(int arr[], int people, int num){
    int out = 0, count = 0;
    for(int i = 0; out < people; i++){
        i %= people;
        if(!arr[i])
            count++;
        if(count == num){
            arr[i] = 1;
            printf("%4d", i + 1);
            if(!(++out % 10))
                putchar('\n');
            count = 0;
        }
    }
    if(out % 10)
        putchar('\n');
}

int main(){
    int ring[N] = {0};
    int people, num;
    printf("����������(1-100):");
    scanf("%d", &people);
    printf("�����뱨��(1-10):");
    scanf("%d", &num);
    printf("�뿪��˳��Ϊ:\n");
    josephRing(ring, people, num);
    return 0;
}

