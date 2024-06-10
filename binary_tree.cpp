/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Jun 2024 05:48:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_OP 10
typedef struct Node
{
    int key;
    struct Node *lchild, *rchild;
} Node;
Node *GetNewNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->lchild = node->rchild = NULL;
    return node;
}
Node *insert(Node *root, int key)
{
    if(root == NULL) return GetNewNode(key);
    if(rand() % 2 == 0) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}
void clear(Node *root)
{
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}
Node* queue[MAX_OP + 5];
void bfs(Node * root)  //层序遍历
{
    int head, tail;
    head = tail = 0;
    queue[tail++] = root;
     while(head < tail)
    {
        Node *node = queue[head];
        printf("\nnode : %d\n", node->key);
        if(node->lchild) {
            queue[tail++] = node->lchild;
            printf("\t%d->%d (left) \n", node->key, node->lchild->key);
        }
        if(node->rchild) {
            queue[tail++] = node->rchild;
            printf("\t%d->%d (right) \n", node->key, node->rchild->key);
        }
        head++;
    }
    return ;
}
int tot = 0;
void dfs(Node *root) //深度优先遍历
{
    if(root == NULL) return ;
    int start, end;
    tot += 1;
    start = tot;
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    tot += 1;
    end = tot;
    printf("%d : [%d, %d]\n", root->key, start, end);
    return ;
}
int main()
{
    srand(time(0));
    Node *root = NULL;
    for(int i = 0; i < MAX_OP; i++)
    {
        root = insert(root, rand() % 100);
    }
    bfs(root);
    dfs(root);
    return 0;
}
