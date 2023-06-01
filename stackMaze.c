#include <stdio.h>
#include <malloc.h>

struct stack {
    int x, y;
    struct stack *next;
};

struct stack *stackInit();

int stackEmpty(struct stack *stackHead);

void stackPush(struct stack *stackHead, int x, int y);

void stackPop(struct stack *stackHead, int *x, int *y);

int main() {
    struct stack *stackHead = stackInit();
    int maze[10][10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                        1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
                        1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
                        1, 0, 1, 1, 1, 0, 0, 0, 1, 1,
                        1, 0, 0, 0, 1, 0, 0, 0, 1, 1,
                        1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
                        1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 0, 2, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int visited[10][10] = {0};
    int move[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    stackPush(stackHead, 1, 1);
    visited[1][1] = 1;
    int x, y;
    do {
        stackPop(stackHead, &x, &y);
        if (maze[x][y] == 2) {
            printf("有路径可以通向出口\n");
            break;
        } else {
            for (int i = 0; i < 4; ++i) {
                int a = x + move[i][0], b = y + move[i][1];
                if ((maze[a][b] == 0 || maze[a][b] == 2) && visited[a][b] == 0) {
                    visited[a][b] = 1;
                    stackPush(stackHead, a, b);
                }
            }
        }
    } while (!stackEmpty(stackHead));
    if (stackEmpty(stackHead))
        printf("没有路径可以通向出口");
    return 0;
}

struct stack *stackInit() {
    struct stack *stackHead = (struct stack *) malloc((sizeof(struct stack)));
    stackHead->next = NULL;
    return stackHead;
}

int stackEmpty(struct stack *stackHead) {
    int flag = 1;
    if (stackHead->next)
        flag = 0;
    return flag;
}

void stackPush(struct stack *stackHead, int x, int y) {
    struct stack *new = (struct stack *) malloc(sizeof(struct stack));
    struct stack *current = stackHead;
    while (current->next)
        current = current->next;
    new->x = x;
    new->y = y;
    new->next = NULL;
    current->next = new;
}

void stackPop(struct stack *stackHead, int *x, int *y) {
    if (!stackEmpty(stackHead)) {
        struct stack *current = stackHead;
        while (current->next->next)
            current = current->next;
        struct stack *last = current->next;
        current->next = NULL;
        *x = last->x;
        *y = last->y;
        free(last);
    }
}
