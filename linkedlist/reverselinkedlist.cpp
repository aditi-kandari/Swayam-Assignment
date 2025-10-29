//reverse linked list

//Brute Force
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    vector<int> v;
    for (auto p = head; p; p = p->next) v.push_back(p->val);
    for (auto p = head; p; p = p->next) {
        p->val = v.back();
        v.pop_back();
    }
    return head;
}
