#include <stdio.h>

typedef struct BTNode
{
    int data;
    int lTag;
    int rTag;
    BTNode *lChild;
    BTNode *rChild;
} BTNode;

void inThread(BTNode *p,BTNode *pre){
    if(p!=NULL)
    {
        inThread(p->lChild,pre);
        if(p->lChild==NULL){
            p->lChild = pre;
            p->lTag = 1;
        }
        if(pre!=NULL && pre->rChild==NULL){
            pre->rChild = 
        }
    }
}