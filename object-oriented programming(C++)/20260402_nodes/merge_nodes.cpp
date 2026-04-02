#include <iostream>

using namespace std;

struct ListNode

{

    int val;

    ListNode *next;
};
ListNode *mergeNodes(ListNode *head);        // 这个函数需要你补充完成

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

int main()
{

    ListNode *head;

    head = createList();

    ListNode *ans = mergeNodes(head);

    while (ans != NULL)

    {

        cout << ans->val << " ";

        ans = ans->next;
    }

    return 0;
}



// 函数的实现
ListNode *mergeNodes(ListNode *head)

{ 
    int cnt = 0;
    ListNode *p1 = head, *p2 = NULL, *head2 = NULL;
    while (p1 != NULL)
    {

        if (p1->val == 0)
        {
            if (cnt)
            {
                ListNode *p = new ListNode();

                p->val = cnt;
                if (head2 == NULL)
                {
                    head2 = p;
                    p2 = p;
                }
                else
                {
                    p2->next = p;
                    p2 = p;
                }
                cnt = 0;
            }
        }
        else
        {
            cnt += p1->val;
        }
        p1 = p1->next;
    }
    return head2;
}
