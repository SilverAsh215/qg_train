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
                printf("输入错误，请重新输入\n");
        }
        printf("\n");
        printMenu();
        scanf_s("%d", &choice);
    }
    printf("再见\n");
}

int inputData(struct student **class, int length) {
    if (length == 50) {
        printf("人数已满\n");
        return 0;
    }
    int re = 1;
    struct student *student = class[length];
    long long num;
    printf("学号:");
    scanf_s("%lld", &num);
    for (int i = 0; i < length; ++i)
        if (class[i]->number == num) {
            printf("已存在该学生\n是否覆盖该学生的成绩:\n1.是     2.否\n");
            int choice;
            scanf_s("%d", &choice);
            while (choice != 1 && choice != 2) {
                printf("输入错误，请重新输入\n");
                printf("是否覆盖该学生的成绩:\n1.是     2.否\n");
                scanf_s("%d", &choice);
            }
            if (choice == 1) {
                student = class[i];
                re = 0;
            } else
                return 0;
        }
    student->number = num;
    printf("语文:");
    scanf_s("%d", &student->chinese);
    printf("数学:");
    scanf_s("%d", &student->math);
    printf("英语:");
    scanf_s("%d", &student->english);
    printf("物理:");
    scanf_s("%d", &student->physics);
    printf("化学:");
    scanf_s("%d", &student->chemistry);
    return re;
}

void outputData(struct student **class, int length) {
    if (length == 0) {
        printf("当前没有数据\n");
        return;
    }
    long long num;
    printf("请输入学号:");
    scanf_s("%lld", &num);
    struct student *student;
    int flag = 0;
    for (int i = 0; i < length; ++i)
        if (class[i]->number == num) {
            student = class[i];
            flag = 1;
        }
    if (flag == 1) {
        printf("学号:%lld\n", student->number);
        printf("语文:%d\n", student->chinese);
        printf("数学:%d\n", student->math);
        printf("英语:%d\n", student->english);
        printf("物理:%d\n", student->physics);
        printf("化学:%d\n", student->chemistry);
    } else
        printf("没有该名学生\n");
}

void averageSort(struct student **class, int length) {
    float average[50] = {0};
    printf("学号         平均成绩\n");
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
    printf("       平均成绩    最高成绩    最低成绩    不及格人数    及格率\n");
    int max = -1, min = 10000, fail = 0, average = 0;
    if (length == 0) {
        printf("当前没有学生数据\n");
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
    printf("语文%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
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
    printf("数学%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
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
    printf("英语%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
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
    printf("物理%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
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
    printf("化学%10.2f%10d%12d%12d%15.2f%%\n", (float) average / (float) length, max, min, fail,
           (float) (length - fail) / (float) length * 100);
}

void fail(struct student **class, int length) {
    if (length == 0) {
        printf("当前没有数据\n");
        return;
    }
    for (int i = 0; i < length; ++i) {
        struct student *student = class[i];
        if (student->chinese < 60 || student->math < 60 || student->english < 60 || student->physics < 60 ||
            student->chemistry < 60) {
            int tot = 0;
            printf("学号:%lld", student->number);
            if (student->chinese < 60) {
                printf("   语文:%d", student->chinese);
                tot += 1;
            }
            if (student->math < 60) {
                printf("   数学:%d", student->math);
                tot += 1;
            }
            if (student->english < 60) {
                printf("   英语:%d", student->english);
                tot += 1;
            }
            if (student->physics < 60) {
                printf("   物理:%d", student->physics);
                tot += 1;
            }
            if (student->chemistry < 60) {
                printf("   化学:%d\n", student->chemistry);
                tot += 1;
            }
            printf("共有%d门科目不及格\n", tot);
        }
    }
}

void printMenu() {
    printf("请输入你的选择:\n1.输入学生数据\n2.输出学生数据\n3.计算输出每个学生的平均成绩，并根据平均成绩排序\n4.计算输出每一个科目的平均成绩、最高成绩，最低成绩，不及格人数，及格率\n5.计算输出不及格人员列表，不及格门次数，和各不及格科目分数\n6.退出\n");
}
