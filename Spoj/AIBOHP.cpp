    #include <iostream>
    #include <cstring>
    using namespace std;
    int dp[6100][6100];

    int main() {

        int t;
        cin>>t;

        while(t--) {
            string str;
            cin>>str;
            int end = str.size() - 1;
            memset(dp, -1, sizeof(dp));
            int temp1, temp2;
            for(int i = end; i >= 0; i--) {
                for(int j = i; j <= end; j++) {

                    if(i == j) {
                        dp[i][j] = 0;
                        continue;
                    }

                    if(str[i] == str[j]) {

                        dp[i][j] = i+1 <= j-1 ? dp[i+1][j-1] : 0;
                    } else {
                        //The elsse part code will be here
                        temp1 = i+1 <= j ? dp[i+1][j] : 0;
                        temp2 = i <= j ? dp[i][j-1] : 0;
                        temp1 = temp1 > temp2  ? temp2 : temp1;
                        dp[i][j] = temp1 + 1;
                    }
                }
            }

            cout<<dp[0][end]<<"\n";
        }

        return 0;
    }
