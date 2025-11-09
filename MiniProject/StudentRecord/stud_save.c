#include"stud.h"

void stud_save(SR *ptr){
    FILE *fp=fopen("student.dat","w");
    while(ptr!=NULL){
        fprintf(fp,"%d %s|%f\n",ptr->roll,ptr->name,ptr->per);
        ptr=ptr->next;
    }
    fclose(fp);
}
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
