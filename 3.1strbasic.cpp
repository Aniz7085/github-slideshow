#include<iostream>
#define maxSize 100

typedef struct//定长存储结构
{
    char str[maxSize + 1];
    int length;
} Str;

int strAssign(Str& str,char *ch)//赋值操作
{
    if(str.ch)
        free(str.ch);
    int len = 0;
    char *c = ch;
    while(*c)
    {
        ++len;
        ++c;
    }
    if(len == 0)
    {
        str.ch = NULL;
        str.length = 0;
        return 1;
    }
    else
    {
        str.ch(char *) malloc(sizeof(char));
        if (str.ch == NULL)
            return 0;
        else
        {
            c = ch;
            for (int i = 0; i <= len;++i,++c)
                str.ch[i] = *c;
            str.length = len;
            return 1;
        }
    }
}

int strLength(Str str)
{
    return str.length;
}

