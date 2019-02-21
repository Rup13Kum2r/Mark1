#include <iostream>
#include <fstream>

using namespace std;

int hsCmp=0;
int max_heapify(int arr[],int n,int i){
    int flag=0;
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]){
    largest=l;   
}
flag++;
   
    if(r<n && arr[r]>arr[largest]){
    largest=r;
}
flag++;

    if(largest!= i){
        flag++;
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
    return flag;
}

void build_maxheap(int arr[],int n){
    for(int i=n/2-1;i>=0; i--)
    hsCmp+=max_heapify(arr,n,i);
}

void heapSort(int arr[],int n){

    build_maxheap(arr,n);
    for(int j=n-1; j>=0; j--){
        swap(arr[0],arr[j]);
        hsCmp+=max_heapify(arr,j,0);
    }

}

int main(){
    
    int s;
    int *arr;
   
    fstream obj;
    obj.open("CmpFileHeap.csv", ios::out);
    if (obj)
    {
        obj << "Size"<< "\t"<<"HeapSort"<< endl;
    }
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {

        s = rand() % 970 + 30; //100 arrays of different sizes.
        arr = new int[s];

        //take random inputs.

        for (int j = 0; j < s; j++)
        {
            arr[j] = rand(); //fill every time with different number.
        }
       

        

        cout << "\n--------------->HEAP SORT<-----------------\n";
        heapSort(arr,s);
        cout<<"Size: \t"<<s<<endl;
        cout<<"No of comparisons: "<<hsCmp<<endl;


        if (obj)
        {
            obj << s << "\t"<<hsCmp<<endl;
        }
    
        hsCmp=0;
    }
    obj.close();
    return 0;
}