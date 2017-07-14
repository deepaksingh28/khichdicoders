#include <iostream>

using namespace std;
int Partition(int arr[] , int left , int right ){
    int pivot = arr[right];
    int pindex = left;
    for(int i= left ; i < right ;i ++){
    if(arr[i]<pivot){
        swap(arr[i],arr[pindex]);
        pindex++;
      }
    }
    swap(arr[pindex],arr[right]);
    return pindex;
}

int Kthsmallest(int arr[], int left , int right ,int k){

    int p = Partition(arr,left , right);
    if (k==p)
        return arr[p];
    else if (p< k)
        Kthsmallest(arr , p+1 ,right ,k);
    else
        Kthsmallest(arr ,left , p-1 ,k);
}
int main()
{
   int arr[] = {6,3,2,7,4};
   int result =Kthsmallest(arr , 0 ,5 ,0);
   cout<< result;
   return 0;
}
