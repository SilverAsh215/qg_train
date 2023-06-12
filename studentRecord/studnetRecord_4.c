#include <stdio.h>
#include <malloc.h>

struct student {
    long long number;
    int mark[5];
    struct student *pre;
    struct student *next;
};

void sample(struct student *class);

void insertStudent(struct student *class);

void searchStudent(struct student *class);

void deleteStudent(struct student *class);

void averageStudent(struct student *class);

void countStudent(struct student *class);

void failStudent(struct student *class);

int choose();

int main() {
    struct student *head = (struct student *) malloc(sizeof(struct student));
    head->number = -100;
    head->pre = NULL;
    head->next = NULL;
    sample(head);
    return 0;
}

void sample(struct student *class) {
    int choice = choose();
    while (choice != 7) {
        switch (choice) {
            case 1:
                insertStudent(class);
                break;
            case 2:
                searchStudent(class);
                break;
            case 3:
                deleteStudent(class);
                break;
            case 4:
                averageStudent(class);
                break;
            case 5:
                countStudent(class);
                break;
            case 6:
                failStudent(class);
                break;
            default:
                printf("�������\n");
        }
        printf("\n");
        choice = choose();
    }
    printf("�ټ�");
}

void insertStudent(struct student *class) {
    struct student *student = (struct student *) malloc(sizeof(struct student));
    printf("����������:\n");
    printf("ѧ��:");
    scanf_s("%lld", &student->number);
    printf("����:");
    scanf_s("%d", &student->mark[0]);
    printf("��ѧ:");
    scanf_s("%d", &student->mark[1]);
    printf("Ӣ��:");
    scanf_s("%d", &student->mark[2]);
    printf("����:");
    scanf_s("%d", &student->mark[3]);
    printf("��ѧ:");
    scanf_s("%d", &student->mark[4]);
    struct student *current = class;
    int flag = 0;
    while (current->next) {
        if (student->number <= current->number)
            break;
        current = current->next;
    }
    if (student->number == current->number)
        flag = 1;
    else if (student->number <= current->number)
        current = current->pre;
    if (flag == 1) {
        printf("�Ѵ��ڸ�ѧ��,�Ƿ񸲸�ԭ������\n1.��    2.��\n");
        int choice;
        scanf_s("%d", &choice);
        while (choice != 1 && choice != 2) {
            printf("\n�����������������\n");
            scanf_s("%d", &choice);
        }
        if (choice == 1)
            for (int i = 0; i < 5; ++i)
                current->mark[i] = student->mark[i];
    } else {
        student->pre = current;
        student->next = current->next;
        if (current->next)
            current->next->pre = student;
        current->next = student;
    }
}

void searchStudent(struct student *class) {
    long long number;
    printf("������ѧ��:");
    scanf_s("%lld", &number);
    struct student *current = class;
    int flag = 0;
    while (current) {
        if (current->number == number) {
            flag = 1;
            printf("ѧ��:%lld\n", current->number);
            printf("����:%d\n", current->mark[0]);
            printf("��ѧ:%d\n", current->mark[1]);
            printf("Ӣ��:%d\n", current->mark[2]);
            printf("����:%d\n", current->mark[3]);
            printf("��ѧ:%d\n", current->mark[4]);
            break;
        }
        current = current->next;
    }
    if (flag == 0)
        printf("û�и�ѧ��\n");
}

void deleteStudent(struct student *class) {
    long long number;
    printf("������ѧ��:");
    scanf_s("%lld", &number);
    struct student *current = class;
    int flag = 0;
    while (current) {
        if (current->number == number) {
            current->pre->next = current->next;
            if (current->next)
                current->next->pre = current->pre;
            free(current);
            flag = 1;
            break;
        }
        current = current->next;
    }
    if (flag == 0)
        printf("û�и�ѧ��\n");
}

void averageStudent(struct student *class) {
    struct student *current = class;
    long double average[100][2];
    int local = 0;
    while (current->next) {
        current = current->next;
        average[local][0] = current->number;
        average[local][1] = 0;
        for (int i = 0; i < 5; ++i)
            average[local][1] += current->mark[i];
        average[local][1] /= 5;
        local++;
    }
    for (int i = 0; i < local; ++i) {
        for (int j = i + 1; j < local; ++j) {
            if (average[i][1] < average[j][1]) {
                long double a, b;
                a = average[i][0];
                b = average[i][1];
                average[i][0] = average[j][0];
                average[i][1] = average[j][1];
                average[j][0] = a;
                average[j][1] = b;
            }
        }
    }
    printf("�ɼ�:\n");
    for (int i = 0; i < local; ++i)
        printf("ѧ��:%.Lf   ƽ���ɼ�:%.1Lf\n", average[i][0], average[i][1]);
}

