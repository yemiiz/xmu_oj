#include <iostream>

#include <string>

using namespace std;

struct CharNode
{

    char val;

    CharNode *next;

    CharNode(char c) : val(c), next(NULL) {}
};

// 将字符串转为链表

CharNode *StringToList(const string &str)
{

    CharNode dummy(0);

    CharNode *tail = &dummy;

    for (int i = 0; i < str.size(); ++i)
    {

        CharNode *newNode = new CharNode(str[i]);

        tail->next = newNode;

        tail = newNode;
    }

    return dummy.next;
}

// 获取链表长度

int ListLength(CharNode *head)
{

    int length = 0;

    while (head)
    {

        length++;

        head = head->next;
    }

    return length;
}

// 链表转为字符串

string ListToString(CharNode *head)
{

    string result = "";

    while (head)
    {

        result += head->val;

        head = head->next;
    }

    return result;
}

// 释放链表内存

void FreeList(CharNode *head)
{

    while (head)
    {

        CharNode *temp = head;

        head = head->next;

        delete temp;
    }
}

// 左旋操作

CharNode *LeftRotate(CharNode *head, int n)
{
    CharNode *p = head;
    string str1,str2;
    CharNode *head1=NULL, *p2;
    for (int i = 0; i < n;i++)
    {
        
        str1 += p->val;
        p = p->next;
    }
    while(p)
    {
        str2 += p->val;
        p = p->next;
    }
    str2 += str1;
    for(char c:str2)
    {
        CharNode *p1 = new CharNode(c);
        if(head1==NULL)
        {
            head1 = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }

    }
    p2->next = NULL;
    return head1;
}

int main()
{

    string s;

    getline(cin, s); // 读取带引号的字符串，比如 "abcdefg"

    s = s.substr(1, s.size() - 2); // 去掉前后的引号

    string n_str;

    getline(cin, n_str); // 读取数字 n

    int n = stoi(n_str); // 转换为整数

    // 字符串 → 链表

    CharNode *head = StringToList(s);

    // 左旋操作

    CharNode *rotated = LeftRotate(head, n);

    // 输出结果

    cout << ListToString(rotated) << endl;

    // 清理内存

    FreeList(rotated);

    return 0;
}