/*
 *Double Linked-List Algorithm in c
 *Please feel free to ask any question at parvesh.singh004@gmail.com
 */


#include<stdio.h>
#include<stdlib.h>

void doubleLinkList(int);
void insertElementatEnd(int);
void insertElementatBegin(int);
void insertElementatLocation();
void printDoubleLinkList();
void deleteElement();
void reverseDoubleLinkList();
void searchElement();


typedef struct Node
{
    int data;
    struct Node *prev,*next;
}Node;

void printLinkListUsingRecursion(struct Node*);


Node *Head,*temp,*ptr;

int main()
{
    Head = NULL;
    while (1)
    {
        printf("Enter 1 for Insert element in begining of linklist\n");
        printf("Enter 2 for Insert element in end of linklist\n");
        printf("Enter 3 for Insert element at particular location\n");
        printf("Enter 4 Delete element from linklist\n");
        printf("Enter 5 for print all the elements in Linklist\n");
        printf("Enter 6 for reverse the linklist\n");
        printf("Enter 7 for print the linklist using recusion\n");
        printf("Enter 8 for search the element in Double Linked-List\n");
        printf("Enter 9 for exit\n");
        
        int option;
        scanf("%d",&option);
        doubleLinkList(option);
        
        
    }
    
    
    
    
    return 0;
}

void doubleLinkList(int option)
{
    int variable;
    switch (option) {
        case 1:
            printf("Enter number\n");
            scanf("%d",&variable);
            insertElementatBegin(variable);
            
            break;
            
        case 2:
            printf("Enter number\n");
            scanf("%d",&variable);
            insertElementatEnd(variable);
            break;
            
        case 3:
            insertElementatLocation();
            break;
            
        case 4:
            deleteElement();
            break;
            
        case 5:
            printDoubleLinkList();
            break;
            
        case 6:
            reverseDoubleLinkList();
            break;
            
        case 7:
            printLinkListUsingRecursion(Head);
            break;
            
        case 8:
            searchElement();
            break;
            
        case 9:
            exit(1);
            break;
        default:
            break;
    }
}

void insertElementatEnd(int variable)
{
    if(Head == NULL)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = variable;
        temp->prev = NULL;
        temp->next = NULL;
        Head = temp;
    }
    else
    {
        ptr = Head;
        temp = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            
        }
        
        temp = (Node *)malloc(sizeof(Node));
        temp->data = variable;
        temp->next = NULL;
        temp->prev = ptr;
        ptr->next = temp;
        
    }
    
}

void insertElementatBegin(int variable)
{
    if(Head == NULL)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = variable;
        temp->prev = NULL;
        temp->next = NULL;
        Head = temp;
    }
    else
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = variable;
        temp->prev = NULL;
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
        
    }
    
}

void insertElementatLocation()
{
    printDoubleLinkList();
    printf("Enter the Location\n");
    int location;
    scanf("%d",&location);
    
    ptr = Head;
    int count = 0;
    if (Head == NULL) return;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    int totalnoofElement = count;
    ptr = NULL;
    ptr = Head;
    if(location <= totalnoofElement)
    {
        int var = 0;
        temp = (Node *)malloc(sizeof(Node));
        if(temp)
        {
            int variable;
            printf("Enter the element\n");
            scanf("%d",&variable);
            if(location == 1)
            {
                temp->data = variable;
                temp->prev = NULL;
                temp->next = Head;
                Head->prev = temp;
                Head = temp;
            }
            else if (location == totalnoofElement)
            {
                ptr = NULL;
                ptr = Head;
                
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                    
                }
                temp->data = variable;
                temp->next = NULL;
                temp->prev = ptr;
                ptr->next = temp;
                
            }
            else
            {
                while (var<location-1)
                {
                    ptr = ptr->next;
                    
                    var++;
                }
                
                ptr->prev->next = temp;
                temp->data = variable;
                temp->next = ptr;
                temp->prev = ptr->prev;
                ptr->prev = temp;
                
                
                printDoubleLinkList();
            }
            
        }
        
        else
        {
            printf("Memory allocation Failed\n");
            
        }
        
    }
    else
    {
        printf("Location Invalid\n");
    }
    
}

void deleteElement()
{
    printDoubleLinkList();
    printf("Enter the Number\n");
    int vairiable;
    scanf("%d",&vairiable);
    ptr = NULL;
    ptr = Head;
    _Bool isVariablePresent = 0;
    
    while (ptr->next != NULL)
    {
        if(ptr->data == vairiable)
        {
            isVariablePresent = 1;
        }
        ptr = ptr->next;
    }
    Node *last;
    last = ptr;
    if(isVariablePresent)
    {
        
        ptr = NULL;
        ptr = Head;
        while (ptr->data != vairiable)
        {
            
            ptr = ptr->next;
            
            
        }
        //if element at first position
        if(ptr->prev == NULL)
        {
            ptr->next->prev = Head;
            Head = ptr->next;
            ptr->next = NULL;
            ptr->prev = NULL;
            
        }
        else
        {
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
        }
        printf("Updated List\n");
        printDoubleLinkList();
    }
    else
    {       //if the element at last position
        if(last->next == NULL)
        {
            last->prev->next = NULL;
            last->prev = NULL;
        }
        else    //if element is not in list
        {
            printf("Element not Found\n");
        }
    }
    
}

void reverseDoubleLinkList()
{
    ptr = NULL;
    ptr = Head;
    Node *temp;
    temp = NULL;
    while (ptr !=  NULL)
    {
        temp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = temp;
        ptr = ptr->prev;
    }
    
    if(temp != NULL)
    {
        Head = temp->prev;
    }
    printf("Double Link-list reverse sucessfully\n");
}


void printLinkListUsingRecursion(Node *ptr)
{
    if(ptr == NULL) return;
    
    printf("%d",ptr->data);
    printLinkListUsingRecursion(ptr->next);
}

void searchElement()
{
    int variable;
    printf("Enter the element");
    scanf("%d",&variable);
    
    Node *start,*last;
    start = Head;
    
    while (start->next != NULL)
    {
        start = start->next;
    }
    last = start;
    start = Head;
    
    _Bool isElementinList = 0;
    while (start->next != NULL && last->prev != Head)
    {
        
        if(start->data == variable || last->data == variable)
        {
            printf("Element found in the list\n");
            isElementinList = 1;
            break;
        }
        
        start = start->next;
        last = last->prev;
    }
    
    if(!isElementinList)
    {
        printf("Element is not in list\n");
    }
    
}


void printDoubleLinkList()
{
    ptr = Head;
    
    while (ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
