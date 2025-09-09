//check num is prime
#include<stdio.h>
void main()
{
    int n;
    printf("Enter a Number:");
    scanf("%d",&n);
    int temp=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            temp=1;
            break;
        }
    }
    if(temp==0){
        printf("%d is Prime Number.",n);
    }
    else{
        printf("%d is not Prime Number.",n);
    }
}