void print(SR *ptr){
	system("clear");
	printf("\n\n\t*************STUDENT LIST****************\n");
	printf("\t|Roll | Name             | Percentage\t|\n");		//
	while(ptr!=NULL){
		printf("\t|  %d  | %-17s| \t%.2f \t|\n",ptr->roll,ptr->name,ptr->per);
		ptr=ptr->next;
	}
	printf("\t*****************************************\n\n");
}
