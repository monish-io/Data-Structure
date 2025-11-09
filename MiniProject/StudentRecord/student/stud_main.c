#include"stud.h"

int main(){
	char op;
	int f=0;
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
				if(hptr==NULL) {f=1; break;}
				print(hptr);
				break;

			case 'L':
				if(hptr==NULL) {f=1; break;}
				stud_dell(&hptr);
				break;

			case 'D':
				if(hptr==NULL) {f=1; break;}
				stud_del(&hptr);
				break;

			case 'M':
				if(hptr==NULL) {f=1; break;}
				stud_mod(&hptr);
				break;
				
			case 'T':
				if(hptr==NULL) {f=1; break;}
				stud_sort(hptr);
				break;

			case 'C':
				if(hptr==NULL) {f=1; break;}
				printf("\nThe total number of data in the record:  %d\n",record_size(hptr));
				break;

			case 'R':
				stud_retrv(&hptr);
				break;

			case 'V':
				if(hptr==NULL) {f=1; break;}
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
					if(hptr==NULL) {f=1; goto non;}
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
		non:
		if(f==1){
		system("clear");
		printf("\nNo data available in the record\n\n[If you want to retrieve the data from the file, press R/r]\n");
		f=0;
		}
	}
}
