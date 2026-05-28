#pragma once

class MyString
{
public:
    int myStat(char *const input); // 统计输入字符串中的英文字母个数

    char *myConcat(char *const left, char *const right);    //将输入的两个字符串连接起来。

    void myUpper(char *input);
    void myLower(char *input);
    // 分别将输入字符串中的每个字母都改为大写、或都改为小写。

    void myEncode(char *input);
    void myDecode(char *input);
    // 分别将输入的字符串进行加密、解密。
    //加密原则：将每个字符的ASCII码加上8。（解密原则与加密相反）

    
};