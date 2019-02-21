#include <iostream>
#include <cstdlib>
using namespace std;


class node{
    public:
    int data;
    node *next;
    
};
node* head;






int main()
{
    int v;
    node *A[v];
    cout<<"\n Enter the no of vertices: ";
    cin>>v;
    
    for(int i=0; i<v; i++){
    int n=0;
    cout<<"\n Enter the no of node connected with node "<<i+1<<" :";
    cin>>n;
    head=NULL;

    for(int j=0; j<n; j++){
    cout<<"\n Enter the node: ";
    int x;
    node *temp=new node;
    
    cin>>x;
    temp->data=x;
    if(head==NULL){
        
        head=temp;
        temp->next=NULL;
    }
    else{
        
        node *temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
        temp->next=NULL;

    }
   
    }
    
    A[i]=head;
    }

//print the adjacency list.

cout<<"\n------------------->Adjacency List for the given Graph is as follows: <----------------------\n";
    for(int k=0; k<v; k++){
        node *temp3=A[k];
        cout<<k+1<<"|";
        while(temp3!=NULL){
        cout<<"->"<<temp3->data;
        temp3=temp3->next;
    }
    cout<<endl;
    }

return 0;
}