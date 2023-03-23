//
// Created by xu on 23-3-19.
//

#include "../Headers/linkedList_realize.h"

int main() {
    int n, s, length = 0;
    LinkedList L;
    ElemType e;
    LNode *middle;
    PrintMenu();
    s = scanf("%d", &n);
    while (n != 13) {
        if (s == 1 && n >= 1 && n <= 12) {
            switch (n) {
                case 1:
                    InitList(&L);
                    printf("success\n");
                    break;
                case 2:
                    DestroyList(&L);
                    length = 0;
                    printf("success\n");
                    break;
                case 3:
                    printf("please input the data: ");
                    scanf("%d", &e);
                    LNode *q = (LNode *) malloc(sizeof(LNode));
                    q->data = e;
                    q->next = NULL;
                    int place;
                    printf("where(1 ~ %d): ", length + 1);
                    scanf("%d", &place);
                    if (place > length + 1 || place <= 0) {
                        printf("error input\n");
                    } else {
                        LinkedList p = L;
                        for (int i = 1; i < place; i++)
                            p = p->next;
                        InsertList(p, q);
                        length++;
                        printf("success\n");
                    }
                    break;
                case 4:
                    printf("input which you want to delete(1 ~ %d): ", length);
                    scanf("%d", &e);//位置
                    if (e > 0 && e <= length) {
                        LinkedList t = L;
                        for (int i = 1; i < e; i++)//找到结点p
                            t = t->next;
                        DeleteList(t, &e);
                        printf("%d\n", e);//打印e
                        length--;
                        printf("success\n");
                    } else
                        printf("error input\n");
                    break;
                case 5:
                    TraverseList(L, visit);
                    break;
                case 6:
                    printf("please input what you want to search: ");
                    scanf("%d", &e);
                    if (!SearchList(L, e))
                        printf("no\n");
                    break;
                case 7:
                    ReverseList(&L);
                    printf("success\n");
                    break;
                case 8:
                    if (IsLoopList(L))
                        printf("yes\n");
                    else
                        printf("no\n");
                    break;
                case 9:
                    L = L->next;
                    L = ReverseEvenList(&L);
                    printf("success\n");
                    break;
                case 10:
                    middle = FindMidNode(&L);
                    printf("%d\n", middle->data);
                    break;
                case 11:
                    MakeLoop(&L);
                    printf("success\n");
                    break;
                case 12:
                    MakeNotLoop(&L);
                    printf("success\n");
                default:
                    break;
            }
        } else
            printf("you input a worry number\n");
        PrintMenu();
        s = scanf("%d", &n);
    }
    printf("see you next time");
    return 0;
}