//#include "../Headers/LQueue.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//void get_int(ElemType **data);
//void show();
//
//int main() {
//    show();
//    return 0;
//}
//
//void get_int(ElemType **data) {
//    printf("Please give me a int number:\n");
//    ElemType *p = (int *) malloc(sizeof(int));
//    char s[50];
//    int flag = 1;
//    while (1) {
//        scanf("%s", s);
//        if (*s == '-') {
//            if (strlen(s) < 6) {
//                int i;
//                for (i = 1; i < 6 && s[i] != '\0'; i++)
//                    if (s[i] < '0' || s[i] > '9') {
//                        flag = 0;
//                        break;
//                    }
//                if (flag == 1) {
//                    *p = 0;
//                    for (i = 1; i < 6 && s[i] != '\0'; i++)
//                        *p = (*p) * 10 + s[i] - '0';
//                    (*p) *= -1;
//                    *data = p;
//                    return;
//                }
//            }
//        } else if (strlen(s) < 5) {
//            int i;
//            for (i = 0; i < 5 && s[i] != '\0'; i++)
//                if (s[i] < '0' || s[i] > '9') {
//                    flag = 0;
//                    break;
//                }
//            if (flag == 1) {
//                *p = 0;
//                for (i = 0; i < 5 && s[i] != '\0'; i++)
//                    *p = (*p) * 10 + s[i] - '0';
//                *data = p;
//                return;
//            }
//        }
//        printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
//    }
//}
//void show() {
//    LQueue *Q = (LQueue *) malloc(sizeof(LQueue));
//    ElemType *data = (ElemType *) malloc(sizeof(ElemType));
//    ElemType *addData;
//    int flag;
//    int length;
//    InitLQueue(Q);
//    while (1) {
//        while (1) {
//            flag = 0;
//            printf("You can do these function:\n");
//            printf("1.Check whether the queue is empty or not;\n");
//            printf("2.Get the number of the queue head;\n");
//            printf("3.Add a number into the queue;\n");
//            printf("4.Get a number out of the queue;\n");
//            printf("5.Read all the node of the queue;\n");
//            printf("6.Get the length of the queue;\n");
//            printf("7.Delete the queue and quit;\n");
//            printf("Now please give me the number to finish the function:\n");
//            scanf("%d", &flag);
//            while (getchar() != '\n')
//                ;
//            if (flag < 1 || flag > 7) {
//                system("cls");
//                printf("Please give me the right number!");
//            } else
//                break;
//        }
//        switch (flag) {
//            case (1):
//                if (IsEmptyLQueue(Q) == TRUE)
//                    printf("The queue is empty now!You should add something!\n");
//                else
//                    printf("The queue is not empty now.\n");
//                break;
//            case (2):
//                if (GetHeadLQueue(Q, data) == TRUE)
//                    LPrint(data);
//                else
//                    printf("The queue is empty now!You should add something!\n");
//                break;
//            case (3):
//                get_int(&addData);
//                if (EnLQueue(Q, addData) == TRUE)
//                    printf("Printf we have add it into the queue!\n");
//                else {
//                    printf("The room is full!!!\n");
//                    exit(-1);
//                }
//                break;
//            case (4):
//                if (DeLQueue(Q) == TRUE)
//                    printf("We have get the node out of the queue.\n");
//                else
//                    printf("The queue is empty now!\n");
//            case (5):
//                TraverseLQueue(Q, LPrint);
//                break;
//            case (6):
//                if (LengthLQueue(Q, &length) == TRUE)
//                    printf("The length of the queue is %d.\n", length);
//                else {
//                    printf("There is some wrong in the queue!!!\n");
//                    exit(-1);
//                }
//                break;
//            case (7):
//                DestroyLQueue(Q);
//                free(Q);
//                return;
//            default:
//                break;
//        }
//    }
//}
