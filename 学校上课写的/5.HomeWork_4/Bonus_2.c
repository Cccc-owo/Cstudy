#include <stdio.h>

int main(){
    double I = 0, bonus;
    int a = 10;
    printf("����(Ԫ):");
    scanf("%lf", &bonus);
    bonus / 1e5 <= 10 ? a = bonus / 1e5: a;

    switch(a){
        case 10: // switch����,10-0��Ҫд������ᵼ���쳣!
            I += (bonus - 1e6) * 0.01;
            bonus = 1e6;
        case 9:
        case 8:
        case 7:
        case 6:
            I += (bonus - 6e5) * 0.015;
            bonus = 6e5;
        case 5:
        case 4:
            I += (bonus - 4e5) * 0.03;
            bonus = 4e5;
        case 3:
        case 2:
            I += (bonus - 2e5) * 0.05;
            bonus = 2e5;
        case 1:
            I += (bonus - 1e5) * 0.075;
            bonus = 1e5;
        case 0:
            I += bonus * 0.1;
    }

    printf("����:%.2lf\n", I);
    return 0;
}