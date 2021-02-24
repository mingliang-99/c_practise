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
题目
原文：

In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one rod onto the next rod.
A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to the last using Stacks

译文：

编程解决汉诺塔问题，使用数据结构栈(偷个懒，如果不知道汉诺塔是什么，请自行Google)

解答
汉诺塔是个非常经典的问题，讲递归时应该都会讲到它。如果我们没有递归的先验知识， 直接去解答这道题，常常会觉得不知道如何下手。用递归却可以非常优美地解决这个问题


