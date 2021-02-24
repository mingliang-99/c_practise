//
//  main.cpp
//  tracking_code
//
//  Created by mingliang on 2021/2/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;
/*
原文：
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
译文：
写一个函数处理一个MxN的矩阵，如果矩阵中某个元素为0，那么把它所在的行和列都置为0
 
思路：

遍历一次矩阵，当遇到元素等于0时，记录下这个元素对应的行和列。
可以开一个行数组row和列数组col，当元素a[i][j]等于0时，
就把row[i]和col[j]置为true。
第二次遍历矩阵时，当某个元素对应的行row[i] 或列col[j]被设置为true，
说明该元素在需要被置0的行或列上，因此将它置0
 
*/


void zero(int **a, int m, int n){
    bool row[m], col[n];
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(a[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(row[i] || col[j])
                a[i][j] = 0;
}
int main()
{
    freopen("1.7.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    int **a;
    a = new int*[m];
    for(int i=0; i<m; ++i)
        a[i] = new int[n];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>a[i][j];
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    zero(a, m, n);
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    fclose(stdin);
    return 0;
}
