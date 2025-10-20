/* WAP to define a C structure named Student (roll_no, name, branch and 
batch_no) and also to access the structure members using Pointer. */
#include<stdio.h>
struct Student{
	int roll_no;
	char name[50];
	char bname[50];
	int b_no;
};
void main()
{
	int i=1;
	struct Student *s1 = (struct Student*) malloc (sizeof(struct Student));//Here we made Structure Pointer
	printf("Enter Student Name:");
	scanf("%s",s1->name);
	printf("Enter %s Branch Name:",s1->name);
	scanf("%s",s1->bname);
	printf("Enter %s Batch_no:",s1->name);
	scanf("%d",&s1->b_no);
	printf("Enter %s Roll_no:",s1->name);
	scanf("%d",&s1->roll_no);
	printf("\n\nStudent Name: %s\nStudent Branch Name: %s\nStudent Roll No: %d\n Student Batch No: %d",s1->name,s1->bname,s1->roll_no,s1->b_no);
}
