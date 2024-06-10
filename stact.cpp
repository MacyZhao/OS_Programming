/*************************************************************************
	> File Name: stact.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jun 2024 09:08:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Stact
{
    int *data;
    int size, top;
}Stact;
Stact *initStact(int n)
{
    Stact *s = (Stact *)malloc(sizeof(Stact));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}
int empty(Stact *s)
{
    return s->top == -1;
}
int top(Stact *s)
{
    if(empty(s)) return 0;
    return s->data[s->top];
}
int push(Stact *s, int val)
{
    if(s->top + 1 == s->size) return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}
int pop(Stact *s)
{
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}
void clearStact(Stact *s)
{
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}
void outputStact(Stact *s)
{
    printf("Stact:");
    for(int i = s->top; i >= 0; --i)
    {
        printf("%4d", s->data[i]);
    }
    printf("\n\n");
}
int main()
{
    srand(time(0));
    #define MAX_OP 10
    Stact *s = initStact(5);
    for(int i = 0; i < MAX_OP; i ++)
    {
        int op = rand() % 3, val = rand() % 100;
        switch(op)
        {
            case 0:
            {
                printf("pop stact, item = %d\n", top(s));
                pop(s);
                break;
            }
            case 1:
            case 2:
            {
                printf("push stact, item = %d\n", val);
                push(s, val);
                break;
            }
        }
        outputStact(s);
    }
    clearStact(s);
    return 0;
}
