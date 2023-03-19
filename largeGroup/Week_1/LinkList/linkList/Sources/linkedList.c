//
// Created by xu on 23-3-19.
//

#include "linkedList.h"
#include <malloc.h>

Status InitList(LinkedList *L) {
    struct LNode *head = (struct LNode *) malloc(sizeof(struct LNode));//创建首结点
    head->next = NULL;                                                 //初始化
    *L = head;                                                         //插入结点
    return SUCCESS;
}

void DestroyList(LinkedList *L) {
    struct LNode *current = *L;//创建一个新的LNode
    while (current != NULL)    //遍历链表
    {
        *L = current->next;
        free(current);//释放结点
        current = *L;
    }
}

Status InsertList(LNode *p, LNode *q) {
    if (p != NULL)//判断p是否为空
    {
        p->next = q->next;//使q结点成为p结点的下一个结点的上一个结点
        q->next = p;      //使q结点成为p结点的下一个结点
        return SUCCESS;
    } else
        return ERROR;
}

Status DeleteList(LNode *p, ElemType *e) {
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

void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    while (L->next != NULL)//遍历链表
    {
        visit(L->data);
        L->next = L->next->next;//使L成为L的下一个结点
    }
}

Status SearchList(LinkedList L, ElemType e) {
    while (L->next != NULL)//遍历链表
    {
        if (L->data == e)
            return SUCCESS;//找到了
        L->next = L->next->next;
        L->data = L->next->data;//不是这个，找下一个
    }
    return ERROR;//没找到
}

Status ReverseList(LinkedList *L)//迭代
{
    LNode *current = *L;            //现在的
    LinkedList next = current->next;//下一个
    while (current->next != NULL) {
        LinkedList next_next = next->next;//下一个的下一个
        *next->next = *current;           //使现在的成为下一个的下一个
        current = next;                   //使下一个成为现在的
        next = next_next;                 //使下一个的下一个成为下一个
    }
    return SUCCESS;
}

Status IsLoopList(LinkedList L) {
    LinkedList slow = L->next, fast = L->next->next;//快慢
    while (fast->next->next != NULL)                //如果为NULL则说明不是
    {
        if (fast == slow)//快慢相遇
            return SUCCESS;
        slow = slow->next;
        fast = fast->next->next;//没相遇，下一个
    }
    return ERROR;
}

LNode *ReverseEvenList(LinkedList *L) {
    LinkedList odd = *L;                                //单数
    LinkedList even = odd->next, next = odd->next->next;//偶数和偶数的下一个
    LinkedList newHead = even;                          //新的头结点
    while (even != NULL) {
        *even->next = *odd;//单数成为偶数的下一个
        *odd->next = *next;//偶数的下一个成为单数的下一个
        odd = next;        //单数为偶数的下一个
        even = next->next; //偶数为偶数的下一个的下一个
    }
    return newHead;//返回新的头结点
}

LNode *FindMidNode(LinkedList *L) {
    LinkedList slow = *L, fast = *L;//快慢
    while (fast->next != NULL)      //等待快指针到达链表尾部
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;//返回中间结点
}
