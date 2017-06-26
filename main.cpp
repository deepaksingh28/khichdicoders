#include <iostream>
#include "dsk.h"

using namespace std;

void merge(int arr[], int start, int mid, int end) {

    if(start >= end)
        return;
    int left[mid-start + 1];
    int right[end-mid];
    for(int i = start; i<= mid; i++) {
        left[i-start] = arr[i];
    }
    for(int i = mid+1; i<=end; i++) {
        right[i-mid-1] = arr[i];
    }
    int i = 0, j = 0, k = start;
    while(i < mid-start+1 && j < end-mid && k <= end) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i <= mid - start) {
        arr[k] = left[i];
        k++;
        i++;
    }
}

void mergesort(int arr[], int start, int end) {

    if(start >= end)
        return;
    int mid = (start + end)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main()
{
    cout << "Hello world123!" << endl;
    int opr, val;

/*    bin_heap hp;  // = new bin_heap();
    while(true) {
        cin>>opr;
        if(opr == 0) {
            cin>>val;
            hp.insert(val);
        }
        else if(opr == 1) {
            cout<<"Min is: "<<hp.extract_min()<<"\n";
        }
        else if(opr == 2) {
            hp.print_heap();
        } else {
            break;
        }
    }
*/
    fib_heap fhp;  // = new bin_heap();
    while(true) {
        cin>>opr;
        if(opr == 0) {
            cin>>val;
            fhp.insert(val);
        }
        else if(opr == 1) {
            cout<<"Min is: "<<fhp.extract_min()<<"\n";
        }
        else if(opr == 2) {
            fhp.print_heap();
        } else {
            break;
        }
    }
    return 0;
}
