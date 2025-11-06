#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student_record {
	int roll;
	char name[16];
	float per;
	struct student_record *next;
} SR;
void stud_add(SR **);
void print(SR *);
void stud_dell(SR **);
void stud_del(SR **);
void stud_del(SR **ptr) {
	char op;
	printf("\t****DELETE RECORD****\n");
	printf("R/r     : Delete by Roll\n");
	printf("N/n     : Delete by name\n");
	printf("\tEnter a choice:\n");
	scanf(" %c",&op);
	if(op=='r'||op=='R') {
		short int i;
		printf("Enter the roll to delete\n");
		scanf("%hd",&i);
		SR *prv,*temp=*ptr;
		while(temp!=NULL) {
			if(temp->roll==i) {
				if(*ptr==temp) *ptr=temp->next;
				else prv->next=temp->next;
				free(temp);
				temp=NULL;
				return;
			}
			else {
				prv=temp;
				temp=temp->next;
			}
		}
	}
	else if(op=='N'||op=='n') {
		char st[16];
		printf("Enter a name to delete\n");
		scanf(" %[^\n]",st);
		SR *prv,*temp=*ptr;

		while(temp!=NULL) {
			if(!(strcmp(st,temp->name))) {

				if(*ptr==temp) *ptr=temp->next;
				else prv->next=temp->next;
				free(temp);
				temp=NULL;
				return;
			}
			else {
				prv=temp;
				temp=temp->next;
			}
		}
	}
}
void stud_dell(SR **ptr) {
	SR *temp=*ptr;
	while(*ptr!=NULL) {
		*ptr=temp->next;
		free(temp);
		temp=*ptr;
	}
}
void print(SR *ptr) {
	printf("Roll  Name      Percentage\n");
	while(ptr!=NULL) {
		printf("%d     %s%7.2f\n",ptr->roll,ptr->name,ptr->per);
		ptr=ptr->next;
	}
}
void stud_add(SR **ptr) {
	SR *temp=(SR*)malloc(sizeof(SR));
	printf("Enter the details..\n");
	printf("Enter the name:\n");
	scanf(" %[^\n]",temp->name);
	printf("Enter the percentage scored!:\n");
	scanf("%f",&temp->per);

	if(*ptr==NULL) {
		temp->next=*ptr;
		*ptr=temp;
		temp->roll=1;
	}
	else {
		SR *last=*ptr;
		while((last->roll+1==temp->roll) || (last->next!=NULL)) last=last->next;
		//if(temp->roll!=last->roll+1)
		temp->next=last->next;
		last->next=temp;
		temp->roll=(last->roll)+1;
	}
}
int main() {
	char op;
	SR *hptr=NULL;
	while(1) {
		printf("\t****STUDENT RECORD MENU****\n");
		printf("A/a     : Add New Record\n");
		printf("D/d     : Delete A Record\n");
		printf("S/s     : Show the List\n");
		printf("M/m	    : Modify A record\n");
		printf("V/v	    : Save\n");
		printf("E/e     : Exit\n");
		printf("T/t     : Sort the List\n");
		printf("L/l	    : Delete All the Records\n");
		printf("R/r	    : Reverse the List\n");
		printf("\tEnter a choice:\n");
		scanf(" %c",&op);
		if(op>=97 && op<=122) op=op^32;
		switch(op) {
		case 'A':
			stud_add(&hptr);
			break;

		case 'S':
			print(hptr);
			break;

		case 'L':
			stud_dell(&hptr);
			break;

		case 'D': {
			stud_del(&hptr);
			break;
		}
		/*
			   case 'D':
			   stud_del(&hptr);
			   break;

			   case 'D':
			   stud_del(&hptr);
			   break;

			   case 'D':
			   stud_del(&hptr);
			   break;

			   case 'D':
			   stud_del(&hptr);
			   break;
		*/
		case 'E':
			goto e;
			break;

		default :
			printf("Give error");
		}
	}
e:
	return 0;
}
