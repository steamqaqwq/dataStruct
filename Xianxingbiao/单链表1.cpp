#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//按位查找 返回第i个节点 不带头结点
LNode *GetElem1(LinkList L, int i)
{ //强调单链表
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
// 不带头结点 单链表
bool InitList1(LinkList &L)
{
    L = NULL;
    return true;
}
// 不带头结点判断空 L = null

// 带头结点初始化结点判断空
bool InitList(LinkList L)
{
    //头结点分配内存
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
// 判断空 L->next ==NULL
// 带头0个结点 按位查找 返回第i个元素
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *p; //指向当前扫描结点
    int j = 0;
    p = L; //初始化p结点指向头结点
    while (p != NULL && j < i)
    { //i超出则返回NULL
        p = p->next;
        j++;
    }
    return p;
}
// 带头 按值查找 找到数据域==e 的节点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next; //从第一个节点开始
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}
// 带头 按位序(位置i)插入  找到i-1后面插入新节点
bool ListInsert(LinkList L, int i, int e)
{
    if (i < 1)
        return false;
    // LNode *p;  //用指针扫描到当前节点
    // int j = 0; //第几个
    // p = L;     //L指向头结点 头结点是第0个节点
    // while (p != NULL && j < i - 1)
    // { //i-1 下标
    //     p = p->next;
    //     j++;
    // }
    // 封装后
    LNode *p = GetElem(L, i - 1);
    // 后插操作↓↓ 可封装
    if (p == NULL)
        return false; //p不合法时
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
    // 后插操作↑↑
}
// 不带头 单独处理 i==1
// 后插操作 InsertNextNode(p,e) p节点后插e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false; //p不合法时
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 前插操作 偷天换日法
bool InsertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    // 找到 i-1个节点
    LNode *p;
    // int j = 0;
    // p = L;
    // while (p != NULL && j < i - 1)
    // {
    //     p = p->next;
    //     j++;
    // }
    // 封装后
    p = GetElem(L, i - 1); //前驱结点
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;   //判断i-1个节点后无其他节点
    LNode *q = p->next; //用q 指向删除节点
    e = q->data;        //用e接受删除节点数据
    p->next = q->next;  //前p 指向q后
    free(q);
    return true;
}

// 创建单链表 尾插法 O(n)
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //建立头结点
    LNode *s, *r = L;                    //r为表位指针
    scanf("%d", &x);
    while (x != 999)
    { //用一个数来结束循环
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x; //先存数据
        r->next = s; //再让头指向新s
        r = s;       //将r指针指向下一个 伏笔：跳出循环后r指针指向最后一个元素
        scanf("%d", &x);
    }
    //将r指针指向NULL完结
    r->next = NULL;
    return L;
}
// 创建单链表 头插法 #可逆置链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //会有脏数据
    L->next = NULL;                      //好习惯
    scanf("%d", &x);
    while (x != 999)
    {
        // 后插操作
        InsertNextNode(L, x);
    }
    return L;
}
void test()
{
    LinkList L;
    int e;
    printf("INIT:%d\n", InitList(L));
    L = List_TailInsert(L);
    ListDelete(L, 2, e);
    printf("查找10:%d", L->next->next->data);
    printf("\n删除值%d\n", e);
}
int main()
{
    test();
    return 0;
}