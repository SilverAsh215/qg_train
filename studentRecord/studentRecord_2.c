#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct student {
    char number[20];
    char name[10];
    char class[20];
    char grade[10];
    struct student *next;
};

void insertStudent(struct student *class, int place);

int searchStudent(struct student *class, char name[10], int length);

void travelStudent(struct student *class, int length);

int choose();

int main() {
    struct student *class = (struct student *) malloc(sizeof(struct student));
    int length = 0, choice = choose();
    while (choice != 4) {
        switch (choice) {
            case 1:
                printf("可插入的位置为1 ~ %d：", length + 1);
                int place;
                scanf_s("%d", &place);
                while (place < 1 || place > length + 1) {
                    printf("请重新输入\n");
                    printf("可插入的位置为1 ~ %d：", length + 1);
                    scanf_s("%d", &place);
                }
                insertStudent(class, place);
                length++;
                break;
            case 2:
                if (length == 0)
                    printf("当前没有任何学生的信息\n");
                else {
                    char name[10];
                    printf("请输入该名学生的姓名：");
                    scanf_s("%s", name);
                    searchStudent(class, name, length);
                }
                break;
            case 3:
                if (length == 0)
                    printf("当前没有任何学生的信息\n");
                else
                    travelStudent(class, length);
                break;
            default:
                printf("请重新输入\n");
        }
        choice = choose();
    }
    printf("再见");

    return 0;
}

void insertStudent(struct student *class, int place) {
    struct student *person = (struct student *) malloc(sizeof(struct student));
    printf("姓名：");
    scanf_s("%s", person->name);
    printf("学号：");
    scanf_s("%s", person->number);
    printf("年级：");
    scanf_s("%s", person->grade);
    printf("班级：");
    scanf_s("%s", person->class);
    while (place > 1) {
        class = class->next;
        place--;
    }
    if (class->next)
        person->next = class->next;
    class->next = person;
}

int searchStudent(struct student *class, char name[10], int length) {
    struct student *current = class;
    int place = 0;
    while (place < length) {
        current = current->next;
        place++;
        if (strcmp(current->name, name) == 0) {
            printf("该名学生为第%d位，以下为该名学生的信息\n姓名：%s\n学号：%s\n年级：%s\n班级：%s\n", place, current->name,
                   current->number, current->grade, current->class);
            return place;
        }
    }
    printf("不存在该名学生的信息\n");
    return -1;
}

void travelStudent(struct student *class, int length) {
    struct student *current = class;
    int locate = 0;
    while (locate < length) {
        current = current->next;
        locate++;
        printf("%d号：%s\n", locate, current->name);
    }
}

int choose() {
    int choose;
    printf("请选择你所需要的功能\n1.插入学生信息\n2.查找学生信息\n3.浏览所有学生\n4.退出\n");
    scanf_s("%d", &choose);
    return choose;
}
