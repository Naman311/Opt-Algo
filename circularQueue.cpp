#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next=NULL;
}*front,*rear,*temp,*it;

void create_node()
{
    temp= new node;
    cin>>temp->data;
}
void insert()
{
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        temp->next=front;
        rear->next=temp;
        rear=temp;
    }
}
void deletion()
{
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
        rear->next=front;
    }
}
void display()
{
    if(front==NULL)
    {
        cout<<"empty";
    }
    else
    {
        it=front;
        if(front==rear)
        {
            cout<<front->data;
        }
        else
        {
            while(it->next!=front)
            {
                cout<<it->data<<" ";
                it=it->next;
            }
            cout<<it->data<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int choice=0;
    while(choice!=3)
    {
        cout<<"chose \n1.Insert\n2.Deletion\n3.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                create_node();
                insert();
                display();
                break;
            case 2:
                deletion();
                display();
                break;
            case 3:
                return 0;
            default:cout<<"Wrong choice";
        }
    }
    return 0;
}
