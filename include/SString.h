#ifndef _SSTRING_H_
#define _SSTRING_H_

#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

#define MAXSTRLEN 20 //设定串最大长度

namespace SString
{
    template <typename ElemType>
    class SString
    {
    private:
        ElemType data[MAXSTRLEN + 1]; //数组元素
        int lenght;                   //长度

    public:
        SString();                                                  //构造函数，初始化串
        void InitSString(const char *S);                            //初始化串
        void PrintSString(SString &S);                              //打印串
        bool StrCopy(SString &S, SString &T);                       //串拷贝
        bool StrEmpty(SString &S);                                  //判空
        int StrCompare(SString &S, SString &T);                     //串比较
        int StrLength(SString &S);                                  //求串长
        void StrConcat(SString &S, SString &S1, SString &S2);       //连接字符串
        void SubString(SString &S, SString &sub, int pos, int len); //求子串
        void StrInsert(SString &S, int pos, SString &T);            //指定位置插入字符串
        void StrDelete(SString &S, int pos, int len);               //删除指定位置指定长度字符串
        void StrClear(SString &S);                                  //串清除
        int StrIndex(SString &S, SString &T, int pos);              //
        void StrReplace(SString &S, SString &T, SString &V);
    };
} // namespace SString

template <typename ElemType>
SString::SString<ElemType>::SString()
{
    data[0] = '\0';
    lenght = 0;
}

template <typename ElemType>
void SString::SString<ElemType>::InitSString(const char *S)
{
    int i = 0;
    while (S[i] != '\0')
    {
        data[i++] = S[i];
        lenght++;
    }
    data[lenght] = '\0';
}

template <typename ElemType>
void SString::SString<ElemType>::PrintSString(SString &S)
{
    for (int i = 0; S.data[i] != '\0'; i++)
    {
        std::cout << S.data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename ElemType>
bool SString::SString<ElemType>::StrCopy(SString &S, SString &T)
{
    for (int i = 0; i < T.lenght; ++i)
    {
        S.data[i] = T.data[i];
    }
    S.data[T.lenght] = '\0';
    return true;
}

template <typename ElemType>
bool SString::SString<ElemType>::StrEmpty(SString &S)
{
    if (S.lenght == 0)
    {
        return true;
    }
    return false;
}

template <typename ElemType>
int SString::SString<ElemType>::StrCompare(SString &S, SString &T)
{
    int i = 0;
    int result = 0;
    while (S.data[i] != '\0' && T.data[i] != '\0')
    {
        result = S.data[i] - T.data[i];
        if (result != 0)
        {
            break;
        }
        i++;
    }
    if (result == 0)
        return 0;
    else if (result > 0)
        return 1;
    else
        return -1;
}

template <typename ElemType>
int SString::SString<ElemType>::StrLength(SString &S)
{
    return S.lenght;
}

template <typename ElemType>
void SString::SString<ElemType>::StrConcat(SString &S, SString &S1, SString &S2)
{
    int i = 0;
    while (S1.data[i] != '\0')
    {
        S.data[i] = S1.data[i];
        i++;
    }
    int j = 0;
    while (S2.data[j] != '\0')
    {
        S.data[i + j] = S2.data[j];
        j++;
    }
    S.data[i + j] = '\0';
}

#endif // _SSTRING_H_