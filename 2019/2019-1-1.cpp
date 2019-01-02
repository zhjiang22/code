#include <stdio.h>
#include <stdlib.h>
#ifndef __NODE_H__
#define __NODE_H__
typedef struct Node
{
    int num;
    struct Node *next;
} Node;
#endif

void push(Node **top, int n)
{
    if ((*top) == NULL)
    {
        *top = (Node *)malloc(sizeof(Node));
        Node *p = (Node *)malloc(sizeof(Node));
        (*top)->next = p;
        p->num = n;
        p->next = NULL;
        return;
    }
    Node *p = *top;
    while (p->next != NULL)
        p = p->next;
    Node *q = (Node *)malloc(sizeof(Node));
    q->num = n;
    q->next = NULL;
    p->next = q;
}
int pop(Node **top)
{
    Node *p = *top;
    Node *last = p;
    while (p->next != NULL)
    {
        last = p;
        p = p->next;
    }
    if (p == *top)
        return -1;
    int x = p->num;
    free(p);
    last->next = NULL;
    return x;
}
void del(Node **top)
{
    Node *p = *top;
    Node *q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

int main()
{
    Node *top = NULL;
    int t, n, pop_num;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        push(&top, n);
    }
    scanf("%d", &t);
    while (t--)
    {
        pop_num = pop(&top);
        printf("%d ", pop_num);
    }
    printf("\n");
    if (top)
        del(&top);
    return 0;
}