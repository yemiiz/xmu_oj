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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 这个函数需要你补充完整
    ListNode *p1 = l1, *p2 = l2, *head1 = NULL;
    int num1 = 0;
    int num2 = 0;
    while (p1 != NULL)
    {
        num1 *= 10;
        num1 += p1->val;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        num2 *= 10;
        num2 += p2->val;
        p2 = p2->next;
    }
    int sum = num1 + num2;
    while (sum)
    {
        ListNode *n1 = new ListNode();
        int temp = sum % 10;
        n1->val = temp;
        if (head1 == NULL)
        {
            head1 = n1;
        }
        else
        {
            n1->next = head1;
            head1 = n1;
        }
        sum /= 10;
    }

    return head1;
}
