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

Write a method that returns all subsets of a set.

译文：

写一个函数返回一个集合中的所有子集。

解答
对于一个集合，它的子集一共有2^n 个(包括空集和它本身)。它的任何一个子集， 我们都可以理解为这个集合本身的每个元素是否出现而形成的一个序列。比如说， 对于集合{1, 2, 3}，空集表示一个元素都没出现，对应{0, 0, 0}； 子集{1, 3}，表示元素2没出现(用0表示)，1，3出现了(用1表示)，所以它对应 {1, 0, 1}。这样一来，我们发现，{1, 2, 3}的所有子集可以用二进制数000到111 的8个数来指示。泛化一下，如果一个集合有n个元素，那么它可以用0到2^n -1 总共2^n 个数的二进制形式来指示。每次我们只需要检查某个二进制数的哪一位为1， 就把对应的元素加入到这个子集就OK。代码如下

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
            if(j&1){//对应哪一位
                subset.push_back(a[idx]);
            }
            j >>= 1;
            ++idx;
        }
        subsets.push_back(subset);
    }
    return subsets;
}
