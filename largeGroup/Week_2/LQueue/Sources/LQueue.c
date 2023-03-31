#include "../Headers/LQueue.h"
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Node *head = (Node *) malloc(sizeof(Node));//�����׽��
    head->next = NULL;
    Q->front = head;
    Q->rear = head;
    Q->length = 0;
}

/**
 *  @name        : void DestroyLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
    DestroyLQueue(Q);
    InitLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(const ElemType *q) {
    printf("%d\n", *q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
