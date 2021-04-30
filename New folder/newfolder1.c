#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*stnode, *ennode, *h,*temp,*temp1,*temp2,*temp4;
 struct node *current = NULL;
void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));
 
        if(stnode != NULL)
        {
            printf(" Input data for node 1 : "); 
            scanf("%d", &num);
 
            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;    
                    fnNode->nextptr = NULL;
 
                    ennode->nextptr = fnNode;   
                    ennode = fnNode;           
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}
void displayDlList()
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        printf("\n\n Data entered on the list are :\n");
 
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr; 
        }
    }
}

void printRecursive(struct node *stnode) 
{ 
	struct node *temp; int i=1;
	while(ennode != NULL) 
	{
		temp = stnode;
        printf("node %d = %d \n",i,temp->num);
        i++;
		printRecursive(temp->nextptr);
	}
}
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = stnode;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->num == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> nextptr;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}
void insertAtN(int num, int position)
{
    int i;
    struct node * newNode, *temp;

    if(stnode == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = stnode;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->nextptr;
            i++;
        }

        /*if(position == 1)
        {
            insertAtBeginning(num);
        }
        else if(temp == ennode)
        {
            insertAtEnd(num);
        }*/
        if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->num = num;
            newNode->nextptr = temp->nextptr; // Connect new node with n+1th node
            newNode->preptr = temp;          // Connect new node with n-1th node

            if(temp->nextptr != NULL)
            {
                /* Connect n+1th node with new node */
                temp->nextptr->preptr= newNode;
            }
            /* Connect n-1th node with new node */
            temp->nextptr = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}
void deleteFromBeginning()
{
    struct node * toDelete;

    if(stnode == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = stnode;

        stnode = stnode->nextptr; // Move head pointer to 2 node
        
        if (stnode != NULL)
            stnode->preptr = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}
void deleteFromEnd()
{
    struct node * toDelete;

    if(ennode == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = ennode;

        ennode = ennode->preptr; // Move last pointer to 2nd last node
        
        if (ennode != NULL)
            ennode->nextptr = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}
 void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = stnode;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->nextptr;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == ennode)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->preptr->nextptr = current->nextptr;
        current->nextptr->preptr = current->preptr;

        free(current); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
void ReversePrint()
{
    struct node * tmp;
    int n = 1;
    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = ennode;
        printf("\n\n Data entered on the list are :\n");
 
        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->preptr; 
        }
    }
}
void reverseList()
{
    struct node *current, *temp;

    current = stnode;
    while(current != NULL)
    {
        /*
         * Swap the previous and next address fields of current node
         */
        temp = current->nextptr;
        current->nextptr = current->preptr;
        current->preptr = temp;

        /* Move the current pointer to next node which is stored in temp */
        current = temp;
    }
    
    /* 
     * Swap the head and last pointers
     */
    temp = stnode;
    stnode = ennode;
    ennode = temp;

    printf("LIST REVERSED SUCCESSFULLY.\n");
}
int main(int argc, char** argv)
{
	int choice,num,n;
	stnode = NULL;
    ennode = NULL;
    printf(" Input the number of nodes : ");
    scanf("%d", &num);
	while(1)
	{
	printf("\n 1. Creation\n");
	printf("\n 2. Display\n");
	printf("\n 3. Display using recursive function \n");
	printf("\n 4. Searching \n");
	printf("\n 5. Insertion \n");
	printf("\n 6. Deletion \n");
	printf("\n 7. Reverse print \n");
	printf("\n 8. Reverse the linked list \n");
	printf("\n 9. To Exit PRESS: 9+ENTER+KEY \n");
	printf("\n\t ENTER YOUR CHOICE : ");
	scanf("%d",&choice);
	switch(choice)
	{
        case 1:
		{
		 DlListcreation(num);
		 break;	
		}
		case 2:
		{
		displayDlList();
		break;	
		}
		case 3:
		{
        printRecursive(stnode);
        //displayDlList();
        break;
		}
		case 4:
		{
        search(num);
        break;
		}
		case 5:
		{
			printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &num);

                insertAtN(num,n);
                break;
		}
		case 6:
		{
		printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
              	break;
		}
		case 7:
		{
			ReversePrint();
			break;
		}
		case 8:
		{
			reverseList();
			displayDlList();
			break;
		}
        case 9:exit(0); 
		default:
		printf("\n Invalid Choice.\n ");
	}
    getch();
    system("cls");
}
}