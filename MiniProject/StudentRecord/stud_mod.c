void stud_mod(SR **ptr){
	char op;
	m:
	printf("\n\n\t***********MODIFICATION SEARCH***************\n");
	printf("\t|\tR/r\t: Search by Roll no         |\n");            //
	printf("\t|\tN/n\t: Search by Name            |\n");
	printf("\t*********************************************\n\n");
	printf("Enter a choice:   ");	
	scanf(" %c",&op);
	if(op>='a' && op<='z') op=op^32;
	SR *temp=*ptr;
	int r;
	switch(op){
		case 'R':{
			mr:
			printf("Enter the Roll no to modify:\t");
			scanf("%d",&r);
		}
		break;
		case 'N':{
			char st[16];
			SR *p=*ptr;
			mn:
			printf("Enter the Name to modify:\t");
			scanf(" %[^\n]",st);
			while(p!=NULL && (strcmp(st,p->name))){
				p=p->next;
			}
			if(p==NULL){
				printf("\nEnter a valid name.\n");
				goto mn;
			}
			p=*ptr;
			printf("\n\n\t*************STUDENT LIST****************\n");
			printf("\t|Roll | Name             | Percentage\t|\n");
			while(p!=NULL){
				if(!(strcmp(st,p->name)))
				printf("\t|  %d  | %-17s| \t%.2f \t|\n",p->roll,p->name,p->per);
				p=p->next;
			}
			printf("\t*****************************************\n\n");
			printf("Enter the Roll no to modify:\t");
			scanf("%d",&r);
		}
		break;	
		default: {
			printf("Enter a valid option.\n");
			goto m;
		}
	}
	while(temp!=NULL && temp->roll!=r){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("\nEnter a valid Roll no\n");
		goto mr;
	}
	temp=*ptr;
	while(temp!=NULL){
		if(temp->roll==r){
			m2:
			printf("\n\n\t**************MODIFY RECORD******************\n");
			printf("\t|\tN/n\t: Modify Name               |\n");            //
			printf("\t|\tP/p\t: Modify Percentage         |\n");
			printf("\t*********************************************\n\n");
			printf("Enter a choice:   ");
			scanf(" %c",&op);
			if(op>='a' && op<='z') op=op^32;
			if(op=='N'){
				printf("\nCurrent name: %s\n",temp->name);
				char s[16];
				printf("Enter the NEW name:\t");
				scanf(" %[^\n]",s);
				strcpy(temp->name,s);
				break;
			}
			else if(op=='P'){
				printf("\nCurrent percentage: %.2f\n",temp->per);
				printf("Enter the NEW percentage:\t");
				scanf("%f",&temp->per);
				break;
			}
			else{
				printf("Enter a valid option.\n");
				goto m2;
			}
		}
		else temp=temp->next;
	}
	printf("\nThe data has been modified\n"); 
}
