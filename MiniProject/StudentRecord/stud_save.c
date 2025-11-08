void stud_save(SR *ptr){
    FILE *fp=fopen("student.dat","w");
    while(ptr!=NULL){
        fprintf(fp,"%d %s|%f\n",ptr->roll,ptr->name,ptr->per);
        ptr=ptr->next;
    }
    fclose(fp);
}
