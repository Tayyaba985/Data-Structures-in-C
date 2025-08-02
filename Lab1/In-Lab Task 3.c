///*******************************
//name: tayyaba
//roll no: fa21-bce-093
//lab no 1 "in lab task 2"
///*******************************
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

int main()
{
    FILE *fp ;
    struct emp employee;
    struct emp *sptr;
    int num_rec;

    // Open the file for reading in the Binary Mode
    fp = fopen ( "employees_records.dat", "rb" ) ;
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
   // get the number of records fom the user to be read
    printf("number of records to be read:\n ");
    scanf("%d",&num_rec);
    fflush(stdin);

    read_records_from_file(sptr,num_rec,fp);
    print_records(sptr,num_rec);

    fclose(fp);
    return 0;
}


int read_records_from_file(struct emp * sptr, int num_records, FILE * fptr)
{
    fread(sptr, sizeof(struct emp), num_records, fptr);
}

void print_records(struct emp * sptr, int num_records)
{
    for(int i=0; i<num_records; i++)
    {
        printf("\n\nRecord-%d:",i+1);
        printf("\nName: %s",(sptr + i)->name);
        printf("Age: %d",(sptr + i)->age);
        printf("\nBasic Salary: %.2f",(sptr + i)->bs);
    }
    printf("\n");
}
