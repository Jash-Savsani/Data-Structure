/*3Sum in Array ans=0*/
#include<stdio.h>
void main()
{
	int i,j,k,n,n2=0;
	int *p1,*p2,*p3;
	printf("Enter Number of Size Of Array:");
	scanf("%d",&n);
	int a[n];
	p1=a;
	p2=a;
	p3=a;
	for(i=0;i<n;i++){
		printf("Enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if((i<j) && (j<k)){ 
					if(*(p1+i) + *(p2+j) + *(p3+k) == 0){
						printf("Answer: (%d + %d + %d)=0\n",*(p1+i),*(p2+j),*(p3+k));
						n2=1;
					}
				}
			}
		}
	}
	if(n2==0){
		printf("Not Group of Three Element Available For Sum of 0.");
	}
}
	
