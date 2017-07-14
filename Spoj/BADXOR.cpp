#include <iostream>
#include <cstring>
using namespace std;
#define lim 1024
#define mod 100000007
int arr[lim][2];

int main() {
	// your code goes here
	int t = 0,n,m,sum,s;
	cin>>s;
	while(t++ < s) {
	    memset(arr, 0, sizeof(arr));
	    arr[0][0] = 1;
	   cin>>n>>m;
	   int a[n];
	   int b[m];
	   for(int i = 0; i<n; i++) {
	       cin>>a[i];
	   }
	   for(int i = 0; i<m; i++) {
	       cin>>b[i];
	   }
	   for(int i = 0; i<n; i++) {
	       for(int j = 0; j<lim; j++) {
	           if(arr[j][0] > 0) {
	               int temp = a[i]^j;
	               if(temp > j) {
	                   arr[temp][1] += arr[j][0];
	                   arr[temp][1] = arr[temp][1] >= mod ? arr[temp][1]%mod : arr[temp][1];
	               } else {
	                   arr[temp][0] += arr[j][0];
	                   arr[temp][0] = arr[temp][0] >= mod ? arr[temp][0]%mod : arr[temp][0];
	               }
	           }
	           arr[j][0] += arr[j][1];
	            arr[j][0] = arr[j][0] >= mod ? arr[j][0]%mod : arr[j][0];
	           arr[j][1] = 0;
	       }
	   }
	   sum = 0;
	   for(int i = 0; i<m; i++)
	       arr[b[i]][1] = -1;


	   for(int i = 0; i<lim; i++) {
	       sum = arr[i][1] != -1 ? sum + arr[i][0] : sum;
	       sum = sum >= mod ? sum%mod : sum;
	   }

	   cout<<"Case "<<t<<": "<<sum<<endl;

	}
	return 0;
}
