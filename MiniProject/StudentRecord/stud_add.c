typedef struct student_record{
	int roll;
	char name[16];
	float per;
	struct student_record *next;
}SR;
void stud_add(SR **ptr){
	SR *temp=(SR*)malloc(sizeof(SR));
	printf("Enter the details...\n");
	printf("Enter the name:   \t");
	scanf(" %[^\n]",temp->name);
	printf("Enter the percentage scored!:\t");
	scanf("%f",&temp->per);
	
	if(*ptr==NULL) temp->roll=1;
	else{
	     SR *last=*ptr;
	     while((last->next!=NULL) && (last->roll+1==last->next->roll)) last=last->next;
	     temp->roll=last->roll+1;
	}

	if((*ptr==NULL) || (temp->roll < (*ptr)->roll)){
		temp->next=*ptr;
		*ptr=temp;
	}
	else{
		SR *last=*ptr;
		while((last->next!=NULL) && (temp->roll > (last->next->roll))) last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
