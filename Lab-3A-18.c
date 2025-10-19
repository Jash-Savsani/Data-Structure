#include<stdio.h>
void main()
{
	int n,i,sum=0;
	float ans;
	printf("Enter Last Number of the Series:");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		sum+=i;
	}
	ans = (sum/n);
	printf("Average : %f",ans);
}
