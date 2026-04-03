#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *createList()
{
    ListNode *head = NULL;
    ListNode *p1, *p2;
    p1 = new ListNode;
    p2 = p1;
    cin >> p1->val;
    while (p1->val != -1)
    {
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = new struct ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

int isPalindrome(ListNode *head); // 这个函数需要你补充完整

int main()
{
    ListNode *head;
    head = createList();
    int ans = isPalindrome(head);
    cout << ans << '\n';
    return 0;
}



//函数实现
#include <vector>
#include <algorithm>
int isPalindrome(ListNode *head)
{
    // 这个函数需要你补充完整
    if (head == NULL)
    {
        return -1;
    }
    ListNode *p = head;
    vector<int> v;
    int cnt = 0;
    while (p != NULL)
    {
        v.push_back(p->val);
        p = p->next;
    }
    vector<int> v2 = v;
    reverse(v.begin(), v.end());
    if (v2 == v)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}