#include <iostream>
#include <fstream>

using namespace std;

static int msCmp=0;
static int hsCmp=0;

int insertionSort(int arr[], int n)
{
    int value, i, hole;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        value = arr[i];
        hole = i;
        while (hole>0 && arr[hole-1]>value)
        {
            arr[hole] = arr[hole-1];
            hole--;
            count++;
        }
        arr[hole] = value;
    }
    
    cout << "No. of comparisons are: " << count << endl;
    return count;
}

int bubbleSort(int arr[], int n)
{
    int flag = 0;
    int i, j;
    for (i=1; i<n; i++)
    {
        for (j=0; j<n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
            flag++;
        }

       }
    cout << "No. of comparisons are: " <<flag<< endl;
    return flag;
}


int Merge(int arrL[],int l_size,int arrR[],int r_size,int arr[],int arr_size){
    int i=0,j=0,k=0;
    int mflag=0;
    while(i<l_size && j<r_size){
        if(arrL[i] <= arrR[j]){
            arr[k]=arrL[i];
            i++;
            
        }

        else{
            arr[k]=arrR[j];
            j++;
        }
        k++;
        mflag++;
    }

    while(i<l_size){
    arr[k]=arrL[i];
    i++;
    k++;
    mflag++;
    }

    while(j<r_size){
    arr[k]=arrR[j];
    j++;
    k++;
    mflag++;
    }
    return mflag;
}


void mergeSort(int arr[], int arr_size){

    if(arr_size<2) return;

    int mid=arr_size/2;

    int l_size=mid;
    int r_size=arr_size-mid;

    int arrL[l_size],arrR[r_size];

    for(int i=0; i<mid; i++){
        arrL[i]=arr[i];
    }
    for(int j=mid; j<arr_size; j++){
        arrR[j-mid]=arr[j];
    }

    mergeSort(arrL,l_size);
    mergeSort(arrR,r_size);
    msCmp+=Merge(arrL,l_size,arrR,r_size,arr,arr_size);
    
}

int max_heapify(int arr[],int n,int i){
    int hflag=0;
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]){
    largest=l;   
}
hflag++;
   
    if(r<n && arr[r]>arr[largest]){
    largest=r;
}
hflag++;

    if(largest!= i){
        hflag++;
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
    return hflag;
}

void build_max_heap(int arr[],int n){
    for(int i=n/2-1; i>=0; i--)
        hsCmp+=max_heapify(arr,n,i);
}

void heapSort(int arr[],int n){
    
    build_max_heap(arr,n);

    for(int j=n-1; j>=0; j--){
        swap(arr[0],arr[j]);
        hsCmp+=max_heapify(arr,j,0);
    }

}





int main() {
    int s, c1,c2,c3;
    int *arr;
    int strt, endt;
    fstream obj;
    obj.open("CmpFile.csv", ios::out);
    if (obj)
    {
        obj << "Size"<< "\t"<< "InsertionCmp"<<"\t"<<"BubbleCmp" <<"\t"<<"MergeSort"<<"\t"<<"HeapSort"<< endl;
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
       

        cout << "\n--------->INSERTION SORT<-----------\n";
        c1 = insertionSort(arr, s); //sort using insertion
     
        cout << "\n--------------->BUBBLE SORT<-----------------\n";
        c2 = bubbleSort(arr,s);

        cout << "\n--------------->MERGE SORT<-----------------\n";
        mergeSort(arr,s);
        cout<<"No of comparisons: "<<msCmp<<endl;

        cout << "\n--------------->HEAP SORT<-----------------\n";
        heapSort(arr,s);
        cout<<"No of comparisons: "<<hsCmp<<endl;


        if (obj)
        {
            obj << s << "\t" << c1<<"\t"<<c2 <<"\t"<<msCmp<<"\t"<<hsCmp<<endl;
        }
        msCmp=0;
        hsCmp=0;
    }
    obj.close();
    return 0;
}
