//
// Created by reese on 23-3-22.
//
#include "../Headers/duLinkedList.h"
#include <malloc.h>
#include <stdio.h>

Status InitList_DuL(DuLinkedList *L) {
    DuLNode *head = (DuLNode *) malloc(sizeof(DuLNode));//创建首结点
    head->prior = NULL;
    head->next = NULL;//初始化
    *L = head;        //插入结点
    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList current = *L, next, prior;//创建一个新的DuLNode
    if (current->next)                     //下
    {
        current = current->next;
        while (current)//遍历链表
        {
            next = current->next;
            free(current);//释放结点
            current = next;
        }
    }
    current = *L;
    if (current->prior)//上
    {
        current = current->prior;
        while (current)//遍历链表
        {
            prior = current->prior;
            free(current);//释放结点
            current = prior;
        }
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p->prior)//判断p是否有上一个结点
    {
        q->prior = p->prior;//使p结点的上一个结点成为q结点的上一个结点
        p->prior->next = q; //使p结点的上一个结点的下一个结点为q
    }
    q->next = p; //使p结点成为q结点的下一个结点
    p->prior = q;//使q结点成为p结点的上一个结点
    return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p->next)//判断p是否有下一个结点
    {
        q->next = p->next; //使q结点成为p结点的下一个结点的上一个结点
        p->next->prior = q;//使q成为p的下一个的上一个
    }
    p->next = q; //使q结点成为p结点的下一个结点
    q->prior = p;//使p结点成为q结点的上一个结点
    return SUCCESS;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLinkedList next = NULL;
    if (p->next->next)//判断p的下一个结点是否为空
    {
        next = p->next->next;//使next等于p的下一个结点的下一个结点
        next->prior = p;     //使next的上一个结点成为p
    }
    *e = p->next->data;//使e为p的下一个结点的data
    free(p->next);     //释放p的下一个结点
    p->next = next;    //使p的下一个结点的下一个结点成为p的下一个结点
    return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList current = L;
    while (current->prior)
        current = current->prior;
    while (current)//遍历链表
    {
        if (current == L) {
            current = current->next;
            continue;
        }
        visit(current->data);
        current = current->next;//使L成为L的下一个结点
    }
}

void duVisit(ElemType e)//visit
{
    printf("%d\n", e);
}

void duPrintMenu()//打印菜单
{
    printf("****************************************************************************\n"
           "           input to choose what you need(please InitList first)\n"
           "1.InitList    2.DestroyList   3.InsertBeforeList   4.InsertAfterList\n"
           "5.DeleteList  6.TraverseList  7.exit\n"
           "****************************************************************************\n");
}
