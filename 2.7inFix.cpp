#include<iostream>
#include<math.h>
#define maxSize 100
#define MIN 0.000000001
int getPriority(char op)
{
    if(op == '+'|| op == '-')
        return 0;
    else
        return 1;
}

int calSub(float opand1,char op,float opand2,float &result)
{
    if (op == '+')
        result = opand1 + opand2;
    if(op == '-')
        result = opand1 - opand2;
    if(op == '*')
        result = opand1 * opand2;
    if(op == '/') //除数不能为0
    {
        if(fabs(opand2)<MIN)//，fabs()求绝对值，MIN几乎可以视为0
        {
            return 0;
        }
        else
        {
            result = opand1 / opand2;
        }
    }
    return 1;
}

int calStackTopTwo(float s1[],int &top1,char s2[],int &top2)
{
    float opnd1, opnd2, result;
    char op;
    int flag;

    opnd2 = s1[top1--];
    opnd1 = s1[top1--];
    op = s2[top2--];
    flag = calSub(opnd1, op, opnd2, result);
    if(flag == 0)
    {
        std::cout << "ERROR" << std::endl; //puts("ERROR");
        s1[++top1] = result;
        return flag;
    }
    
}
//需要处理有括号的栈
 float calInfix(char exp[])//中缀表达式
{
    float s1[maxSize];//数组栈
    int top1 = -1;
    char s2[maxSize];//运算符栈
    int top2 = -1;
    int i = 0;
    while(exp[i]!='\0')//当表达式不为0
    {
        if('0'<= exp[i]&&exp[i] <='9')
        {
            s1[++top1] = exp[i] - '0';
            ++i;
        } //字符转数值;'0'=a,'3'-'0'=a+3 - a
        else if(exp[i] == '+'||
                exp[i] == '-'|| 
                exp[i] == '*'||
                exp[i] == '/')
        {
            if(top2==-1 ||s2[top2]=='(' || 
            getPriority(exp[i])>getPriority(s2[top2]))  //入栈
            {
            s2[++top2] = exp[i];
            ++i;
            }
            else
            {
            int flag = calStackTopTwo(s1, top1, s2, top2);
            if(flag == 0)
                return 0;
            }
        }
        else if (exp[i] == ')') //出栈
        {
            while (s2[top2] != '(')
            {
                int flag = calStackTopTwo(s1, top1, s2, top2);
                if(flag == 0)
                    return 0;
            }
            --top2;
            ++i;
        }
    }

    while (top2 != -1)
    {
        int flag = calStackTopTwo(s1, top1, s2, top2);
        if (flag == 0)
            return 0;
    }
    return s1[top1];
}
