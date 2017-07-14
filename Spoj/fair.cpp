#include <iostream>

using namespace std;

int check(int val, int arr[], int n, int wrkr) {

    int i = 0, j = 0, sum = 0, maxm = 0;
    while(i < wrkr && j<n) {
        sum += arr[j];
        i = sum > val ? i+1 : i;
        maxm = sum > val && sum - arr[j] > maxm ? sum - arr[j] : maxm;
        sum = sum > val ? arr[j] : sum;
        if(sum > val) {
            return 0;
        }
        j++;
    }
    maxm = sum > maxm ? sum : maxm;
    return i < wrkr && j == n && sum <= val ? maxm : 0;

}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n, mina = 10000000, sum = 0, temp, lastmax = 0;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        mina = mina > arr[i] ? arr[i] : mina;
        sum += arr[i];
    }
    int wrkr;
    cin>>wrkr;
  //  cout<<sum<<" "<<mina;
    //cin>>wrkr;
    mina = sum/wrkr;
    while(sum > mina + 1) {
        int mid = (sum + mina)/2;
        if(temp = check(mid, arr, n, wrkr)) {
            lastmax = temp;
            sum = mid;
        } else {
            mina = mid;
        }
    }
    cout<<"sum is: "<<sum<<endl;
    cout<<"MaxValue is: "<<lastmax<<endl;
    }

    return 0;
}
