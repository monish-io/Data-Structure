#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include"stud_add.c"
//#include"stud_del.c"
//#include"stud_print.c"
//#include"stud_mod.c"
//#include"stud_save.c"
//#include"stud_sort.c"

typedef struct student_record{
	int roll;
	char name[16];
	float per;
	struct student_record *next;
}SR;

void stud_add(SR **);
void print(SR *);
void stud_dell(SR **);
void stud_del(SR **);
void stud_save(SR *);
void stud_mod(SR **);
void stud_sort(SR *);
int record_size(SR *);
void stud_retrv(SR **);
