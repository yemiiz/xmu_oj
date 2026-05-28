#include <iostream>

#include <string>

using namespace std;

struct CharNode
{

    char val;

    CharNode *next;

    CharNode(char c) : val(c), next(NULL) {} // struct中的构造函数，用于对结点的初始化
};

// StringToList函数将字符串（string类）转化为链表，该函数返回链表的头指针

CharNode *StringToList(const string &str)
{

    CharNode dummy(0);

    CharNode *tail = &dummy;

    for (int i = 0; i < str.size(); ++i)
    {

        char c = str[i];

        CharNode *newNode = new CharNode(c);

        tail->next = newNode;

        tail = newNode;
    }

    return dummy.next;
}

// FreeList函数清理链表

void FreeList(CharNode *head)
{

    while (head)
    {

        CharNode *temp = head;

        head = head->next;

        delete temp;
    }
}

// StrToInt函数将链表转换为字符串（string类）

string StrToInt(CharNode *head)
{
    if(!head)
        return "0";
    else
    {
        string str;
        int found = 0;
        while(head)
        {
            if(head->val == '-')
            {
                str += '-';
            }
            if(head->val >='1' && head->val<='9')
            {
                found = 1;
            }
            if(found && head->val>='0'&&head->val<='9')
            {
                str += head->val;
            }
            head = head->next;
        }
        return str;
    }

    // 本函数需要你补充完整
}

int main()
{

    string input;

    getline(cin, input); // 从输入中读取一整行数据到input中

    if (!input.empty() && input.front() == '"')
    {

        input = input.substr(1); // 去掉输入字符串中开头的引号
    }

    if (!input.empty() && input.back() == '"')
    {

        input = input.substr(0, input.size() - 1); // 去掉输入字符串中末尾的引号
    }

    CharNode *head = StringToList(input);

    string result = StrToInt(head);

    cout << result << endl;

    FreeList(head);

    return 0;
}