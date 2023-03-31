#include "../Headers/LQueue.h"
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Node *head = (Node *) malloc(sizeof(Node));//创建首结点
    head->next = NULL;
    Q->front = head;
    Q->rear = head;
    Q->length = 0;
}

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestroyLQueue(LQueue *Q) {
    Node *head = Q->front;
    Node *current = head->next;
    while (current) {
        head = current->next;
        free(current);
        current = head;
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
    if (!Q->front->next)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, ElemType *e) {
    if (Q->front->next) {
        *e = *Q->front->next->data;
        return TRUE;
    } else
        return FALSE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q, int *length) {
    int len = 0;
    if (Q->front) {
        Node *current = Q->front->next;
        while (current) {
            len++;
            current = current->next;
        }
        *length = len;
        if (len == Q->length)
            return TRUE;
        else
            return FALSE;
    } else
        return FALSE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, ElemType *data) {
    Node *current = (Node *) malloc(sizeof(Node));
    current->next = NULL;
    current->data = data;
    if (Q->length != 50) {
        Q->rear->next = current;
        Q->rear = current;
        (Q->length)++;
        return TRUE;
    } else
        return FALSE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
    if (Q->front) {
        if (Q->front->next) {
            Node *front = Q->front;
            Q->front = Q->front->next;
            free(front);
            (Q->length)--;
            return TRUE;
        } else
            return FALSE;
    } else
        return FALSE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
    DestroyLQueue(Q);
    InitLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(const ElemType *q)) {
    if (Q->front) {
        Node *current = Q->front->next;
        while (current) {
            foo(current->data);
            current = current->next;
        }
        return TRUE;
    } else
        return FALSE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(const ElemType *q) {
    printf("%d\n", *q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
