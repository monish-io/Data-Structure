void stud_save(struct student_record *ptr){
    FILE *fp=fopen("student.dat","w");
    while(ptr!=NULL){
        fprintf(fp,"%d %s %.2f\n",ptr->roll,ptr->name,ptr->per);
        ptr=ptr->next;
    }
    fclose(fp);
}