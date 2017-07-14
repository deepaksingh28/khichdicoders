    #include <iostream>
    #include <cstring>
    #define lim 100
    using namespace std;
    int arr[lim][lim][lim];
     
    int maxi(int a, int b) {
        return a > b ? a : b;
    }
     
    int blessing(string str1, string str2, int a, int b, int n1, int n2, int k) {
        if(arr[a][b][k] != -1) {
            return arr[a][b][k];
        }
     
        if(k == 0 || k > n1-a || k > n2-b) {
            return arr[a][b][k] = 0;
        }
     
        if(str1[a] == str2[b]) {
            //cout<<"start "<<a<<" "<<b<<" "<<k<<"\n";
            arr[a+1][b+1][k] = blessing(str1, str2, a+1, b+1, n1, n2, k);
            arr[a+1][b+1][k-1] = blessing(str1, str2, a+1, b+1, n1, n2, k-1);
            int temp = arr[a+1][b+1][k-1] > 0 ? arr[a+1][b+1][k-1] + (int)str1[a] : k-1 == 0 ? (int)str1[a] : 0;
            return arr[a][b][k] = temp > arr[a+1][b+1][k] ? temp : arr[a+1][b+1][k];
        } else {
            return arr[a][b][k] = maxi(blessing(str1, str2, a+1, b, n1, n2, k), blessing(str1, str2, a, b+1, n1, n2, k));
        }
    }
    int main() {
        int t;
        cin>>t;
        while(t--) {
            memset(arr, -1, sizeof(arr));
            string str1, str2;
            cin>>str1>>str2;
            int k;
            cin>>k;
            cout<<blessing(str1, str2, 0, 0, str1.size(), str2.size(), k)<<endl;
     
        }
    }

