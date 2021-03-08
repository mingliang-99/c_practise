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

Imagine a robot sitting on the upper left hand corner of an NxN grid. The robot can only move in two directions: right and down. How many possible paths are there for the robot?

FOLLOW UP

Imagine certain squares are “off limits”, such that the robot can not step on them. Design an algorithm to get all possible paths for the robot.

译文：

在一个N*N矩阵的左上角坐着一个机器人，它只能向右运动或向下运动。那么， 机器人运动到右下角一共有多少种可能的路径？

进一步地，

如果对于其中的一些格子，机器人是不能踏上去的。设计一种算法来获得所有可能的路径。

解答
为了一般化这个问题，我们假设这个矩阵是m*n的，左上角的格子是(1, 1)， 右下角的坐标是(m, n)。

解法一

这个题目可以递归来解，如何递归呢？首先，我们需要一个递推公式， 对于矩阵中的格子(i, j)，假设从(1, 1)到它的路径数量为path(i, j)， 那么，有：

//1 .保存路径的个数；
ll path(ll m, ll n){
    if(m == 1 || n == 1) return 1;
    else return path(m-1, n) + path(m, n-1);
}

让我们先来考虑简单一点的问题，如果我们只要输出它其中一条可行的路径即可， 那么我们可以从终点(m, n)开始回溯，遇到可走的格子就入栈， 如果没有格子能到达当前格子，当前格子则出栈。最后到达(1, 1)时， 栈中正好保存了一条可行路径
//2.找到一个可行的路径
bool get_path(int m, int n){
    point p; p.x=n; p.y=m;
    sp.push(p);
    if(n==1 && m==1) return true;
    bool suc = false;
    if(m>1 && g[m-1][n])
        suc = get_path(m-1, n);
    if(!suc && n>1 && g[m][n-1])
        suc = get_path(m, n-1);
    if(!suc) sp.pop();
    return suc;
}

//3.找到所有的路径
/*
 开始，如果某个格子可以走， 我们就将它保存到路径数组中；如果不能走，则回溯到上一个格子， 继续选择向右或者向下走。当机器人走到右下角的格子(M, N)时，即可输出一条路径。 然后程序会退出递归，回到上一个格子，找寻下一条可行路径
 */
void print_paths(int m, int n, int M, int N, int len){
    if(g[m][n] == 0) return;
    point p; p.x=n; p.y=m;
    vp[len++] = p;//数组保存路径
    if(m == M && n == N){
        for(int i=0; i<len; ++i)
            cout<<"("<<vp[i].y<<", "<<vp[i].x<<")"<<" ";
        cout<<endl;
    }
    else{
        print_paths(m, n+1, M, N, len);
        print_paths(m+1, n, M, N, len);
    }
}
