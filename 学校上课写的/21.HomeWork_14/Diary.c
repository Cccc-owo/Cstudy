// 10.12
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEN 256 // ��������С

// ���ֳ����Լ�������
const char *DIARY_FILE = ".\\D\\diary\\today.txt";

const char *BACKUP_FILE = ".\\E\\backup\\backup.dat";

const char *HISTORY_FILE = ".\\D\\diary\\history.txt";

const char *weather[] = {"����", "��", "��", "ѩ", "�±���", "�˷���", "٤�����߱�"};

const char *context[] = {
        "������ȥ�������е����ˣ���·�ϼ�10��Ǯ��������\n���ǿ�ϧ���ǣ��Ҳ�С�ĵ�ˮ�����������ӡ�\n",
        "��������ģ�ʲô���⣬�ͷ�����٣���ô��������ô����ҵ������ү�ˡ�\n��ȥ����Ϸ�������ˡ�\n",
        "�����ٺٺ٣�������������δ���ˣ������������ˡ��������ҡ�\n��˵�������ϳ�ʲô��\n",
        "��������������ã���ȥɢ����ʱ��������һֻ�ɰ���С����\n��ϧ���ܵ�̫�죬û���ü���������\n",
        "�������쿼�Կ����ˣ������е���䡣\n����û��ϵ���´���Ŭ���ɣ�\n",
        "����������ͼ��ݿ��飬ͻȻ������һ��������Ȥ���顣\nһ�������˺ü���Сʱ����ȫͣ��������\n",
        "�������������һ��ȥ���˻����������ֱð����\n����ζ�����̫���ˣ��´λ�Ҫ������\n",
        "���������ڹ�������������һ�������̣���������������\n��Ц�Ŷ���˵лл���о��Լ����˼����¡�\n",
        "���������յ���һ�������������ĵò����ˡ�\nԭ���������տ쵽�ˣ�������ǰ׼���ľ�ϲ��\n",
        "��������ȥ��ɽ����Ȼ���ۣ����羰��ĺ�����\nվ��ɽ���ĸо�����ֱ̫���ˣ�\n"
};


char buffer[MAX_LEN];

// д�ռǺ���
void diary(FILE *fp){
    int temp1 = rand() % 7, temp2 = rand() % 10;
    fprintf(fp, "����: %s  ����: %s\n", __DATE__, *(weather + temp1));
    fputs(*(context + temp2), fp);
    fputc('\n', fp);
    rewind(fp);
}

// �ļ����ƺ���
int fileCopy(FILE *from, FILE *to){
    char ch;
    if(from == NULL || to == NULL)
        return EXIT_FAILURE;
    while((ch = fgetc(from)) != EOF)
        fwrite(&ch, sizeof(char), 1, to);
    fclose(from);
    fclose(to);
    return EXIT_SUCCESS;
}

// �ı����뺯��
int fileInsert(FILE *from, FILE *to){
    char ch;
    if(from == NULL || to == NULL)
        return EXIT_FAILURE;
    while((ch = fgetc(from)) != EOF)
        fputc(ch, to);
    fclose(from);
    fclose(to);
    return EXIT_SUCCESS;
}

int main(){
    srand(time(NULL));
    printf("���ڴ��ռ�...\n");
    FILE *fp = fopen(DIARY_FILE, "w+");
    if(fp == NULL){
        perror("�ռ��ļ��޷�������");
        exit(EXIT_FAILURE);
    }else
        printf("����д�ռ�...\n\n");
    diary(fp);
    while(fgets(buffer, MAX_LEN, fp) != NULL)
        printf("%s", buffer);
    fclose(fp);
    // д�ռǲ����������

    printf("����ɾ��backup.dat�ļ�...\n");
    if(!remove(BACKUP_FILE))
        printf("ɾ���ɹ�!\n");
    else{
        perror("ɾ��ʧ��");
        exit(EXIT_FAILURE);
    }
    // ɾ��backup.dat�ļ�

    printf("���ڽ�history.txt�е����ݸ��Ƶ�backup.dat��\n");
    FILE *from, *to;
    from = fopen(HISTORY_FILE, "r");
    to = fopen(BACKUP_FILE, "w+");
    if(!fileCopy(from, to))
        printf("���Ƴɹ�!\n");
    else{
        perror("����ʧ��");
        exit(EXIT_FAILURE);
    }
    // ��history.txt�е����ݸ��Ƶ�backup.dat

    FILE *source, *insert;
    printf("���ڽ�today.txt�е����ݲ��뵽history.txt��...\n");
    source = fopen(DIARY_FILE, "r");
    insert = fopen(HISTORY_FILE, "a+");
    if(!fileInsert(source, insert))
        printf("����ɹ�!\n");
    else{
        perror("����ʧ��");
        exit(EXIT_FAILURE);
    }
    // ��today.txt�е����ݲ��뵽history.txt��

    return EXIT_SUCCESS;
}