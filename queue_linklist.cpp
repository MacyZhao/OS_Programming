/*************************************************************************
	> File Name: queue_linklist.c
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 07:00:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node
{
    int data;
    Node *next;
} Node;
typedef struct Linklist
{
    Node head, *tail;
}Linklist;
Node  *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}
Linklist *initLinklist()
{
    Linklist *l = (Linklist *)malloc(sizeof(Linklist));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}
int emptyList(Linklist *l)
{
    return l->head.next == NULL;
}
int frontList(Linklist *l)
{
    if(emptyList(l)) return 0;
    return l->head.next->data;
}
int insertTail(Linklist *l, int val)
{
    Node *node = getNewNode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}
int eraseHead(Linklist *l)
{
    if(emptyList(l)) return 0;
    Node *p = l->head.next;
    l->head.next = l->head.next->next;
    if(p == l->tail) l->tail = &(l->head);
    free(p);
    return 1;
}
void clearLinklist(Linklist *l)
{
    Node *p = l->head.next, *q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}
typedef struct Queue
{
    Linklist *l;
    int count;
}Queue;
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->l = initLinklist();
    q->count = 0;
    return q;
}
int empty(Queue *q) {
    return q->count == 0;
}
int front(Queue *q) {
    if(empty(q)) return 0;
    return frontList(q->l);
}
int push(Queue *q, int val) {
    insertTail(q->l, val);
    q->count += 1;
    return 1;
}
int pop(Queue *q) {
    eraseHead(q->l);
    q->count -= 1;
    return 1;
}
void clearQueue(Queue * q)
{
    if(q == NULL) return ;
    clearLinklist(q->l);
    free(q);
    return ;
}
void outputQueue(Queue *q)
{
    printf("Queue : ");
    Node *p = q->l->head.next;
    for(int i = 0; i < q->count; i++, p = p->next)
    {
        printf("%4d", p->data);

    }
    printf("\n");
}
int main()
{
    srand(time(0));
#define MAX_OP 10
    Queue *q = initQueue();
    for(int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 5, val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            {printf("front of queue : %d\n", front(q));
                pop(q);
                break;}
            case 2:
            case 3:
            case 4:
            {printf("push %d to queue\n", val);
                push(q, val);
                break;}
        }
        outputQueue(q);
    }
    clearQueue(q);
    return 0;
}
