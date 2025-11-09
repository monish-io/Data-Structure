#include"stud.h"

//int record_size(SR *);
void stud_sort(SR *ptr){
	int n=record_size(ptr);
	char op;
	s:
	printf("\n\n\t***************SORT RECORD*******************\n");
	printf("\t|\tN/n\t: Sort by Name              |\n");            //
	printf("\t|\tP/p\t: Sort by Percentage        |\n");
	printf("\t|\tR/r\t: Sort by Roll(Reverse)     |\n");
	printf("\t*********************************************\n\n");
	printf("Enter a choice:   ");	
	scanf(" %c",&op);
	if(op>='a' && op<='z') op=op^32;
	
	SR *arr[n];
	SR *shuf=ptr;
	int ind=0;
	while(shuf!=NULL){
		arr[ind++]=shuf;
		shuf=shuf->next;
	}
	switch(op){
		case 'N':{
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					int val=strcasecmp(arr[i]->name,arr[j]->name);
					if(val>0){
						shuf=arr[i];
						arr[i]=arr[j];
						arr[j]=shuf;
					}
				}
			}
		}
		break;
		case 'P':{
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(arr[i]->per < arr[j]->per){
						shuf=arr[i];
						arr[i]=arr[j];
						arr[j]=shuf;
					}
				}
			}
		}
		break;
		case 'R':{
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(arr[i]->roll < arr[j]->roll){
						shuf=arr[i];
						arr[i]=arr[j];
						arr[j]=shuf;
					}
				}
			}
		}
		break;
		default:{
			printf("\nEnter a valid option.\n");
			goto s;
		}
	}
	system("clear");
	printf("\n\n\t**************SORTED LIST****************\n");
	printf("\t|Roll  | Name             | Percentage\t|\n");     //
	printf("\t+---------------------------------------+\n");
	for(ind=0;ind<n;ind++)
	printf("\t| %3d  | %-17s| \t%.2f \t|\n",arr[ind]->roll,arr[ind]->name,arr[ind]->per);
	printf("\t*****************************************\n\n");
}
int record_size(SR *ptr){
	int count=0;
	while(ptr!=NULL){
		ptr=ptr->next;
		count++;
	}
	return count;
}
