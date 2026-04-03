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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);// 这个函数需要你补充完整


int main()
{
    ListNode *head1, *head2;
    head1 = createList();
    head2 = createList();
    ListNode *ans = addTwoNumbers(head1, head2);
    if (ans == NULL)
        cout << "-1";
    else
    {
        while (ans != NULL)
        {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << -1;
    }
    return 0;
}



//函数实现
// 反转链表的函数
ListNode *reverse(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *cur = head;
    while (cur != NULL)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *p1 = l1, *p2 = l2, *head = NULL, *tail = NULL;
    int c = 0;
    while (p1 != NULL || p2 != NULL || c != 0)
    {
        int a = 0;
        if (p1 != NULL)
        {
            a = p1->val;
            p1 = p1->next;
        }
        int b = 0;
        if (p2 != NULL)
        {
            b = p2->val;
            p2 = p2->next;
        }
        int s = a + b + c;
        c = s / 10;
        int cur = s % 10;

        ListNode *node = new ListNode();
        node->val = cur;
        node->next = NULL;

        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }
    head = reverse(head);
    return head;
}