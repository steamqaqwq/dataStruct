#include <stdio.h>
// 重点！！！！！！！！
// 思路  拿一个数抽出当基准,就空出一个 右小于基准
// 快速排序 low基准 分左右 low<基准<high
// 左空右移 low==high基准元素找出位置
// 左右字表 再次递归排序
//---------------------------
// 选取元素 头中尾对比挑/随机挑
// 算法效率 划分均匀 递归深度小 算法效率高
// 时间复杂度 = O(n*递归层数) 空间复杂度=O(递归层数)
// 最好时间复杂度=O(nlog2n) #每次基准元素均匀划分
// 最坏时间复杂度=O(n^2) #序列本有序/逆序
// 最好空间复杂度=O(log2n)
// 最坏空间复杂度=O(n)
// 平均时间复杂度=O(nlog2n) 平均最优排序算法
// 稳定性: 不稳定   #稳定方向要对

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high) //循环结束条件low==high
    {                  //查找小于基准值
        while (low < high && a[high] >= pivot)
            --high;
        // 找到小的 移动到左端
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        //找到大的 移动到右端
        a[high] = a[low];
    }
    a[low] = pivot; //枢轴元素放到  此时low==high
    return low;
}
void QuickSort(int a[], int low, int high)
{
    // low 0  high 7
    if (low < high)
    {
        int pivotpos = Partition(a, low, high); //定基准
        QuickSort(a, low, pivotpos - 1);        //划分左
        QuickSort(a, pivotpos + 1, high);       //划分右
    }
}

/////////////////////////////////////////////////
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}
void QuickSort2(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(a, low, high);
        QuickSort2(a, low, pivotpos - 1);
        QuickSort2(a, pivotpos + 1, high);
    }
}
/////////////////////////////////////////////////

int main()
{
    int a[10] = {9, 8, 7, 3, 5, 1};
    QuickSort2(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
}