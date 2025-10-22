/*74. Write a program to simulate music player application using suitable data 
structure. There is no estimation about number of music files to be managed by 
the music player. Your program should support all the basic music player 
operations to play and manage the playlist.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char s_name[50];
	struct node *lptr;
	struct node *rptr;
};
struct node *l = NULL;
struct node *r = NULL;
struct node *save = NULL;
void insert_AtBegging(char s_name[50]){
	struct node *newNode = (struct node*) malloc (sizeof(struct node));
	strcpy(newNode->s_name,s_name);
	newNode->lptr = NULL;
	if(l==NULL){
		newNode->rptr = NULL;
		l = newNode;
		r = newNode;
		return; 
	}
	newNode->rptr = l;
	l->lptr = newNode;
	l = newNode;
	return;
}
void display_AllSongs(){
	if(l==NULL){
		printf("Music Player is Empty.\n");
		return;
	}
	struct node *save = l;
	while(save != NULL){
		printf("%s->",save->s_name);
		save = save->rptr;
	}
	printf("\n");
}
void play_MusicPlayer(int n){
	int k;
	switch(n){
		case 1 : save = l;
		         break;
		case 2 : save = r;
				 break;
		case 3 : printf("Enter K:");
				 scanf("%d",&k);
				 save = l;
				 while(k!=1){
				 	save = save->rptr;
				 	k--;
				 }
				 break;
		case 4 : save = save->rptr;
				 break;
		case 5 : save = save->lptr;
	}
	printf("%s is Playing......\n",save->s_name);
	return ;
}
void main(){
	char s_name[50];
	printf("\t\t---------Enter NULL to Break a Loop-----------\n\n");
	while(1){
		printf("Enter a Song name:");
		gets(s_name);
		if(strcmp(s_name,"NULL")==0){
			break;
		}
		insert_AtBegging(s_name);
	}	
	printf("\nMusic Palyer List:");
	void display_AllSongs();
	int n;
	printf("\n\n\t\t---------Enter -1 to Break a Loop-----------\n\n");
	printf("1.Listen First Song.\n2.Listen Last Song.\n3.Listen Kth Song.\n4.Listen Next Song.\n5.Listen Previous Song.\n");
	while(1){
		printf("Enter Number:");
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		play_MusicPlayer(n);
	}
}

