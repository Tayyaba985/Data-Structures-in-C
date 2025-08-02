#include <stdio.h>
#include <stdlib.h>
struct emp
{
    char name[48]; // Name of the employee
    int age;
    float bs; // Basic Salary as a floating point number.
};

int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr);
int main(void)
{
    FILE *fp ;
    struct emp employee;
    struct emp *emptr;
    int  num_rec = 0, n;

    // Open the file for writing in the Binary Mode
    fp = fopen ( "employees_records.dat", "w" ) ;
    if ( fp == NULL )
    {
        printf ( "Cannot open file\n" ) ;
        exit(1) ;
    }
    printf("enter number of persons: ");
    scanf("%d",&n);
    fflush(stdin);
    emptr = (struct emp*) malloc(n * sizeof(struct emp));

    for(int i=0; i<n; i++)
    {

        printf ( "\nEnter the name of the Employee: " ) ;
        fgets ((emptr+i)->name, 48, stdin);
        printf ( "Enter the age of the Employee: " ) ;
        scanf("%d", &((emptr+i)->age) );
        printf ( "Enter the Basic Salary of the Employee: " ) ;
        scanf("%f", &((emptr+i)->bs) ) ;
        fflush(stdin);
        num_rec++;
    }
    printf("records written: %d", write_records_to_file(emptr,num_rec,fp));
    fclose(fp);
    return 0;
}

int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr)
{
    int num = 0;
    for(int i=0; i<num_records; i++)
    {
        fprintf(fptr,"\t%s%d\t%f\n", (sptr+i)->name, (sptr+i)->age, (sptr+i)->bs);
        num++;
    }
    return num;
}
