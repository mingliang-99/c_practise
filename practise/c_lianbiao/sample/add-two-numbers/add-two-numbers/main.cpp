//
//  main.cpp
//  add-two-numbers
//
//  Created by mingliang on 2021/1/4.
//

#include <iostream>

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

ListNode *add_two_numbers(ListNode *l1, ListNode *l2){
    ListNode *head = nullptr, *tail = nullptr;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val: 0;
        int n2 = l2 ? l2->val: 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = new ListNode(sum % 10);
        } else {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
