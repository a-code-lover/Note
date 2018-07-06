# 错误汇总

## 1

+ sizeof: return the sizes of Byte，size：return the sizes of element，

+ operator []: no array bounds check, the program would crash while running, use at() in class vector would check the bounds while compiling.

+ mind the difference between int []a and int a[]

+ get out_of_range many many times

+ by adding "cout" in some critical points of unsure programs to debug.

+ be concentrated, mistake of a num or letter can cause sevious consumption of debugging time.

## 2.leetcode mistake

### (1)"variable length array bound evaluates to non-positive value 0"

    without consideration the condition that the size of array is 0.

### (2)"Warning: operation on 'i' may be undefined, -Wsequence-point"

    func(i++)+func1(i),the operation order of two function is undefined, so.

### (3) "CompileError: expected unqualified -id before string constant"

    missing colon after a class definition, missing {} or ()

+ "Warning: Comparison between signed and unsigned integer expressions": note that every warning may cause fatal error, syntax warning but logic error.  
    for (int i = 0; i < s.size() - 1; ++i) {}  
while s.size() equals to 0, this cause running error.  
    for (int i = 0; (int)i < s.size() - 1; ++i) {}

+ "Runtime Error:  access within null pointer of type 'struct ListNode'": access data member or function member of a null pointer.

+ "CompileError: Line 9: 'bool operator<(const ListNode*, const ListNode*)' must have an argument of class or enumerated type".

+ "Runtime Error: double free or corruption (out): 0x00000000011abe70 ***" : <https://www.cnblogs.com/zhenjing/archive/2011/01/26/memory_overwrite.html>

## 3.project mistake

"error C3646:未知重写声明符"：[循环引用，顺序错误，语法错误](https://blog.csdn.net/biubiu741/article/details/54958861)

## 4.使用临时变量构建链表，返回临时变量地址。

```c++
//merge k sorted lists
bool operator< (const ListNode a, const ListNode b) {
    return a.val > b.val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //q内的变量都是拷贝进来的，分配queue的内存，属于临时变量。
        priority_queue<ListNode> q;
        ListNode head(0), *cur = &head;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                q.push(*lists[i]);
            }
        }
        while (!q.empty()) {
            //每次分配的tmp地址是一样的，都是q的top地址。
            ListNode tmp = (ListNode)q.top();
            cur->next = &tmp;  
            q.pop();
            cur = &tmp;
            if (tmp.next != NULL) q.push(*tmp.next);
        }
        return head.next;
    }
};
```