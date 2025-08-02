#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Node.h"
#include "SinglyLinkedList.h"
void flush();

int main()
{
    int choice;
    char load_choice;
    struct node * head = NULL; /// Pointer to the first node (head) of the list
    //struct node * last = NULL; /// Pointer to the last element of the list

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
        printf("\n1. Insert a new node at the start of the list.");
        printf("\n2. Insert a new node at the before a node in the list.");
        printf("\n3. Insert a new node at the end of the list.");
        printf("\n4. Print the list.");
        printf("\n5. Delete the last item from the list.");
        printf("\n6. Delete the first item from the list.");
        printf("\n7. Delete the specific item from the list.");
        printf("\n8. Insert a new node after index.");
        printf("\n9. Search the list by Data Field.");
        printf("\n10. Save the list to a file.");
        printf("\n11. Exit the menue.\n");



        scanf("%d", &choice);
        flush();
        switch (choice)
        {   case    1:  /// Add a node to the start of the list.
            {
                printf("adding a new node at the start of the list:");
                insertNodeAtStart(&head);
                break;
            }
            case    2:  /// Add a node before a specific index.
            {
                printf("adding a new node before a specific address of the list:");
                int index;
                printf("enter the index");
                scanf("%d",&index);
                insertNodeBefore(head, index);
                break;
            }

            case    3:  /// Add a new node to the list at the end. Create one if empty.
            {
                printf("\nAdding a new node: \n\n");
                insertNodeAtEnd(&head);
                break;
            }

            case    4:  /// Print the list.
            {
                printList(head);
                break;
            }

            case    5:  /// Delete the last item from the list
            {
                deleteNodeFromEnd(head);
                printf("\nLast node deleted!!\n");
                break;
            }
            case    6:   /// Delete the first item from the list
                {
                    deleteNodeFromStart(head);
                    printf("\nFirst node deleted!!\n");
                    break;
                }
            case    7:   /// Delete the specific item from the list
                {
                    int index;
                    printf("Enter the index of the node: ");
                    scanf("%d",&index);
                    deleteNodeAfter(head,index);
                    break;
                }
            case    8:  /// Insert a new node after index.
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

             case   9:  /// Search the list for a Data Field
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


            case    10:  /// Save list to file
            {
                FILE * fptr = NULL;
                if((fptr=fopen("EmpoyeeData.dat", "wb")) == NULL)
                {
                    printf("\nCannot open file for saving Data!!\n\n");
                    break;
                }

                saveListToFile(head, fptr);
                printf("data saved successfully");
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
