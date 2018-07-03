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

            if(map[s[begin++]]++ ?){ /*modify counter here*/ }
        }  

        /* update d here if finding maximum*/
    }
    return d;
}
```

## 79.word search

思路：bfs