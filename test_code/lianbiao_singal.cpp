//
//  main.cpp
//  ACM
//
//  Created by yangmingliang on 16/9/4.
//  Copyright © 2016年 yangmingliang. All rights reserved.
/************************** 题解 **********************
链表题目集合
 
 ************************* 题解 ***********************/
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define LYTEST  1
/************************** 最小子模块 **********************

  //链表基本操作
 ************************* 最小子模块 ***********************/

struct stu_node
{
    int num;
    char name[20];
    int score;
    struct stu_node *next;
} ;

/*
 插入指定节点的后面（此例是指定学号的节点）
 */
struct stu_node *insert(struct stu_node *head, int num)
{
    struct stu_node *p;
    p=head;       // 指针p指向第一个节点
    struct stu_node *s=(struct stu_node *)malloc(sizof(struct stu_node));    //  待插入的结点s
    if(head==NULL)
    {
        head=s;
        s->next=NULL;  //当链表为空时，新节点作为头结点插入
        return head;
    }
    else
    {
        while(p->num!=num&&p->next!=NULL)//p指向的结点不是所查找的，并且不是最后一个结点，继续往下找
        {
            p=p->next;
            if(p->num == num){
                /*找到了想要插入的位置*/
                s->next=p->next;
                p->next=s;
            }
            return head;
        }
        
    }
}
    
    



