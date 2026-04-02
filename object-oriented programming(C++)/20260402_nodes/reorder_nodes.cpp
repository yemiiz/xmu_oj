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

ListNode *oddEvenList(ListNode *head); // 这个函数需要你补充完整

int main()

{

    ListNode *head;

    head = createList();

    ListNode *ans = oddEvenList(head);

    if (ans == NULL)

        cout << "-1";

    else

    {

        while (ans != NULL)

        {

            cout << ans->val << " ";

            ans = ans->next;
        }
    }

    return 0;
}





// 函数实现
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *odd = head;         // 1, 3, 5, ... 
    ListNode *even = head->next;   // 2, 4, 6, ...
    //分成两个部分最后奇数的尾接偶数的头
    ListNode *evenHead = even;     

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;   //1->3->5    
        odd = odd->next;          //odd变为2准备接下一个奇数3

        even->next = odd->next;   //2->4->6
        even = even->next;        //even变为3准备接下一个偶数4
    }

    odd->next = evenHead;         // 5->2  

    return head;
}