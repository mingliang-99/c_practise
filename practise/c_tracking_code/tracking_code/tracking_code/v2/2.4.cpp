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

原文：

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE

Input: (3 -> 1 -> 5), (5 -> 9 -> 2)

Output: 8 -> 0 -> 8

译文：

你有两个由单链表表示的数。每个结点代表其中的一位数字。数字的存储是逆序的， 也就是说个位位于链表的表头。写一函数使这两个数相加并返回结果，结果也由链表表示。

例子：(3 -> 1 -> 5), (5 -> 9 -> 2)

输入：8 -> 0 -> 8



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        int sum;
        while (l1 || l2){
            sum = 0;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};

