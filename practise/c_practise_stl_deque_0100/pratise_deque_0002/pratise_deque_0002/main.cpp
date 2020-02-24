//
//  main.cpp
//  pratise_deque_0002
//
//  Created by mingliang8 on 2020/2/24.
//  Copyright © 2020 mingliang8. All rights reserved.
//

#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
    deque<int> a;
    // 在末尾插入数据
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    // 在开头插入数据
    a.push_front(2);
    a.push_front(1);
    a.push_front(0);
    // 以数组方式输出
    for (size_t n = 0; n < a.size(); ++n)
        cout << "a[" << n << "] = " << a[n] << endl;

    cout << endl;
    
    //删除双端队列中最后一个元素
    a.pop_back();
    //删除双端队列中最前一个元素
    a.pop_front();
    
    
    // 以迭代器方式输出
    deque<int>::iterator iter;
    for (iter = a.begin(); iter < a.end(); ++iter)
    {
        // 计算数组下标，distance包含在algorithm中
        int index = distance(a.begin(), iter);
        cout << "a[" << index << "] = " << *iter << endl;
    }

    cout << "a.size =" << a.size() << " \n deque clear " << endl;
    //队列清楚
    a.clear();
    
    //判断空
    if(a.empty()){
           cout << "deque is null a.size =" << a.size() << endl;
    }
    system("pause");
    return 0;
}

/*
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/
