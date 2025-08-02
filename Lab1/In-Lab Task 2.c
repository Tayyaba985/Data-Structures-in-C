///*******************************
//name: tayyaba
//roll no: fa21-bce-093
//lab no 1 "in lab task 2"
///*******************************
#include <stdio.h>
#include <stdlib.h>
/// Define a structure 'emp' to hold data about an employee
struct emp
{
    char name[48]; // Name of the employee
    int age;
    float bs; // Basic Salary as a floating point number.
};
/// Functions:
int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr);
int read_records_from_file(struct emp * sptr, int num_records, FILE * fptr);
void print_records(struct emp * sptr, int num_records);
int main(void)
{
    FILE *fp ;
    struct emp employee;
    struct emp *sptr;  // structure pointer
    int  num_rec = 0, n;

    // Open the file for writing in the Binary Mode
    fp = fopen ( "employees_records.dat", "wb" ) ;
    if ( fp == NULL )
    {
        printf ( "Cannot open file\n" ) ;
        exit(1) ;
    }
    printf("number of records: \n");
    scanf("%d",&n);
    fflush(stdin);
    sptr = (struct emp*) malloc(n * sizeof(struct emp));

    for(int i=0; i<n; i++)
    {
        printf("\nRecord-%d\n",i+1);
        printf ( "Enter the name of the Employee:\n " ) ;
        fgets ((sptr+i)->name, 48, stdin);
        printf ( "Enter the age of the Employee:\n " ) ;
        scanf("%d", &((sptr+i)->age) );
        printf ( "Enter the Basic Salary of the Employee:\n " ) ;
        scanf("%f", &((sptr+i)->bs) ) ;
        fflush(stdin);
        num_rec++;
    }
    int v;
    v = write_records_to_file(sptr,num_rec,fp);
    printf("Structures stored in file: %d\n",v);
    fclose(fp);
    return 0;
}

int write_records_to_file (struct emp * sptr, int num_records, FILE * fptr)
{
    int num = fwrite(sptr, sizeof(struct emp), num_records, fptr);
    return num;
}
