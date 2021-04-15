#include "SString.h"

void SString_test()
{
    SString::SString<char> mystring;
    SString::SString<char> mystring1;
    SString::SString<char> mystring2;
    mystring.InitSString("", 0);
    mystring1.InitSString("abcd", 4);
    mystring2.InitSString("efgh", 4);

    //mystring.StrCopy(mystring, mystring1);
    //if (mystring.StrEmpty(mystring))cout << "空\n"<< endl;
    /*int result = mystring.StrCompare(mystring, mystring1);
    switch (result)
    {
    case 0:
        cout << "两字符串相等\n"
             << endl;
        break;
    case -1:
        cout << "2字符串大\n"
             << endl;
    case 1:
        cout << "1字符串大\n"
             << endl;
    default:
        break;
    }*/
    //int result = mystring.StrLength(mystring);
    //cout << "字符串长度为：" << result << endl;
    //mystring.StrConcat(mystring, mystring1, mystring2);
    mystring1.PrintSString(mystring1);
}