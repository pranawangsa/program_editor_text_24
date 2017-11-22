#include <stdio.h>
#include <stdlib.h>
typedef struct word
{
    char alph;
    struct word *next,*prev;
}word;
word *head=NULL,*tail=NULL,*prnt=NULL,*active=NULL;//head=first char

void print();
void add();
void del();
void lshift();
void rshift();

void menu()
{
    system("cls");
    fflush(stdin);
    int pil;
    printf("1. Print\n2. Add Char\n3. Delete Char\n4. Shift Left\n5. Shift Right\n\n");
    scanf("%d",&pil);
    switch(pil)
    {
        case 1 : print();break;
        case 2 : add();break;
        case 3 : del();break;
        case 4 : lshift();break;
        case 5 : rshift();break;
        default : menu();
    }
}
void print()
{
    if(head!=NULL)
    {
        prnt=head;
        if (head==tail) printf("%c",prnt->alph);
        else
        {
            while(prnt!=NULL)
            {
              printf("%c",prnt->alph);
              prnt=prnt->next;
            }
        }
    }
    printf("\n");
}
void add()
{
    prnt=(word*)malloc(sizeof(word));
    if(head!=NULL)
    {
        if(active!=tail)
        {
            prnt->next=active->next;
            prnt->prev=active;
            active->next->prev=prnt;
            active->next=prnt;
            if(active==head->prev) head=head->prev;
            active=active->next;
        }
        else
        {
            active->next=prnt;
            prnt->prev=active;
            prnt->next=NULL;
            active=active->next;
            tail=active;
        }
    }
    else
    {
        head=prnt;
        head->next=NULL;
        prnt=(word*)malloc(sizeof(word));//one block behind head
        head->prev=prnt;
        prnt->prev=NULL;
        tail=prnt;
        active=prnt;
    }
    printf("Word : ");
    scanf("%s",&active->alph);
}
void del()
{
    if(head==tail)
    {
        free(head->prev);
        free(head);
        head=NULL;
        tail=NULL;
        active=NULL;
    }
    else if(active==tail)
    {
        active=active->prev;
        active->next=NULL;
        free(tail);
        tail=active;
    }
    else if(active==head)
    {
        active=active->next;
        head=head->prev;
        active->prev=head;
        free(head->next);
        head->next=active;
        head=active;
    }
    else if(active==head->prev);
    else
    {
        prnt=active->next;
        active=active->prev;
        prnt->next=active;
        free(active->prev);
        prnt->prev=active;
    }
}
void lshift()
{
    if(active->prev!=NULL)active=active->prev;
}
void rshift()
{
    if(active->next!=NULL)active=active->next;
}
int main()
{
    int i;
    printf("Masukkan jumlah input : ");
    scanf("%d",&i);
    for(i;i>0;i--) menu();
    return 0;
}
