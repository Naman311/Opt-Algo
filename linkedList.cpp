#include<iostream>

using namespace std;

struct node
{
    int data;
    node *ptr=NULL;
}*head,*temp,*it;

void create_node()
{
    cout<<"Enter the value of node ";
    temp= new node;
    cin>>temp->data;
}
void in_beg()
{
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->ptr=head;
        head=temp;
    }
}
void in_mid()
{
    cout<<"Enter the position ";
    int pos;
    cin>>pos;
    it=head;
    for(int i=0;i<pos-1;i++)
    {
        it=it->ptr;
    }
    temp->ptr=it->ptr;
    it->ptr=temp;
    cout<<"Node inserted in the mid"<<endl;
}
void in_end()
{
   it=head;
   while(it->ptr!=NULL)
   {
       it=it->ptr;
   }
   it->ptr=temp;
}
void del_beg()
{
    if(head->ptr==NULL)
    {
        head=NULL;
    }
    else
    {
        head=head->ptr;
    }
}
void del_end()
{
    it=head;
    while((it->ptr)->ptr!=NULL)
    {
        it=it->ptr;
    }
    it->ptr=NULL;
}
void del_mid()
{
    cout<<"Enter the position ";
    int pos;
    cin>>pos;
    it=head;
    for(int i=0;i<pos-1;i++)
    {
        it=it->ptr;
    }
    it->ptr=(it->ptr)->ptr;
}
void display()
{
    cout<<"List is -"<<endl;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->ptr;
    }
    cout<<endl;
}
int main()
{
    int choice=0;
    while(choice!=7)
    {
        cout<<"chose \n1.Insert at beg\n2.Insert in mid\n3.Insert at end\n4.delete in the beg\n5.delete in end\n6.delete in the middle\n7.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                create_node();
                in_beg();
                display();
                break;
            case 2:
                create_node();
                in_mid();
                display();
                break;
            case 3:
                create_node();
                in_end();
                display();
                break;
            case 4:
                del_beg();
                display();
                break;
            case 5:
                del_end();
                display();
                break;
            case 6:
                del_mid();
                display();
                break;
            case 7:
                return 0;
            default:cout<<"Wrong choice";
        }
    }
}
