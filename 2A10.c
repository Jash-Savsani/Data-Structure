//reverse num
#include<stdio.h>
void main()
{
    int n,r,ans=0;
    printf("Enter a Number:");
    scanf("%d",&n);
    while(n>0){
        r=n%10;
        ans=(ans*10)+r;
        n=n/10;
    }
    printf("Reverse Number is:%d",ans);
}