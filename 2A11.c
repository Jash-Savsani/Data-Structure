//factors of given numbers  6=1 2 3 6
#include<stdio.h>
void main()
{
    int n;
    printf("Enter Number:");
    scanf("%d",&n);
    printf("Factors of %d is: 1, %d,",n,n);
    for(int i=2;i<n;i++){
        if(n%i==0){
            printf("%d, ",i);

        }
    }
}