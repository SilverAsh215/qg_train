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
                printf("请重新输入\n");
        }
        choice = choose();
    }
    printf("再见");
    return 0;
}

void insertStudent(unsigned long long **record, int *number) {
    unsigned long long studentNumber;
    printf("请输入该学生的学号：");
    scanf_s("%llu", &studentNumber);
    int place = 0;
    while (record[place][0] < studentNumber && place < *number)
        place++;
    if (record[place][0] == studentNumber)
        printf("已存在该名学生\n");
    else {
        if (place != *number) {
            for (int i = *number; i > place; i--) {
                for (int j = 0; j < 6; ++j)
                    record[i][j] = record[i - 1][j];
            }
        }
        record[place][0] = studentNumber;
        printf("请输入该学生的成绩\n");
        printf("数学：");
        scanf_s("%llu", &record[place][1]);
        printf("英语：");
        scanf_s("%llu", &record[place][2]);
        printf("数电：");
        scanf_s("%llu", &record[place][3]);
        printf("模电：");
        scanf_s("%llu", &record[place][4]);
        printf("高程：");
        scanf_s("%llu", &record[place][5]);
        (*number)++;
    }
}

void checkStudent(unsigned long long **record, int number) {
    if (number == 0)
        printf("当前没有学生\n");
    else {
        int place = 0, flag = 0;
        unsigned long long studentNumber;
        printf("请输入你要查询的学生的学号：");
        scanf_s("%llu", &studentNumber);
        for (int i = 0; i < number; ++i) {
            if (record[place][0] == studentNumber) {
                flag = 1;
                break;
            } else
                place++;
        }
        if (flag) {
            printf("该名学生位于第%d号\n该名学生的成绩为：\n数学：%llu\n英语：%llu\n数电：%llu\n模电：%llu\n高程：%llu\n",
                   place + 1, record[place][1], record[place][2], record[place][3], record[place][4], record[place][5]);
        } else
            printf("不存在该名学生\n");
    }
}

void deleteStudent(unsigned long long **record, int *number) {
    if (*number == 0)
        printf("当前没有学生\n");
    else {
        unsigned long long studentNumber;
        int flag = 0;
        printf("请输入你要删除的学生学号：");
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
            printf("不存在该学生\n");
    }
}

void visitStudent(unsigned long long **record, int number) {
    if (number == 0)
        printf("当前没有学生\n");
    else {
        printf("所有学生的学号：\n");
        for (int i = 0; i < number; ++i)
            printf("%d：%llu\n", i + 1, record[i][0]);
    }
}

int choose() {
    int choose;
    printf("请选择你所需要的功能\n1.学生记录插入\n2.学生记录删除\n3.查找学生\n4.浏览所有学生学号\n5.退出\n");
    scanf_s("%d", &choose);
    return choose;
}
