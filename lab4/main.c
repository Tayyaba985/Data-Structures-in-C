#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Node2.h"
#include "DoublyLinkedList.h"

void flush();


int main()
{
    int choice;
    char load_choice;
    struct node_d * head = NULL; /// Pointer to the first node (head) of the list


    printf("Hello! This program lets you manage your Employees' Database:\n");

    printf("\nDo you want to load employee database from the file? (y/n): ");
    load_choice = getchar();

    if(load_choice == 'y')
    {
        FILE * fptr = NULL;
        if((fptr=fopen("EmpoyeeData.dat", "rb")) == NULL)
        {
            printf("\nCannot open file for loading Data!!\n\n");
            exit(1);
        }
        loadListFromFile(&head, fptr);
        fclose(fptr);
    }
    while(1)
    {
        printf("\nWhat do you want to do now?\n");

        printf("\n1. Insert a new node at the end of the list.");
        printf("\n2. Insert a new node at the start of the list.");
        printf("\n3. Print the list.");
        printf("\n4. Delete the first item from the list.");
        printf("\n5. Delete the last item from the list.");
        printf("\n6. Delete the specific item from the list.");
        printf("\n7. Insert a new node after index.");
        printf("\n8. Search the list by Data Field.");
        printf("\n9. Save the list to a file.");
        printf("\n10. Print Memory Map of the list.");
        printf("\n11. Exit the menue.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {
            case    1:  /// Add a new node to the list at the end. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                insertNodeAtEnd(&head);
                break;
            }

            case    2: /// Add a new node to the list at the start. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                insertNodeAtStart(&head);
                break;
            }

            case    3:  /// Print the list.
            {
                printList(head);
                break;
            }

            case    4:  /// Delete the first item from the list
            {
                deleteNodeFromStart(head);
                printf("\nFirst node deleted!!\n");
                break;
            }

            case    5:  /// Delete the last item from the list
            {
                deleteNodeFromEnd(head);
                printf("\nLast node deleted!!\n");
                break;
            }

            case    6:   ///Delete the specific item from the list.
            {
                int idx;
                printf("enter the index:");
                scanf("%d\n",&idx);
                deleteNodeAfter(head,idx);
                printf("\nNode deleted!!\n");
                break;
            }

            case    7:  /// Insert a new node after index.
            {
                int idx = 0;
                printf("\nEnter the index after which you want to insert a node: ");
                scanf("%d",&idx);
                flush();
                if(insertNodeAfter(head, idx) == 0)
                    printf("\nNode inserted successfully!");
                else
                    printf("\nIndex exceeds the list length!!\n");

                break;
            }

             case   8:  /// Search the list for a Data Field
            {
                int field_choice, idx=0;
                printf("\nEnter a Data Field to search by: (1 - 3)\n");
                printf("\n\t1. Name \n");
                printf("\n\t2. Age \n");
                printf("\n\t3. Basic Salary \n");
                scanf("%d", &field_choice);
                flush();

                idx = searchNodeByData(head, field_choice);

                break;
            }


            case    9:  /// Save list to file
            {
                FILE * fptr = NULL;
                if((fptr=fopen("EmployeeData1.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(head, fptr);
                break;
            }

            case    10:  /// Print Memory Map.
            {
                printMemMap(head);
                break;
            }

            case    11:  /// Exit the program.
            {
                printf("\nExiting on user request.\n\n");
                return(0);
            }
        }
    }
    return 0;
}


void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
