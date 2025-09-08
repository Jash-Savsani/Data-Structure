//using recursion for factorial
#include<stdio.h>
int fact(int n){
    if(n<=1){
        return 1;
    }
    return n*fact(n-1);
}
void main()
{
    int n,f;
    printf("Enter Number:");
    scanf("%d",&n);
    f=fact(n);
    printf("Factorial of %d is %d.",n,f);
}