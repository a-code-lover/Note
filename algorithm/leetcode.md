# 刷题汇总

## 性能分析

```c++
int x=[](){
    std::ios::sync_with_stdio(false);  //关闭STDIN和CIN同步 减少CIN读入的时间，可以减少50%以上。
    cin.tie(NULL);
    return 0;
}();
```

## 4. median of two sorted array

<https://blog.csdn.net/yutianzuijin/article/details/11499917>

## 5.LPS

思路：二维dp, brutal

## 10. regular expression matchming

思路：二维dp，双指针

## 22.generate parenthesis

思路：递归或迭代

## 23.merge k sorted lists

思路：1. priority_queue(不够熟练)  2. incursive, merge 2 to merge n

## 28.implement strstr

<https://leetcode.com/problems/implement-strstr/discuss/12956/Explained-4ms-Easy-C++-solution>  
思路：1. brutal  2.kmp

## 29.divide two integer

思路：不能使用乘除求余运算，因此使用位运算，左移运算 + 符号。

## 33.search in rotated sorted array

思路：binary search， mid and realmid(clever idea).

## 49.group anagrams

思路：prime number

## all. 排列组合问题

## all. substring 问题

<https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems>

```c++
int findSubstring(string s){
    vector<int> map(128,0);
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int d; //the length of substring

    for() { /* initialize the hash map here */ }

    while(end<s.size()){

        if(map[s[end++]]-- ?){  /* modify counter here */ }

        while(/* counter condition */){

            /* update d here if finding minimum*/

            //increase begin to make it invalid/valid again

            if(map[s[begin++]]++ ?){ /*modify counter here*/ }
        }  

        /* update d here if finding maximum*/
    }
    return d;
}
```

## 79.word search

思路：bfs

## 91.decode ways

思路：iterative, (recursive search from back to front?)

## 94.binaty tree inorder traversal

思路：use iterative instead of recursive.
注：递归和迭代的运行时间是一样的，只是递归用到系统内存的栈，迭代使用数据结构的栈。

## all. use iterative to deal with binary tree

## 121. best time to sell stocks

思路： dp

## 124. binary tree maximum path sum

## 134. gas station can complete circle

## 最小圆覆盖

平面上有n个点，给定n个点的坐标，试找一个半径最小的圆，将n个点全部包围，点可以在圆上, 这个圆叫最小包围圆, 求出求出这个圆的圆心坐标和半径。
