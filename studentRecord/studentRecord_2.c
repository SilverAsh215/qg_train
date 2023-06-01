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
                printf("�ɲ����λ��Ϊ1 ~ %d��", length + 1);
                int place;
                scanf_s("%d", &place);
                while (place < 1 || place > length + 1) {
                    printf("����������\n");
                    printf("�ɲ����λ��Ϊ1 ~ %d��", length + 1);
                    scanf_s("%d", &place);
                }
                insertStudent(class, place);
                length++;
                break;
            case 2:
                if (length == 0)
                    printf("��ǰû���κ�ѧ������Ϣ\n");
                else {
                    char name[10];
                    printf("���������ѧ����������");
                    scanf_s("%s", name);
                    searchStudent(class, name, length);
                }
                break;
            case 3:
                if (length == 0)
                    printf("��ǰû���κ�ѧ������Ϣ\n");
                else
                    travelStudent(class, length);
                break;
            default:
                printf("����������\n");
        }
        choice = choose();
    }
    printf("�ټ�");

    return 0;
}

void insertStudent(struct student *class, int place) {
    struct student *person = (struct student *) malloc(sizeof(struct student));
    printf("������");
    scanf_s("%s", person->name);
    printf("ѧ�ţ�");
    scanf_s("%s", person->number);
    printf("�꼶��");
    scanf_s("%s", person->grade);
    printf("�༶��");
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
            printf("����ѧ��Ϊ��%dλ������Ϊ����ѧ������Ϣ\n������%s\nѧ�ţ�%s\n�꼶��%s\n�༶��%s\n", place, current->name,
                   current->number, current->grade, current->class);
            return place;
        }
    }
    printf("�����ڸ���ѧ������Ϣ\n");
    return -1;
}

void travelStudent(struct student *class, int length) {
    struct student *current = class;
    int locate = 0;
    while (locate < length) {
        current = current->next;
        locate++;
        printf("%d�ţ�%s\n", locate, current->name);
    }
}

int choose() {
    int choose;
    printf("��ѡ��������Ҫ�Ĺ���\n1.����ѧ����Ϣ\n2.����ѧ����Ϣ\n3.�������ѧ��\n4.�˳�\n");
    scanf_s("%d", &choose);
    return choose;
}
