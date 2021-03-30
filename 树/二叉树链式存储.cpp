#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
struct ElemType
{
    int value;
};
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild, *parent;
} BiTNode, *BiTree;

void BiTreeInsert(BiTree root, ElemType a)
{
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = a;
    root->lchild = p;
    p->rchild = NULL;
    p->lchild = NULL;
}
void visit(BiTree T)
{
}
// 递归深度优先遍历 (中序遍历)
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);            //访问根
        PreOrder(T->lchild); //访问左
        PreOrder(T->rchild); //访问右
    }
}

// 非递归算法深度优先遍历
// 模拟栈
void preorderNonrecursion(BiTree T)
{
    if (T != NULL)
    {
        BiTNode *Stack[MaxSize]; //结点地址
        int top = -1;
        BiTNode *p = NULL;
        Stack[++top] = T;
        while (top != -1)
        {
            p = Stack[top--]; //出栈
            visit(p);
            // 左右孩子在就入栈
            if (p->rchild != NULL)
                Stack[++top] = p->rchild;
            if (p->lchild != NULL)
                Stack[++top] = p->lchild;
        }
    }
}

// 后序非递归遍历序列
void postorderNonrecursion(BiTree T)
{
    if (T != NULL)
    {
        BiTNode *Stack1[MaxSize];
        int top1 = -1;
        // 辅助栈 用来逆序序列
        BiTNode *Stack2[MaxSize];
        int top2 = -1;

        BiTNode *p = NULL;
        Stack1[++top1] = T;
        while (top1 != -1)
        {
            p = Stack1[top1--]; //出栈
            Stack2[++top2] = p;
            // 左右孩子在就入栈
            if (p->rchild != NULL)
                Stack1[++top1] = p->rchild;
            if (p->lchild != NULL)
                Stack1[++top1] = p->lchild;
        }
        while (top2 != -1)
        {
            p = Stack2[top2--]; //出栈
            visit(p);
        }
    }
}
// 中序非递归遍历
void inorderNonrecursion(BiTree T)
{
    if (T != NULL)
    {
        BiTNode *Stack[MaxSize];
        BiTNode *p = NULL;
        int top = -1;
        p = T;
        while (top != -1 || p != NULL)
        {
            while (p != NULL)
            {
                Stack[++top] = p;
                p = p->lchild;
            }
            if (top != -1)
            {
                p = Stack[top--];
                visit(p);
                p = p->rchild;
            }
        }
    }
}
// 层次遍历
void level(BiTree T)
{
    if (T != NULL)
    {
        int front, rear;
        BiTNode *que[MaxSize];
        front = rear = 0;
        BiTNode *p;
        rear = (rear + 1) % MaxSize;
        que[rear] = T;
        while (front != rear)
        {
            front = (front + 1) % MaxSize;
            p = que[front];
            visit(p);
            // 左孩子先 右孩子后
            if (p->lchild != NULL)
            {
                rear = (rear + 1);
                que[rear] = p->lchild
            }
            if (p->rchild != NULL)
            {
                rear = (rear + 1);
                que[rear] = p->rchild;
            }
        }
    }
}



// 定义空树
int main()
{
    BiTree root = NULL;
    // 插入根节点
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;
}
