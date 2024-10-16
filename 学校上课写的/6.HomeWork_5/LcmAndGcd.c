//5.3
#include <stdio.h>

void swap(int m, int n){ // �Ի���������֤gcd������������һ����ǰ������С
    if(m < n){
        int temp = m;
        m = n;
        n = temp;
    }
}

int gcd(int m, int n){ // �������
    int mod;
    swap(m, n);
    if(n == 0)
        return m;
    do{
        mod = m % n;
        if(mod == 0){
            return n;
        }else{
            m = n;
            n = mod;
        }
    }while(1);
}

int lcm(int m, int n){ // ��С������
    if(m == 0 || n== 0)
        return 0;
    else
        return m * n / gcd(m, n);
}

int main(){
    int a, b;
    printf("�����������Ǹ�����:");
    scanf("%d,%d", &a, &b);
    printf("���Լ��Ϊ%d\n", gcd(a, b));
    printf("��С������Ϊ%d\n", lcm(a, b));
    return 0;
}
