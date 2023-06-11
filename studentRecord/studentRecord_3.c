#include <stdio.h>
#include <malloc.h>

struct student {
    long long number;
    int chinese;
    int math;
    int english;
    int physics;
    int chemistry;
};

void sample(struct student **class);

int inputData(struct student **class, int length);

void outputData(struct student **class, int length);

void averageSort(struct student **class, int length);

void search(struct student **class, int length);

void fail(struct student **class, int length);

void printMenu();

int main() {
    struct student **class = (struct student **) malloc(sizeof(struct student *) * 50);
    for (int i = 0; i < 50; ++i)
        class[i] = (struct student *) malloc(sizeof(struct student));
    sample(class);

    return 0;
}

void sample(struct student **class) {
    int choice, length = 0;
    printMenu();
    scanf_s("%d", &choice);
    while (choice != 6) {
        switch (choice) {
            case 1:
                length += inputData(class, length);
                break;
            case 2:
                outputData(class, length);
                break;
            case 3:
                averageSort(class, length);
                break;
            case 4:
                search(class, length);
                break;
            case 5:
                fail(class, length);
                break;
            default:
                printf("�����������������\n");
        }
        printf("\n");
        printMenu();
        scanf_s("%d", &choice);
    }
    printf("�ټ�\n");
}

int inputData(struct student **class, int length) {
    if (length == 50) {
        printf("��������\n");
        return 0;
    }
    int re = 1;
    struct student *student = class[length];
    long long num;
    printf("ѧ��:");
    scanf_s("%lld", &num);
    for (int i = 0; i < length; ++i)
        if (class[i]->number == num) {
            printf("�Ѵ��ڸ�ѧ��\n�Ƿ񸲸Ǹ�ѧ���ĳɼ�:\n1.��     2.��\n");
            int choice;
            scanf_s("%d", &choice);
            while (choice != 1 && choice != 2) {
                printf("�����������������\n");
                printf("�Ƿ񸲸Ǹ�ѧ���ĳɼ�:\n1.��     2.��\n");
                scanf_s("%d", &choice);
            }
            if (choice == 1) {
                student = class[i];
                re = 0;
            } else
                return 0;
        }
    student->number = num;
    printf("����:");
    scanf_s("%d", &student->chinese);
    printf("��ѧ:");
    scanf_s("%d", &student->math);
    printf("Ӣ��:");
    scanf_s("%d", &student->english);
    printf("����:");
    scanf_s("%d", &student->physics);
    printf("��ѧ:");
    scanf_s("%d", &student->chemistry);
    return re;
}

void outputData(struct student **class, int length) {
    if (length == 0) {
        printf("��ǰû������\n");
        return;
    }
    long long num;
    printf("������ѧ��:");
    scanf_s("%lld", &num);
    struct student *student;
    int flag = 0;
    for (int i = 0; i < length; ++i)
        if (class[i]->number == num) {
            student = class[i];
            flag = 1;
        }
    if (flag == 1) {
        printf("ѧ��:%lld\n", student->number);
        printf("����:%d\n", student->chinese);
        printf("��ѧ:%d\n", student->math);
        printf("Ӣ��:%d\n", student->english);
        printf("����:%d\n", student->physics);
        printf("��ѧ:%d\n", student->chemistry);
    } else
        printf("û�и���ѧ��\n");
}

void averageSort(struct student **class, int length) {
    float average[50] = {0};
    printf("ѧ��         ƽ���ɼ�\n");
    for (int i = 0; i < length; ++i) {
        struct student *student = class[i];
        float aver = (float) (student->chinese + student->math + student->english + student->physics +
                              student->chemistry) / 5;
        average[i] = aver;
        printf("%10lld%10.2f\n", class[i]->number, aver);
    }
    for (int i = 0; i < 50; ++i)
        for (int j = i + 1; j < 50; ++j)
            if (average[i] < average[j]) {
                float t = average[i];
                average[i] = average[j];
                average[j] = t;
                struct student *temp = class[i];
                class[i] = class[j];
                class[j] = temp;
            }
}

void search(struct student **class, int length) {
    printf("       ƽ���ɼ�    ��߳ɼ�    ��ͳɼ�    ����������    ������\n");
    int max = -1, min = 10000, fail = 0, average = 0;
    if (length == 0) {
        printf("��ǰû��ѧ������\n");
        return;
    }
    for (int i = 0; i < length; ++i) {
        int mark = class[i]->chinese;
        average += mark;
        if (mark > max)
            max = mark;
        if (mark < min)
            min = mark;
        if (mark < 60)
            fail += 1;
    }
    printf("����%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
    max = -1, min = 10000, fail = 0, average = 0;
    for (int i = 0; i < length; ++i) {
        int mark = class[i]->math;
        average += mark;
        if (mark > max)
            max = mark;
        if (mark < min)
            min = mark;
        if (mark < 60)
            fail += 1;
    }
    printf("��ѧ%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
    max = -1, min = 10000, fail = 0, average = 0;
    for (int i = 0; i < length; ++i) {
        int mark = class[i]->english;
        average += mark;
        if (mark > max)
            max = mark;
        if (mark < min)
            min = mark;
        if (mark < 60)
            fail += 1;
    }
    printf("Ӣ��%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
    max = -1, min = 10000, fail = 0, average = 0;
    for (int i = 0; i < length; ++i) {
        int mark = class[i]->physics;
        average += mark;
        if (mark > max)
            max = mark;
        if (mark < min)
            min = mark;
        if (mark < 60)
            fail += 1;
    }
    printf("����%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
    max = -1, min = 10000, fail = 0, average = 0;
    for (int i = 0; i < length; ++i) {
        int mark = class[i]->chemistry;
        average += mark;
        if (mark > max)
            max = mark;
        if (mark < min)
            min = mark;
        if (mark < 60)
            fail += 1;
    }
    printf("��ѧ%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
}

void fail(struct student **class, int length) {
    if (length == 0) {
        printf("��ǰû������\n");
        return;
    }
    for (int i = 0; i < length; ++i) {
        struct student *student = class[i];
        if (student->chinese < 60 || student->math < 60 || student->english < 60 || student->physics < 60 ||
            student->chemistry < 60) {
            int tot = 0;
            printf("ѧ��:%lld", student->number);
            if (student->chinese < 60) {
                printf("   ����:%d", student->chinese);
                tot += 1;
            }
            if (student->math < 60) {
                printf("   ��ѧ:%d", student->math);
                tot += 1;
            }
            if (student->english < 60) {
                printf("   Ӣ��:%d", student->english);
                tot += 1;
            }
            if (student->physics < 60) {
                printf("   ����:%d", student->physics);
                tot += 1;
            }
            if (student->chemistry < 60) {
                printf("   ��ѧ:%d\n", student->chemistry);
                tot += 1;
            }
            printf("����%d�ſ�Ŀ������\n", tot);
        }
    }
}

void printMenu() {
    printf("���������ѡ��:\n1.����ѧ������\n2.���ѧ������\n3.�������ÿ��ѧ����ƽ���ɼ���������ƽ���ɼ�����\n4.�������ÿһ����Ŀ��ƽ���ɼ�����߳ɼ�����ͳɼ���������������������\n5.���������������Ա�б��������Ŵ������͸��������Ŀ����\n6.�˳�\n");
}
