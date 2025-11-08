#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stud_add.c"
#include"stud_del.c"
#include"stud_print.c"
#include"stud_mod.c"
#include"stud_save.c"
#include"stud_sort.c"

void stud_add(SR **);
void print(SR *);
void stud_dell(SR **);
void stud_del(SR **);
void stud_save(SR *);
void stud_mod(SR **);
void stud_sort(SR *);
//int record_size(SR *);
void stud_retrv(SR **);
void stud_retrv(SR **ptr){
	int r;
	char m[16];
	float p;
	FILE *fp=fopen("student.dat","r");
	if(fp==NULL){
		system("clear");
		printf("\nBackup File not found!\n");
		return;
	}
	while((fscanf(fp,"%d %[^|]|%f\n",&r,m,&p))!=EOF){
		SR *temp=(SR*)malloc(sizeof(SR));
		temp->roll=r;
		strcpy(temp->name,m);
		temp->per=p;

        if(*ptr==NULL){
			temp->next=*ptr;
			*ptr=temp;
		}
		else{
			SR *last=*ptr;
			while(last->next!=NULL) last=last->next;
			temp->next=last->next;
			last->next=temp;
		}
    }
	fclose(fp);
	system("clear");
	printf("\nThe Backup Saved data is retrieved.\n");
}

int main(){
	char op;
	SR *hptr=NULL;
	while(1){
		printf("\n\n\t*************STUDENT RECORD MENU*************\n");
		printf("\t|\tA/a\t: Add New Record            |\n");
		printf("\t|\tS/s\t: Show the List             |\n");
		printf("\t|\tM/m\t: Modify A record           |\n");
		printf("\t|\tT/t\t: Sort the List             |\n");
		printf("\t|\tD/d\t: Delete A Record           |\n");
		printf("\t|\tL/l\t: Delete All the Records    |\n");
		printf("\t|\tV/v\t: Save                      |\n");
		printf("\t|\tE/e\t: Exit                      |\n");
		printf("\t*********************************************\n\n");
		printf("Enter a choice:   ");

		scanf(" %c",&op);
		if(op>=97 && op<=122) op=op^32;
		switch(op){
			case 'A':
				stud_add(&hptr);
				break;

			case 'S':
				print(hptr);
				break;

			case 'L':
				stud_dell(&hptr);
				break;

			case 'D':
				stud_del(&hptr);
				break;

			case 'M':
				stud_mod(&hptr);
				break;
				
			case 'T':
				stud_sort(hptr);
				break;

			case 'C':
				printf("\nThe total number of data in the record:  %d\n",record_size(hptr));
				break;

			case 'R':
				stud_retrv(&hptr);
				break;

			case 'V':
				stud_save(hptr);
				printf("\nData saved successfully!\n");
				break;

			case 'E':
				printf("\n\n\t*********************************************\n");
				printf("\t|\tS/s\t: Save and Exit             |\n");            //
				printf("\t|\tE/e\t: Exit without saving       |\n");
				printf("\t*********************************************\n\n");
				printf("Enter a choice:   ");
				scanf(" %c",&op);
				if(op>='a' && op<='z') op=op^32;
				if(op=='S'){

					stud_save(hptr);
					printf("\nData saved successfully!\n");
					printf("\nExiting the program...\n");
					return 0;
				}
				else if(op=='E'){
					printf("\nExiting the program without saving...\n");
					return 0;
				}
				else{
					printf("Enter a valid option.\n");
					break;
				}
				break;

			default :
				system("clear");
				printf("\nEnter a valid option.\n");
		}
	}
}
