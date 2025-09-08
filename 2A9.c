//power of num using loop
#include<stdio.h>
void main()
{
    int b,p,ans=1;
    printf("Enter a Base:");
    scanf("%d",&b);
    printf("Enter a Power:");
    scanf("%d",&p);
    for(int i=1;i<=p;i++){
        ans*=b;
    }
    printf("Answer:%d",ans);
}