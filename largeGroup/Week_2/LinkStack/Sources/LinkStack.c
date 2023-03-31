#include "../Headers/LinkStack.h"
#include <malloc.h>
//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s) {
    if (s->top)
        return ERROR;
    else {
        StackNode *head = (StackNode *) malloc(sizeof(StackNode));
        s->top = head;
        s->count = 0;
        return SUCCESS;
    }
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s) {
    if (s->top)
        return s->top->next ? SUCCESS : ERROR;
    else
        return ERROR;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s, ElemType *e) {
    if (s->top)
        if (s->top->next) {
            *e = s->top->next->data;
            return SUCCESS;
        } else
            return ERROR;
    else
        return ERROR;
}

//Çå¿ÕÕ»
Status clearLStack(LinkStack *s) {
    if (s->count != 0) {
        StackNode *current = s->top->next, *next;
        while (current) {
            next = current->next;
            free(current);
            current = next;
        }
        s->count = 0;
        return SUCCESS;
    } else
        return ERROR;
}

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s) {
    if (s->top) {
        clearLStack(s);
        free(s->top);
        s->top = NULL;
        return SUCCESS;
    } else
        return ERROR;
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s, int *length) {
    int len = 0;
    if (s->top) {
        StackNode *current = s->top->next;
        while (current) {
            len++;
            current = current->next;
        }
        *length = len;
        if (len == s->count)
            return SUCCESS;
        else
            return ERROR;
    } else
        return ERROR;
}

//ÈëÕ»
Status pushLStack(LinkStack *s, ElemType data) {
    if (s->top) {
        StackNode *last = s->top;
        while (last->next)
            last = last->next;
        StackNode *new = (StackNode *) malloc(sizeof(StackNode));
        new->next = NULL;
        new->data = data;
        last->next = new;
        s->count++;
        return SUCCESS;
    } else
        return ERROR;
}

//³öÕ»
Status popLStack(LinkStack *s, ElemType *data) {
    if (s->top) {
        if (s->top->next) {
            StackNode *last = s->top;
            while (last->next->next)
                last = last->next;
            *data = last->next->data;
            free(last->next);
            last->next = NULL;
            s->count--;
            return SUCCESS;
        } else
            return ERROR;
    } else
        return ERROR;
}
