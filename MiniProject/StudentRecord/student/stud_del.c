#include"stud.h"

void stud_del(SR **ptr){
	char op;
	int i;
	del:
	printf("\n\n\t*************DELETE RECORD*******************\n");
	printf("\t|\tR/r\t: Delete by Roll no         |\n");            //
	printf("\t|\tN/n\t: Delete by Name            |\n");
	printf("\t*********************************************\n\n");
	printf("Enter a choice:   ");
	scanf(" %c",&op);
	if(op=='r'||op=='R'){
		delr:
		printf("Enter the roll to delete:\t");
		scanf("%d",&i);
	}
	else if(op=='N'||op=='n'){
		char st[16];
		deln:
		printf("Enter a name to delete:\t");
		scanf(" %[^\n]",st);
		SR *temp=*ptr;
		while(temp!=NULL){
			if(!(strcmp(st,temp->name))) break;
			temp=temp->next;
		}
		if(temp==NULL){
			printf("\nNo name found in the record.\n");
			goto deln;
		}
		temp=*ptr;
		printf("\n\n\t*************STUDENT LIST****************\n");
		printf("\t|Roll  | Name             | Percentage\t|\n");
		printf("\t+---------------------------------------+\n");
		while(temp!=NULL){
			if(!(strcmp(st,temp->name)))
			printf("\t| %3d  | %-17s| \t%.2f \t|\n",temp->roll,temp->name,temp->per);
			temp=temp->next;
		}
		printf("\t*****************************************\n\n");
		printf("Enter the roll no to delete:\t");
		scanf("%d",&i);
	}
	else{ printf("Enter a valid option.\n"); goto del;}
	SR *prv,*temp=*ptr;
	while(temp!=NULL){
		if(temp->roll==i){
			if(*ptr==temp) *ptr=temp->next;
			else prv->next=temp->next;
			free(temp);
			temp=NULL;
			system("clear");
			printf("\nYour requested data is deleted\n");
			return;
		}
		else{
			prv=temp;
			temp=temp->next;
		}
	}
	if(temp==NULL){
		printf("\nEnter a valid Roll no\n");
		goto delr;
	}
}
void stud_dell(SR **ptr){
	SR *temp=*ptr;
	while(*ptr!=NULL){
		*ptr=temp->next;
		free(temp);
		temp=*ptr;
	}
	*ptr=NULL;
	system("clear");
	printf("\nAll the data records are deleted!\n");
}
