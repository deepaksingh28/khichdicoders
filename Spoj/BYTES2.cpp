    #include <iostream>
    #include <cstring>
    using namespace std;
    int dp[100][100];
    int arr[100][100];

    int dynam_func(int i, int j, int h, int w) {

        if(i >= h || i < 0 || j >= w || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int temp1 = dynam_func(i+1, j, h, w);
        int temp2 = dynam_func(i+1, j-1, h, w);
        int temp3 = dynam_func(i+1, j+1, h, w);

        int temp4 = temp1 >= temp2 ? temp1 >= temp3 ? temp1 : temp3 : temp2 > temp3 ? temp2 : temp3;
        return dp[i][j] = temp4 + arr[i][j];
    }

    int main() {

        int t;
        cin>>t;

        while(t--) {

            int w, h;
            cin>>h>>w;
            memset(dp, -1, sizeof(dp));

            for(int i = 0; i<h; i++) {
                for(int j = 0; j<w; j++) {
                    cin>>arr[i][j];
                }
            }

            int maxm = -1, temp;

            for(int i = 0; i<w; i++) {
                temp = dynam_func(0, i, h, w);
                maxm = temp > maxm ? temp : maxm;
            }

            cout<<maxm<<"\n";
        }
        return 0;
    }
