//�����ǵĳ���
#include <stdio.h>
#define PI 3.1415926

int main(){
    double radius, height;
    printf("������뾶�͸�:");
    scanf("%lf,%lf",&radius, &height);

    printf("Բ���ܳ���: %.2lf\n", radius * 2 * PI);
    printf("Բ�������: %.2lf\n", radius * radius * PI);
    printf("��ı����: %.2lf\n", radius * 4 * PI);
    printf("������: %.2lf\n", 4.0 * (radius *radius * radius) * PI / 3);
    printf("Բ�������: %.2lf\n", radius * 2 * PI * height);
}