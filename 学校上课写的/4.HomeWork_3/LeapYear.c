// ��ָ���ķ�Χ�ڼ���Ƿ�Ϊ����
#include <stdio.h>

int main(){
    int start, end, count = 0;
    printf("��������ֹ���:");
    scanf("%d,%d", &start, &end);
    printf("%d - %d ��֮���������:\n", start, end);
    for(int year = start;year <= end;year++){
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0){
            printf("%d  ", year);
            count++;
            if (count % 10 == 0) // ÿ���10������ͻ���
                printf("\n");
        }
    }
    printf("\n");
    return 0;
}