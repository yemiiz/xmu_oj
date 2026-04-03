#include <sstream>

#include <string>

#include <utility>

#include <iostream>
using namespace std;

// 本题使用的数据结构为双链表，每个结点都有prev和next指针，可以从链表的任意位置向前或向后遍历。使用node->prev访问node结点的前一结点，使用node->next访问node结点的后一结点。

// 头结点（链表的第一个结点）的prev指针和尾结点（最后一个结点）的next指针均为NULL。

struct ListNode
{

    string val; // string类，用于处理字符串

    ListNode *next; // 指向下一个结点的指针

    ListNode *prev; // 指向前一个结点的指针

    ListNode(string x) : val(x), prev(NULL), next(NULL) {} // struct中的构造函数，用于对链表结点的初始化
};

// buildList函数用于从输入字符串input创建链表，创建好的链表头指针存储在head中，尾指针存储在tail中

void buildList(const string &input, ListNode *&head, ListNode *&tail)
{

    if (input.empty())

    {

        head = NULL;

        tail = NULL;

        return;
    }

    // 移除结尾的 "->NULL"

    const string tail_str = "->NULL";

    string trimmedInput = input;

    if (trimmedInput.size() >= tail_str.size() && trimmedInput.substr(trimmedInput.size() - tail_str.size()) == tail_str)
    {

        trimmedInput = trimmedInput.substr(0, trimmedInput.size() - tail_str.size());
    }

    // 分割字符串并构建链表

    stringstream ss(trimmedInput);

    string item;

    ListNode *dummyHead = new ListNode("");

    ListNode *current = dummyHead;

    tail = dummyHead;

    while (getline(ss, item, '-'))
    {

        if (item.back() == '>')
        {

            item.pop_back();
        }

        if (!item.empty() && (item.front() == '>' && item.size() > 1))
        {

            item = item.substr(1);
        }

        if (!item.empty())
        {

            ListNode *newNode = new ListNode(item);

            current->next = newNode;

            newNode->prev = current;

            current = current->next;

            tail = newNode;
        }
    }

    head = dummyHead->next;

    return;
}

// findFirstCommonNode函数从两条链表（A和B）中寻找第一个公共结点，并返回指向公共结点的指针

ListNode *findFirstCommonNode(ListNode *headA, ListNode *tailA, ListNode *headB, ListNode *tailB);


int main()
{

    string lineA, lineB;

    getline(cin, lineA); // 从输入中读取一整行数据到lineA中

    getline(cin, lineB); // 从输入中读取一整行数据到lineB中

    ListNode *headA, *tailA;

    ListNode *headB, *tailB;

    headA = tailA = headB = tailB = NULL;

    buildList(lineA, headA, tailA); // 从输入数据中创建链表

    buildList(lineB, headB, tailB); // 从输入数据中创建链表

    ListNode *commonNode = findFirstCommonNode(headA, tailA, headB, tailB);

    if (commonNode != NULL)
    {

        cout << commonNode->val << endl;
    }
    else
    {

        cout << "NULL" << endl;
    }

    return 0;
}


// 函数实现
ListNode *findFirstCommonNode(ListNode *headA, ListNode *tailA, ListNode *headB, ListNode *tailB)
{

    // 本函数需要你补充完整
    // headA 链表A的头指针
    // tailA 链表A的尾指针
    // headB 链表B的头指针
    // tailB 链表B的尾指针
    // 将代码补充完整, 注意：请勿改动函数声明
    ListNode *pa = tailA, *pb = tailB;
    if (tailA->val != tailB->val)
    {
        return NULL;
    }
    while (true)
    {
        if (pa->val == pb->val)
        {
            pa = pa->prev;
            pb = pb->prev;
        }
        else
        {
            return pa->next;
        }
    }
}