#include <stdio.h>

int main(){
    int amount = 0;
    for(int a = 1; a <= 9; a++){
        for(int b = 1; b <= 9; b++){
            for(int c = 1; c <= 9; c++){
                if(a != b & b != c & c != a){
                    printf("\n%d%d%d", a, b, c);
                    amount++;
                }
            }
        }
    }
    printf("\nһ����%d������", amount);
    return 0;
}