// 6.16
#include <stdio.h>
#include <string.h>

int strPos(char str1[], char str2[]){
    int i, j;
    for(i = 0; i < strlen(str1) - strlen(str2); i++){
        for(j = 0; j < strlen(str2); j++){
            if(str1[i + j] != str2[j])
                break;
        }
        if(j == strlen(str2))
            return i;
    }
    return -1;
}

int main(){
    char mainStr[] = "ababbab", str[8];
    int pos;
    printf("����Ϊ:ababbab\n�����ִ�:");
    scanf("%s", str);
    pos = strPos(mainStr, str);
    if(pos >= 0)
        printf("ƥ��λ��Ϊ: %d", pos);
    else
        printf("ƥ��ʧ��!");
    return 0;
}
