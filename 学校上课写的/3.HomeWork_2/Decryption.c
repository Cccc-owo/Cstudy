// ��ʦû�в���Ҫд���ܳ���ģ���û�¸�˳��д��
#include <stdio.h>

void decode(int in){
    if(65 <= in && in < 90)
        in = (in - 4 < 65) ? (in - 4 + 26) : (in - 4); // ��Ԫ���������ʵҲ���Ǹ������if-else Usage:���� ? �����Ļ���ʲô : ��������ʲô
    else if(97 <= in && in < 122)
        in = (in - 4 < 97) ? (in - 4 + 26) : (in - 4);
    putchar(in);
}

int main(){
    int in,sleep;
    printf("������Ҫ���ܵľ���:");
    sleep = getchar();
    printf("������Ϊ:");
    decode(sleep);
    while((in = getchar()) != '\n'){
        decode(in);
    }
    printf("\n");
    return 0;
}