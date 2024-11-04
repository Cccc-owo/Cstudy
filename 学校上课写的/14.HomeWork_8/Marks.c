// 7.14
#include <stdio.h>
#define S 3 // ѧ����
#define C 5 // �γ���

double sum(int len, double arr[len]){
    double sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}

double powSum(int len, double arr[len]){
    double sum = 0;
    for(int i = 0; i < len; i++)
        sum += arr[i] * arr[i];
    return sum;
}

double classAve(int students, int subjects, int subject, double arr[students][subjects]){
    double sum = 0;
    for(int i = 0; i < students; i++)
        sum += arr[i][subject];
    return sum / students;
}

double scoreAve(int subjects, double arr[subjects]){
    double sum = 0;
    for(int i = 0; i < subjects; i++)
        sum += arr[i];
    return sum / subjects;
}

int main(){
    double marks[S][C], subjAve[C], stuAve[S], highest = 0, var, sums, powSums;
    int stu, subj;
    for(int i = 0; i < S; i++)
        for(int j = 0; j < C; j++)
            scanf("%lf", &marks[i][j]);
    // ��������
    for(int n = 0; n < S; n++){
        stuAve[n] = scoreAve(C, marks[n]);
        printf("��%d��ͬѧ��ƽ����Ϊ%.2lf\n", n + 1, stuAve[n]);
    }
    // ÿλѧ����ƽ����
    for(int n = 0; n < C; n++){
        subjAve[n] = classAve(S, C, n, marks);
        printf("��%d�ſγ̵�ƽ����Ϊ%.2lf\n", n + 1, subjAve[n]);
    }
    // ȫ����߷�
    for(int i = 0; i < S; i++){
        for(int j = 0; j < C; j++){
            if(marks[i][j] > highest){
                highest = marks[i][j];
                stu = i;
                subj = j;
            }
        }
    }
    printf("��߷�Ϊ%.1lf,�ǵ�%d��ѧ���ĵ�%d�ſγ�\n", highest, stu + 1, subj + 1);
    // ��߷ֺͶ�Ӧ��ѧ������Ŀ
    sums = sum(S, stuAve);
    powSums = powSum(S, stuAve);
    var = powSums / S - (sums / S) * (sums / S);
    printf("ѧ�����ֵķ���Ϊ%.3lf\n", var);
    // ���㷽��
    return 0;
}
