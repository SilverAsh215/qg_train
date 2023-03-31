#include "../Headers/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_int(ElemType **data);
void show();

int main() {
    show();
    return 0;
}

void get_int(ElemType **data) {
    printf("Please give me a int number:\n");
    ElemType *p = (int *) malloc(sizeof(int));
    char s[50];
    int flag = 1;
    while (1) {
        scanf("%s", s);
        if (*s == '-') {
            if (strlen(s) < 6) {
                int i;
                for (i = 1; i < 6 && s[i] != '\0'; i++)
                    if (s[i] < '0' || s[i] > '9') {
                        flag = 0;
                        break;
                    }
                if (flag == 1) {
                    *p = 0;
                    for (i = 1; i < 6 && s[i] != '\0'; i++)
                        *p = (*p) * 10 + s[i] - '0';
                    (*p) *= -1;
                    *data = p;
                    return;
                }
            }
        } else if (strlen(s) < 5) {
            int i;
            for (i = 0; i < 5 && s[i] != '\0'; i++)
                if (s[i] < '0' || s[i] > '9') {
                    flag = 0;
                    break;
                }
            if (flag == 1) {
                *p = 0;
                for (i = 0; i < 5 && s[i] != '\0'; i++)
                    *p = (*p) * 10 + s[i] - '0';
                *data = p;
                return;
            }
        }
        printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
    }
}

void show() {
    LinkStack *Q = (LinkStack *) malloc(sizeof(LinkStack));
    ElemType *data = (int *) malloc(sizeof(int));
    ElemType *addData;
    int flag;
    int length;
    initLStack(Q);
    while (1) {
        while (1) {
            flag = 0;
            printf("You can do these function:\n");
            printf("1.Check whether the stack is empty or not;\n");
            printf("2.Get the number of the stack head;\n");
            printf("3.Add a number into the stack;\n");
            printf("4.Get a number out of the stack;\n");
            printf("5.Get the length of the stack;\n");
            printf("6.Delete the stack and quit;\n");
            printf("Now please give me the number to finish the function:\n");
            scanf("%d", &flag);
            while (getchar() != '\n')
                ;
            if (flag < 1 || flag > 7) {
                system("cls");
                printf("Please give me the right number!");
            } else
                break;
        }
        switch (flag) {
            case (1):
                if (isEmptyLStack(Q) == ERROR)
                    printf("The stack is empty now!You should add something!\n");
                else
                    printf("The stack is not empty now.\n");
                break;
            case (2):
                if (getTopLStack(Q, data) == SUCCESS)
                    printf("The data is %d\n", *data);
                else
                    printf("The stack is empty now!You should add something!\n");
                break;
            case (3):
                get_int(&addData);
                if (pushLStack(Q, *addData) == SUCCESS)
                    printf("Printf we have add it into the stack!\n");
                else {
                    printf("The room is full!!!\n");
                    exit(-1);
                }
                break;
            case (4):
                if (popLStack(Q, data) == SUCCESS)
                    printf("We have get the node out of the stack.\n"
                           "The data is %d\n",
                           *data);
                else
                    printf("The stack is empty now!\n");
                break;
            case (5):
                if (LStackLength(Q, &length) == SUCCESS)
                    printf("The length of the stack is %d.\n", length);
                else {
                    printf("There is some wrong in the stack!!!\n");
                    exit(-1);
                }
                break;
            case (6):
                destroyLStack(Q);
                free(Q);
                return;
            default:
                break;
        }
    }
}
