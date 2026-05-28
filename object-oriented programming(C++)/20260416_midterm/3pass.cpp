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

        p1 = new ListNode;

        cin >> p1->val;
    }

    p2->next = NULL;

    delete p1;

    return head;
}

ListNode *getIntersection(ListNode *head1, ListNode *head2)

{
    ListNode dummy;
    ListNode *head = &dummy;
    ListNode *p1 = head1, *p2 = head2;
    while (p1)
    {
        while (p2)
        {
            p2 = p2->next;
            if (p1->val == p2->val)
            {
                ListNode *p = new ListNode;
                p->val = p1->val;
                head->next = p;
                head = p;
                p2 = head2;
            }
        }

        p2 = head2;
        p1 = p1->next;
    }
    return dummy.next;
}
#include <vector>
ListNode *getIntersection(ListNode *head1, ListNode *head2)

{
    ListNode *head = NULL, *p2;
    vector<int> v1, v2;
    while(head1)
    {
        v1.push_back(head1->val);
        head1 = head1->next;
    }
    while (head2)
    {
        v2.push_back(head2->val);
        head2 = head2->next;
    }
    for(auto num1:v1)
    {
        for(auto num2:v2)
        {
            if(num1 == num2)
            {
                ListNode *p1 = new ListNode;
                p1->val = num1;
                if(head==NULL)
                {
                    head = p1;
                    p2 = p1;
                }
                else
                {
                    p2->next = p1;
                    p2 = p1;
                }
            }
        }
    }
    return head;
}
int main()

{

    ListNode *head1 = createList();

    ListNode *head2 = createList();

    ListNode *ans = getIntersection(head1, head2);

    if (ans == NULL)

    {

        cout << "NULL";

        return 0;
    }

    while (ans != NULL)

    {

        cout << ans->val;

        if (ans->next != NULL)
            cout << " ";

        ans = ans->next;
    }

    return 0;
}