#include<stdio.h>
void main()
{
	int i,j,k,n,*ptr1,*ptr2;
	printf("Enter last Number For Pattern:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ptr2 = (int*) malloc ((i+1) * sizeof(int));
		ptr2[0]=1;
		ptr2[i]=1;
		if(i>=2)
		{
			for(j=0;j<i-1;j++)
			{
				ptr2[1+j] = ptr1[j] + ptr1[1+j];
			}
		}
		for(k=n-i-1;k>=1;k--)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%d ",ptr2[j]);
		}
		printf("\n");
		if(i>=1)
		{
			ptr1 = (int*) malloc ((i+1) * sizeof(int));
			for(j=0;j<i+1;j++)
			{
				ptr1[j]=ptr2[j];	
			}	
		}
	}
	free(ptr1);
	free(ptr2);
}
