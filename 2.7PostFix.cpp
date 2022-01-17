#include<iostream>
#include<math.h>
#define maxSize 100
#define MIN 0.0000001
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
 float calPostFix(char exp[])//后缀表达式
{
    float s[maxSize];//数组栈
    int top = -1;
    for (int i = 0; exp[i] != '\0';++i)//可用for循环或while循环
    {
        if('0'<=exp[i]&&exp[i]<='9')
            s[++top] = exp[i] - '0';
        else
        {
            float opnd1, opnd2, result;
            char op;
            int flag;
            opnd2 = s[top--];    
            opnd1 = s[top--];
            op = exp[i];     
           flag = calSub(opnd1, op, opnd2, result);
            if (flag == 0)      
           {   
             std::cout << "ERROR" << std::endl; //puts("ERROR");
             break;
           }
           s[++top] = result;
        }
    
    }
    return s[top];
}