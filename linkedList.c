#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Rlink;
    struct Node *Llink;
};
struct Node *header = NULL;
struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->Rlink = NULL;
    newnode->Llink = NULL;
    return (newnode);
};

void insertAtFront(int data)
{
    struct Node *newnode;
    if (header == NULL)
    {
        newnode = CreateNode(data);
        header = newnode;
    }
    else
    {
        newnode = CreateNode(data);
        newnode->Llink = NULL;
        newnode->Rlink = header;
        header = newnode;
    }
}
void insertAtEnd(int data)
{
    struct Node *newnode = CreateNode(data);
    struct Node *ptr = header;
    if (header == NULL)
        header = newnode;
    else
    {
        while (ptr->Rlink != NULL)
        {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = newnode;
        newnode->Llink = ptr;
    }
}
void insertAtAny(int data, int pos)
{
    struct Node *newnode = CreateNode(data);
    struct Node *ptr = header, *prev;
    int currentPos = 0;
    if(pos == 0)
    {
     newnode -> Rlink = header;
     header = newnode;
    }
    else
    {
        while(ptr != NULL && currentPos < pos )
        {
            prev = ptr;
            ptr = ptr -> Rlink;
            currentPos++;
        }
        if(currentPos == pos)
        {
            newnode -> Llink = prev;
            newnode -> Rlink = ptr;
            prev -> Rlink = newnode;
            if(ptr != NULL)
                ptr -> Llink = newnode;
        }
        else
        {
            printf("Position not found");
            free(newnode);
        }
    }
}
void traversal()
{
    struct Node *ptr;
    ptr = header;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->Rlink;
    }
    printf("\n");
}
int main()
{
    printf("Hello world!\n");
    insertAtFront(90);
    insertAtFront(80);
    insertAtEnd(10);
    traversal();
    insertAtAny(50,2);
    traversal();
    return 0;
}
