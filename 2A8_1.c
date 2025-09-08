//using loop for factorial
#include<stdio.h>
void main()
{
    int n,ans=1;
    printf("Enter Number:");
    scanf("%d",&n);
    for(int i=n;i>=1;i--){
        ans*=i;
    }
    printf("Answer:%d",ans);
}