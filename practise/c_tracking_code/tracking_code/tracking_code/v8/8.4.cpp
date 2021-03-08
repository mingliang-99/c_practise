//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>
题目
原文：

Write a method to compute all permutations of a string

译文：

写一个函数返回一个串的所有排列

解答
对于一个长度为n的串，它的全排列共有A(n, n)=n!种。这个问题也是一个递归的问题， 不过我们可以用不同的思路去理解它。为了方便讲解，假设我们要考察的串是”abc”， 递归函数名叫permu

思路一：

我们可以把串“abc”中的第0个字符a取出来，然后递归调用permu计算剩余的串“bc” 的排列，得到{bc, cb}。然后再将字符a插入这两个串中的任何一个空位(插空法)， 得到最终所有的排列。比如，a插入串bc的所有(3个)空位，得到{abc,bac,bca}。 递归的终止条件是什么呢？当一个串为空，就无法再取出其中的第0个字符了， 所以此时返回一个空的排列。代码如下：

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
vvi get_subsets(int a[], int n){ //O(n2^n)
    vvi subsets;
    int max = 1<<n;
    for(int i=0; i<max; ++i){
        vi subset;
        int idx = 0;
        int j = i;
        while(j > 0){
            if(j&1){
                subset.push_back(a[idx]);
            }
            j >>= 1;
            ++idx;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

