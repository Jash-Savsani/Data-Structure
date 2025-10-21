/*57. Write a menu driven program to implement following operations on the singly 
linked list.  
1. Insert a node at the front of the linked list. 
2. Display all nodes. 
3. Delete a first node of the linked list. 
4. Insert a node at the end of the linked list. 
5. Delete a last node of the linked list. 
6. Delete a node from specified position.*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node* head = NULL;
void insert_At_Beggining(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = head;
	head = newNode;
}
void insert_At_Ending(int info){
	struct node* newNode = (struct node*) malloc (sizeof(struct node));
	newNode->info = info;
	newNode->link = NULL;
	if(head == NULL){
		head = newNode;
		return;
	}
	struct node* save = head;
	while (save->link != NULL)
	{
		save = save->link;
	}
	save->link = newNode;
}
void display_AllNodes(){
	if(head==NULL){
		return;
	}
	struct node* save = head;
	while(save != NULL){
		printf("%d->", save->info);
		save = save->link;
	}
}
void delete_At_Beggining(){
	if(head==NULL){
		return;
	}
	struct node* save = head;
	head = head->link;
	save->link = NULL;//aana thi delete karvano node head ne point karto bandh karse
	free(save);//node ne memory mathi delete karel che. jethi vadhara ni memory ma space occupy thase nahi.
}
void delete_At_Ending(){
	if(head==NULL){
		return;
	}
	int count=0;
	struct node* save = head;
	struct node* pred = save;
	while(save->link != NULL){
		pred = save;
		save = save->link;
		count=1;
	}
	if(count==0){
		head = NULL;
		return;
	}
	pred->link = save->link;
	free(save);
}
void delete_At_Specify_Positon(int position){
	if(head==NULL)
	{
		return;
	}	
	int count=0;
	struct node* save = head;
	struct node* pred = save;
	position--;
	while(save->link!=NULL && position!=0){
		pred = save;
		save = save->link;
		position--;
		count++;
	}
	if(position!=0){
		printf("Delete Position is Not Found.");
	}
	else if(count==0){
		head = head->link;
	}
	pred->link = save->link;
	free(save);
}
void main()
{
	int i;
	int choise;
	printf("\n1.Insert a node at the front of the linked list.\n2. Display all nodes.\n3.Delete a first node of the linked list.\n4.Insert a node at the"): 
	printf("end of the linked list.\n5.Delete a last node of the linked list.\n6.Delete a node from specified position.");
		while(1){
		printf("\nEnter Choise Number:");
		scanf("%d",&choise);
		switch(choise){
			case 1 : printf("Enter Number:");
					scanf("%d",&i);
					insert_At_Beggining(i);
					break;
			case 2 :display_AllNodes();
					break;
			case 3 :delete_At_Beggining();
					break;
			case 4 : printf("Enter Number:");
					scanf("%d",&i);
					insert_At_Ending(i);
					break;
			case 5 :delete_At_Ending();
					break;
			case 6 :display_AllNodes();
					printf("\nEnter Which Positon To you Want to delete Node:");
					scanf("%d",&i);
					delete_At_Specify_Positon(i);
					break;
			default : return;
			}		
		}		
}	