void countStudent(struct student *class) {
    printf("����Ŀ����:\n");
    float average = 0, fail = 0, tot = 0;
    int max = -1, min = 1000000000;
    struct student *current = class;
    while (current->next) {
        tot += 1;
        current = current->next;
        average += (float) current->mark[0];
        if (current->mark[0] > max)
            max = current->mark[0];
        if (current->mark[0] < min)
            min = current->mark[0];
        if (current->mark[0] < 60)
            fail++;
    }
    average /= tot;
    printf("����:   ƽ���ɼ�:%.2f   ��߳ɼ�:%d   ��ͳɼ�:%d   ����������:%.f   ������:%.2f%%\n", average, max, min,
           fail, (tot - fail) / tot * 100);
    average = 0, fail = 0, max = -1, min = 1000000000;
    current = class;
    while (current->next) {
        current = current->next;
        average += (float) current->mark[1];
        if (current->mark[1] > max)
            max = current->mark[1];
        if (current->mark[1] < min)
            min = current->mark[1];
        if (current->mark[1] < 60)
            fail++;
    }
    average /= tot;
    printf("��ѧ:   ƽ���ɼ�:%.2f   ��߳ɼ�:%d   ��ͳɼ�:%d   ����������:%.f   ������:%.2f%%\n", average, max, min,
           fail, (tot - fail) / tot * 100);
    average = 0, fail = 0, max = -1, min = 1000000000;
    current = class;
    while (current->next) {
        current = current->next;
        average += (float) current->mark[2];
        if (current->mark[2] > max)
            max = current->mark[2];
        if (current->mark[2] < min)
            min = current->mark[2];
        if (current->mark[2] < 60)
            fail++;
    }
    average /= tot;
    printf("Ӣ��:   ƽ���ɼ�:%.2f   ��߳ɼ�:%d   ��ͳɼ�:%d   ����������:%.f   ������:%.2f%%\n", average, max, min,
           fail, (tot - fail) / tot * 100);
    average = 0, fail = 0, max = -1, min = 1000000000;
    current = class;
    while (current->next) {
        current = current->next;
        average += (float) current->mark[3];
        if (current->mark[3] > max)
            max = current->mark[3];
        if (current->mark[3] < min)
            min = current->mark[3];
        if (current->mark[3] < 60)
            fail++;
    }
    average /= tot;
    printf("����:   ƽ���ɼ�:%.2f   ��߳ɼ�:%d   ��ͳɼ�:%d   ����������:%.f   ������:%.2f%%\n", average, max, min,
           fail, (tot - fail) / tot * 100);
    average = 0, fail = 0, max = -1, min = 1000000000;
    current = class;
    while (current->next) {
        current = current->next;
        average += (float) current->mark[4];
        if (current->mark[4] > max)
            max = current->mark[4];
        if (current->mark[4] < min)
            min = current->mark[4];
        if (current->mark[4] < 60)
            fail++;
    }
    average /= tot;
    printf("��ѧ:   ƽ���ɼ�:%.2f   ��߳ɼ�:%d   ��ͳɼ�:%d   ����������:%.f   ������:%.2f%%\n", average, max, min,
           fail, (tot - fail) / tot * 100);
}

void failStudent(struct student *class) {
    printf("����������:\n");
    struct student *current = class;
    while (current->next) {
        current = current->next;
        int flag = 0;
        for (int i = 0; i < 5; ++i)
            if (current->mark[i] < 60) {
                flag = 1;
                break;
            }
        if (flag == 1) {
            printf("ѧ��:%lld   ", current->number);
            int tot = 0;
            if (current->mark[0] < 60) {
                printf("����:%d   ", current->mark[0]);
                tot++;
            }
            if (current->mark[1] < 60) {
                printf("��ѧ:%d   ", current->mark[1]);
                tot++;
            }
            if (current->mark[2] < 60) {
                printf("Ӣ��:%d   ", current->mark[2]);
                tot++;
            }
            if (current->mark[3] < 60) {
                printf("����:%d   ", current->mark[3]);
                tot++;
            }
            if (current->mark[4] < 60) {
                printf("��ѧ:%d   ", current->mark[4]);
                tot++;
            }
            printf("����%d�ſ�Ŀ������\n", tot);
        }
    }
}

int choose() {
    int choice;
    printf("���������ѡ��:\n"
           "1:����ѧ������\n"
           "2:����ѧ������\n"
           "3:ɾ��ѧ������\n"
           "4:����ÿ��ѧ����ƽ���ɼ���������ƽ���ɼ�����\n"
           "5:����ÿһ����Ŀ��ƽ���ɼ�����߳ɼ�����ͳɼ���������������������\n"
           "6:���㲻������Ա�б��������Ŵ������͸��������Ŀ����\n"
           "7:�˳�\n");
    scanf_s("%d", &choice);
    while (choice < 1 || choice > 7) {
        printf("\n�����������������\n"
               "���������ѡ��:\n"
               "1:����ѧ������\n"
               "2:����ѧ������\n"
               "3:ɾ��ѧ������\n"
               "4:����ÿ��ѧ����ƽ���ɼ���������ƽ���ɼ�����\n"
               "5:����ÿһ����Ŀ��ƽ���ɼ�����߳ɼ�����ͳɼ���������������������\n"
               "6:���㲻������Ա�б��������Ŵ������͸��������Ŀ����\n"
               "7:�˳�\n");
        scanf_s("%d", &choice);
    }
    return choice;
}
