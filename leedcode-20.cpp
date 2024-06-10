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
    char *data;
    int size, top;
}Stact;
Stact *initStact(char n)
{
    Stact *s = (Stact *)malloc(sizeof(Stact));
    s->data = (char *)malloc(sizeof(char) * n);
    s->size = n;
    s->top = -1;
    return s;
}
int empty(Stact *s)
{
    return s->top == -1;
}
char top(Stact *s)
{
    if(empty(s)) return 0;
    return s->data[s->top];
}
int push(Stact *s, char val)
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
void solve(char str[])
{
    int flag = 1;
    Stact *s = initStact(100);
    for(int i = 0; str[i]; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(s, str[i]);}
        else
            {
                switch(str[i]) {
                                case ')': {if(!empty(s) && top(s) == '(') pop(s);
                                  else flag = 0;
                                 }break;
                                case ']':{
                                    if(!empty(s) && top(s) == '[') pop(s);
                                    else flag = 0;
                                    } break;
                                case '}': {
                                    if(!empty(s) && top(s) == '{') pop(s);
                                    else flag = 0;
                                } break;
                } 
                
            }
            if(flag == 0) break;
    }
    if(flag == 0 || !empty(s))
    {
        printf("error\n");                                               
    }else{
        printf("success\n");
    }
     clearStact(s);
    return  ;
}
int main()
{
    char str[100];
    while(~scanf("%s", str)){
        solve(str);
    }
    return 0;
}
