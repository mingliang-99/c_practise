//
//  main.cpp
//  gong-gong-jie-dian
//
//  Created by mingliang on 2021/1/4.
//

#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode * gong_gong_jie_dian(ListNode *head1, ListNode *head2)
{
    if (!head1 || !head2) {
        return NULL;
    }
    
    /* 求出两个链表的长度 */
    ListNode *p1, *p2;
    p1 = head1;
    p2 = head2;
    int len1, len2, len;
    len1 = len2 = 0;
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    
    /* 将长链表先移动len个结点 */
    int i;
    len = abs(len1 - len2);
    p1 = head1;
    p2 = head2;
    if (len1 > len2) {
        for (i = 0; i < len; ++i) {
            p1 = p1->next;
        }
    } else {
        for (i = 0; i < len; ++i) {
            p2 = p2->next;
        }
    }
    
    /* 遍历 找到第一个相等的结点即为交点 */
    while (!p1) {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2) {
            return p1;
        }
    }
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
