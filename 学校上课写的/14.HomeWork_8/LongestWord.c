// 7.10
#include <stdio.h>
#include <string.h>

int main(){
    char str[64], longest[64] = "";
    int len = 0;
    printf("�������ַ�����:");
    do{
        scanf("%s", str);
        if(strlen(str) > len){
            strcpy(longest, str);
            len = strlen(str);
        }
    }while(getchar() != '\n');
    printf("�����Ϊ:%s\n", longest);
    return 0;
}
