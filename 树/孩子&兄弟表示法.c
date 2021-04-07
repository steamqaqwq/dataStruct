#define ElemType int
#define Tree_Size 10
//孩子兄弟表示法
typedef struct CSNode
{
    ElemType data;
    struct CSNode *child, *nextsibling;
} CSnode, *CSTree;

// 孩子表示法
typedef struct CTNode
{
    int child; //存储下标
    struct CTNode *next;
} * ChildPtr; //孩子结点
typedef struct
{
    ElemType data;       //结点的数据
    ChildPtr firstchild; //孩子链表头指针
} CTBox;                 //数组结点

typedef struct
{
    CTBox nodes[Tree_Size]; //存储结点的数组
    int n;                  //结点数量
} CTree;                    //树