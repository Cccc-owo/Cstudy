#include <stdio.h>

void encode(int input){
    if (65 <= input && input <= 90)
        input = (input - 61) % 26 + 65; // ���ǱȽ����Ƶ��㷨�ˣ��ҿɲ���������дһ���if-else���ж��������
    else if (97 <= input && input <= 122)
        input = (input - 93) % 26 + 97;
    putchar(input);
}

int main(){
    int in, sleep;
    printf("������Ҫ���ܵľ���:");
    sleep = getchar();
    printf("������Ϊ:");
    encode(sleep);
    while((in = getchar()) != '\n')
        encode(in);
    printf("\n");
    return 0;
}