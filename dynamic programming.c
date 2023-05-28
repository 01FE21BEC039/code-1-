#include<stdio.h>
Int fibonacci(int n)
{
    Int fib[n+1];
Fib[0]=0;
Fib[1]=1;
For(int I=2;I<=n,I++)
{
    Fib[I]=fib[I-1]+fib[I-1];
  Return fib[n];
}
Int main()
{
  Int n=10;
Int result=fibonacci(n);
Printf(“the %dth fibonacci number is:%d\n”,n,result);
Return 0;
}
