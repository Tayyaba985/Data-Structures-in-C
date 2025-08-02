#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "pr_queue_functions.h"

struct element pr_dequeue(struct node ** qfront, struct node ** qrear)
{
    if(*qfront == NULL) /// if a dequeue operation is sought when the queue is already empty
    {
        printf("The queue was empty. Returning garbage data! \n\n");
        struct element temp;
        return(temp);
    }
    struct element temp = (*qfront)->data;   /// I copy the data at the front node into a temporary variable

    struct node * ptr_temp = (*qfront);

    *qfront = (*qfront)->next;  /// Move the 'front' pointer to the next node
    free(ptr_temp);

    if(*qfront == NULL) /// When we delete the last node,
        *qrear = NULL;  /// we also set the 'rear' pointer to NULL
    return(temp);

}

void pr_enqueue(struct node ** qfront, struct node ** qrear, struct element new_data, int priority)
{
    /* Complete this function*/
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if(*qfront == NULL)/// If the queue is empty, we have to modify both the pointers
    {
        ///(*rear)->next = new_node; /// This was the mistake! When front is NULL then rear is also
                                     /// NULL. We can't have NULL->next !
        *qrear = new_node;
        *qfront = new_node;
    }
    else
    {
        (*qrear)->next = new_node;
        *qrear = new_node;
    }
    ///printf("\nFront pointer is at address %u, and its next is %u\n", (*qfront), (*qfront)->next);
   /// printf("\nEnqueued %d", new_data.value);

}

/* Function returns true if the queue is empty false otherwise*/
int pr_isEmpty(struct node * qfront)
{
    return(qfront == NULL);
}
