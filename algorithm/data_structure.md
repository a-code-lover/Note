# data structure

## 1.常见数据结构应用汇总：

### (1)堆

+ 堆排序
+ 优先级队列：作业调度

## 2.常用基本排序的时空分析

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

哈希函数，冲突检测，插入实现？？？

## 6.树

### 非递归实现遍历

<https://leetcode.com/problems/binary-tree-inorder-traversal/description/>