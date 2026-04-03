#include <iostream>

#include <sstream>

#include <string>

#include <cctype>

using namespace std;

struct ListNode
{

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {} // 在struct中也可以写构造函数，用于对数据的初始化。例如，ListNode x(5) 表示：创建结构体变量x，其中x.val为5，x.next为空。
};

// create_list函数用于从输入数据中创建链表，并返回链表头指针

ListNode *create_list(const string &s)
{

    stringstream ss(s);

    string token;

    ListNode *head = NULL;

    ListNode *tail = NULL;

    while (getline(ss, token, '-'))
    {

        while (!token.empty() && !isdigit(token[0]))
        { // 删除非数字的字符

            token.erase(token.begin());
        }

        if (token.empty() || token == "NULL")
            continue;

        int num = stoi(token);

        ListNode *node = new ListNode(num);

        if (!head)
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

    return head;
}

ListNode *delete_duplicates(ListNode *head);

// print_list函数用于将链表打印出来

void print_list(ListNode *head)
{

    ListNode *cur = head;

    while (cur)
    {

        cout << cur->val;

        if (cur->next)
            cout << "->";

        cur = cur->next;
    }

    cout << "->NULL" << endl;
}

int main()
{

    string list_str;

    getline(cin, list_str); // 从输入中读取一整行数据到list_str中

    ListNode *head = create_list(list_str);

    ListNode *new_head = delete_duplicates(head);

    print_list(new_head);

    return 0;

}




// 函数实现
ListNode *delete_duplicates(ListNode *head)
{
    ListNode *p = head, *head2 = NULL, *p2;
    while (p != NULL)
    {
        bool isduplicate = false;

        while (p != NULL && p->next != NULL && p->val == p->next->val)  
        /*
        顺序必须是p!=NULL && p->next!=NULL && p->val==p->next->val
        如果顺序是p->val==p->next->val && p!=NULL && p->next!=NULL
        当p为NULL时，p->val会导致程序崩溃
        
        */
        {
            isduplicate = true;
            p = p->next;
        }

        if (!isduplicate)
        {
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
        }

        p = p->next;
    }

    if (p2 != NULL)
        p2->next = NULL;

    return head2;
}
