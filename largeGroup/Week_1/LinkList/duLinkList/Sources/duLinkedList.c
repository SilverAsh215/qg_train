//
// Created by xu on 23-3-19.
//

#include "../Headers/duLinkedList_realize.h"

int main() {
    int n, s, prior = 0, next = 0;
    DuLinkedList L;
    ElemType e;
    PrintMenu();
    s = scanf_s("%d", &n);
    while (n != 7) {
        if (s == 1 && n >= 1 && n <= 6) {
            switch (n) {
                case 1:
                    InitList_DuL(&L);
                    printf("success\n");
                    break;
                case 2:
                    DestroyList_DuL(&L);
                    prior = 0;
                    next = 0;
                    printf("success\n");
                    break;
                case 3:
                    printf("please input the data: ");
                    scanf_s("%d", &e);
                    DuLNode *qb = (DuLNode *) malloc(sizeof(DuLNode));
                    qb->data = e;
                    qb->next = NULL;
                    qb->prior = NULL;
                    int place_b;
                    printf("before(%d ~ %d): ", prior, next);
                    scanf_s("%d", &place_b);
                    if (place_b > next || place_b < prior)
                        printf("error input\n");
                    else {
                        DuLinkedList p = L;
                        if (place_b > 0) {
                            for (int i = 0; i < place_b; i++)
                                p = p->next;
                            next++;
                        } else {
                            for (int i = 0; i > place_b; i--)
                                p = p->prior;
                            prior--;
                        }
                        InsertBeforeList_DuL(p, qb);
                        printf("success\n");
                    }
                    break;
                case 4:
                    printf("please input the data: ");
                    scanf_s("%d", &e);
                    DuLNode *qa = (DuLNode *) malloc(sizeof(DuLNode));
                    qa->data = e;
                    qa->next = NULL;
                    qa->prior = NULL;
                    int place_a;
                    printf("after(%d ~ %d): ", prior, next);
                    scanf_s("%d", &place_a);
                    if (place_a > next || place_a < prior)
                        printf("error input\n");
                    else {
                        DuLinkedList p = L;
                        if (place_a >= 0) {
                            for (int i = 0; i < place_a; i++)
                                p = p->next;
                            next++;
                        } else {
                            for (int i = 0; i > place_a; i--)
                                p = p->prior;
                            prior--;
                        }
                        InsertAfterList_DuL(p, qa);
                        printf("success\n");
                    }
                    break;
                case 5:
                    printf("input which you want to delete(%d ~ %d): ", prior, next);
                    scanf_s("%d", &e); // 位置
                    DuLinkedList t = L;
                    if (e > 0 && e <= next) {
                        for (int i = 1; i < e; i++) // 找到结点p
                            t = t->next;
                        next--;
                    } else if (e < 0 && e > prior) {
                        for (int i = 0; i >= e; i--) // 找到结点p
                            t = t->prior;
                        prior++;
                    } else if (e == prior)//特别处理
                    {
                        DuLinkedList current = L;
                        while (current->prior)
                            current = current->prior;
                        current->next->prior = NULL;
                        free(current);
                        prior++;
                        printf("success\n");
                        break;
                    } else {
                        printf("error input\n");
                        break;
                    }
                    DeleteList_DuL(t, &e);
                    printf("%d\n", e); // 打印e
                    break;
                case 6:
                    printf("\n");
                    TraverseList_DuL(L, visit);
                    break;
                default:
                    break;
            }
        } else {
            printf("you input a worry number\n"
                   "input '0' to continue\n");
            char c;
            while ((c = getchar()) != '0');
        }
        PrintMenu();
        s = scanf_s("%d", &n);
    }
    printf("see you next time");
    return 0;
}
