# data structure and algorithm

## 2.常用基本排序的时空分析

> 在实际中，待排序的数很少是单独的数值，它们通常是称为记录的数据集的一部分。每个记录包含一个关键字， 就是排序问题中要重排的值。记录的剩余部分由卫星数据组成，通常与关键字是一同存取的。在实际中，当一个排序算法重排关键字时，也必须要重排卫星数据。如果每个记录包含大量卫星数据，我们通常重排记录指针的数组，而不是记录本身，这样可以降低数据移动量。  
> 在某种意义上，正是这些实现细节将一个算法与成熟的程序区分开来。一个排序算法描述确定有序次序的方法而不管我们是在排序单独的数还是包含很多卫星数据的大记录。因此，当关注排序问题时，我们通常假定输入只是由数组成。将一个对数进行排序的算法转换为一个对记录进行排序的程序在概念上是很直接的，当然在具体的工程情境下，其他一些细节问题可能会使实际的编程工作遇到很多挑战。

|         | 平均   | 最好  | 最坏  | 空间复杂度  |  稳定性  |
| ---     | :---   | :--- | :--- | :---      | :---   |
| 插入排序 | o(n2)  | o(n) | o(n2) | o(1) | 稳定 |
| shell排序 |       |      |      | o(1) | 不稳定 |
| 选择排序 | o(n2) | o(n2) | n(n2) | o(1) | 不稳定 |
| 堆排序  | o(nlogn) | o(nlogn) | o(nlogn) | o(1) | 不稳定 |
| 冒泡排序 | o(n2) | o(n2) | o(n2) | o(1) | 稳定 |
| 快速排序 | o(nlogn) | o(nlogn) | o(n2) | o(logn) | 不稳定 |
| 归并排序 | o(nlogn) | o(nlogn) | o(nlogn) | o(n) | 稳定 |
| 基数排序 | o(d(n+r)) | o(d(n+r)) |o(d(n+r)) | o(n+rd) | 稳定 |

## 3.查找

### (1)二分查找

```c++
int binarySearch(int arr[], int low, int high, int target) {
    if(low > high || target < arr[low] || target > arr[high]) return -1;
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) return binarySearch(arr, mid + 1, high, target);
    if(arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
}
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high || target < arr[low] || target > arr[high]) return -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

主要应用：  

+ 有序数组查找
+ 二分法实现开平方根

## 4.链表

## 5.哈希表

<https://blog.csdn.net/u013074465/article/details/45059639>  
<https://blog.csdn.net/u013074465/article/details/40504975>
<http://blog.jobbole.com/106733/>
[Hash算法总结](https://www.jianshu.com/p/bf1d7eee28d0)

哈希函数，冲突检测，插入实现？？？

## 6.树

### 非递归实现遍历

[树的遍历递归/非递归](https://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html)
<https://leetcode.com/problems/binary-tree-inorder-traversal/description/>

## 7.堆

+ 堆排序
+ 优先级队列：作业调度

## 8.分治

![分治思想](/rsc/分治.png)