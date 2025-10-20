/*
47. Write a menu driven program to implement following operations on a circular 
queue using an Array 
• Insert 
• Delete 
• Display all elements of the queue
*/
#include<stdio.h>//baaki che.
#define n 5
int f=-1,r=-1;
int circular_queue[n];
void enqueue(int y){
	if(((r+1)%n) == f){
		printf("Circular Queue is Full.\n");
		return;
	}
	r = (r+1)%n;
	circular_queue[r] = y;
	if(f == -1){
		f++;
	}
	return;	
}
int dequeue(){
	if(f==-1){
		printf("Circular Queue is Empty.\n");
		return -1;
	}
	int y = circular_queue[f];
	if(f == r){
		f=-1;
		r=-1;
	}else{
		f = (f+1)%n;
	}
	return y;
}
void display(){
	if(f==-1){
		printf("Queue is Empty.\n");
		return;
	}
	int i;
	printf("\nCircular Queue Elements: ");
	for(i=f;i!=r;i=(i+1)%n){
		printf("%d ,",circular_queue[i]);
	}printf("%d ",circular_queue[r]);
	printf("\n"); 
}
void main(){
	int i,n2;
	printf("1.Enqueue\n2.Dequeue\n3.Display\n\n");
	printf("Enter -1 to Break a Loop.\n");
	while(1){
		printf("Enter Your Choise:");
		scanf("%d",&i);
		if(i==-1)
			break;
		switch(i){
			case 1:printf("\nEnter Number for Enqueue:");
					scanf("%d",&n2);
					enqueue(n2);
					break;
			case 2: n2 = dequeue();
					printf("\nDequeue Number is : %d\n",n2);
					break;
			case 3: display();
		}
	}
}
