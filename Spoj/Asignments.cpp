#include <iostream>
#include <math.h>
#include <cstring>
#define sz 1 << 20
long long int res[20][sz];
int arr[20][20];

using namespace std;

long long int dynam_function(int n, int level, int val) {

    if(level >= n) {
        return 1;
    }

    if(res[level][val] != -1) {
        return res[level][val];
    }

    long long int chk = 1;
    long long int sum = 0;

    for(int i = 0; i<n; i++) {
        if(arr[level][i] == 1) {
            chk = 1 << i;
            if(!(chk & val)) {
                sum += dynam_function(n, level + 1, val | chk);
            }
        }
    }
    res[level][val] = sum;
    return sum;

}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        memset(res, -1, sizeof(res));
        long long int n;
        cin>>n;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cin>>arr[i][j];
            }
        }

        long long int sum = 0;

        sum = dynam_function(n, 0, 0);
        cout<<sum<<endl;
    }
    return 0;
}
