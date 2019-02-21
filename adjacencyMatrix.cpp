#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int v;

    cout<<"Enter the no of nodes: ";
    cin>>v;
    int arr[v][v]={};

    for(int i=0; i<v; i++){
        int temp,temp2;
        cout<<"Enter no of nodes connected with node "<<i+1<<":";
         cin>>temp;
        for(int j=0; j<temp;j++){
        cout<<"Node "<<i+1<<" => ";
         cin>>temp2;
         arr[i][temp2-1]=1; 
        }

    }
cout<<"\nThe Matrix: "<<endl;
    for(int k=0; k<v; k++){
        for(int l=0; l<v; l++){
            cout<<setw(4);
            cout<<arr[k][l];

        }
        cout<<endl;
    }

    return 0;
}
