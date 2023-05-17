#include <stdio.h>
#include <malloc.h>

void insertStudent(unsigned long long **record, int *number);

void checkStudent(unsigned long long **record, int number);

void deleteStudent(unsigned long long **record, int *number);

void visitStudent(unsigned long long **record, int number);

int choose();

int main() {
    unsigned long long **record = (unsigned long long **) malloc(sizeof(unsigned long long *) * 100);
    for (int i = 0; i < 10; ++i)
        record[i] = (unsigned long long *) malloc(sizeof(unsigned long long) * 10);
    int number = 0, choice = choose();
    while (choice != 5) {
        switch (choice) {
            case 1:
                insertStudent(record, &number);
                break;
            case 2:
                deleteStudent(record, &number);
                break;
            case 3:
                checkStudent(record, number);
                break;
            case 4:
                visitStudent(record, number);
                break;
            default:
                printf("����������\n");
        }
        choice = choose();
    }
    printf("�ټ�");
    return 0;
}

void insertStudent(unsigned long long **record, int *number) {
    unsigned long long studentNumber;
    printf("�������ѧ����ѧ�ţ�");
    scanf_s("%llu", &studentNumber);
    int place = 0;
    while (record[place][0] < studentNumber && place < *number)
        place++;
    if (record[place][0] == studentNumber)
        printf("�Ѵ��ڸ���ѧ��\n");
    else {
        if (place != *number) {
            for (int i = *number; i > place; i--) {
                for (int j = 0; j < 6; ++j)
                    record[i][j] = record[i - 1][j];
            }
        }
        record[place][0] = studentNumber;
        printf("�������ѧ���ĳɼ�\n");
        printf("��ѧ��");
        scanf_s("%llu", &record[place][1]);
        printf("Ӣ�");
        scanf_s("%llu", &record[place][2]);
        printf("���磺");
        scanf_s("%llu", &record[place][3]);
        printf("ģ�磺");
        scanf_s("%llu", &record[place][4]);
        printf("�̣߳�");
        scanf_s("%llu", &record[place][5]);
        (*number)++;
    }
}

void checkStudent(unsigned long long **record, int number) {
    if (number == 0)
        printf("��ǰû��ѧ��\n");
    else {
        int place = 0, flag = 0;
        unsigned long long studentNumber;
        printf("��������Ҫ��ѯ��ѧ����ѧ�ţ�");
        scanf_s("%llu", &studentNumber);
        for (int i = 0; i < number; ++i) {
            if (record[place][0] == studentNumber) {
                flag = 1;
                break;
            } else
                place++;
        }
        if (flag) {
            printf("����ѧ��λ�ڵ�%d��\n����ѧ���ĳɼ�Ϊ��\n��ѧ��%llu\nӢ�%llu\n���磺%llu\nģ�磺%llu\n�̣߳�%llu\n",
                   place + 1, record[place][1], record[place][2], record[place][3], record[place][4], record[place][5]);
        } else
            printf("�����ڸ���ѧ��\n");
    }
}

void deleteStudent(unsigned long long **record, int *number) {
    if (*number == 0)
        printf("��ǰû��ѧ��\n");
    else {
        unsigned long long studentNumber;
        int flag = 0;
        printf("��������Ҫɾ����ѧ��ѧ�ţ�");
        scanf_s("%llu", &studentNumber);
        for (int i = 0; i < *number; ++i) {
            if (record[i][0] == studentNumber) {
                for (int j = i; j < *number; ++j)
                    record[j] = record[j + 1];
                flag = 1;
                break;
            }
        }
        if (flag)
            (*number)--;
        else
            printf("�����ڸ�ѧ��\n");
    }
}

void visitStudent(unsigned long long **record, int number) {
    if (number == 0)
        printf("��ǰû��ѧ��\n");
    else {
        printf("����ѧ����ѧ�ţ�\n");
        for (int i = 0; i < number; ++i)
            printf("%d��%llu\n", i + 1, record[i][0]);
    }
}

int choose() {
    int choose;
    printf("��ѡ��������Ҫ�Ĺ���\n1.ѧ����¼����\n2.ѧ����¼ɾ��\n3.����ѧ��\n4.�������ѧ��ѧ��\n5.�˳�\n");
    scanf_s("%d", &choose);
    return choose;
}
