//
// Created by xu on 23-3-19.
//

#include "duLinkedList.h"
#include <malloc.h>

Status InitList_DuL(DuLinkedList *L) {
    struct DuLNode *head = (struct DuLNode *) malloc(sizeof(struct DuLNode));//创建首结点
    head->prior = NULL;
    head->next = NULL;//初始化
    *L = head;        //插入结点
    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L) {
    struct DuLNode *current = *L;//创建一个新的DuLNode
    while (current != NULL)      //遍历链表
    {
        *L = current->next;
        free(current);//释放结点
        current = *L;
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p != NULL)//判断p是否为空
    {
        q->prior = p->prior;//使q结点成为p结点的前一个结点的下一个结点
        p->prior = q;       //使q结点成为p结点的上一个结点
        return SUCCESS;
    } else
        return ERROR;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p != NULL)//判断p是否为空
    {
        p->next = q->next;//使q结点成为p结点的下一个结点的上一个结点
        q->next = p;      //使q结点成为p结点的下一个结点
        return SUCCESS;
    } else
        return ERROR;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if (p->next != NULL)//判断p的下一个结点是否为空
    {
        if (p->next->next != NULL)  //判断p的下一个结点的下一个结点是否为空
            p->next = p->next->next;//使p的下一个结点的下一个结点成为p的下一个结点
        *e = p->next->data;         //使e为p的下一个结点的data
        free(p->next);              //释放p的下一个结点
        return SUCCESS;
    } else
        return ERROR;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    while (L->next != NULL)//遍历链表
    {
        visit(L->data);
        L->next = L->next->next;//使L成为L的下一个结点
    }
}
