    #include <iostream>
    #include <cstring>
    using namespace std;
    int arr1[16];
    int arr2[16];
    int arr3[16][16];
    int dp[16][65536];

    int dynam_func(int n, int val, int lev) {

    	if (lev >= n) {
    		return 0;
    	}

    	if (dp[lev][val] != -1) {
    		return dp[lev][val];
    	}

    	int minm = 10000, temp;
    	int chk;
    	for (int i = 0; i < n; i++) {
    		chk = 1 << i;
    		if (!(val & chk)) {
    			temp = dynam_func(n, val | chk, lev + 1) + arr3[lev][i];
    			minm = temp < minm ? temp : minm;
    		}
    	}

    	return dp[lev][val] = minm;
    }


    int main() {

    	int n;
    	cin >> n;
    	while (n != 0) {
    		int diff1, diff2;

    		for (int i = 0; i < n; i++) {
    			cin >> arr1[i];
    		}

    		for (int i = 0; i < n; i++) {
    			cin >> arr2[i];
    		}


    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < n; j++) {
    				diff1 = j - i >= 0 ? j - i : i - j;
    				diff2 = arr1[i] >= arr2[j] ? arr1[i] - arr2[j] : arr2[j] - arr1[i];
    				arr3[i][j] = diff1 + diff2;
    			}
    		}

    		memset(dp, -1, sizeof(dp));

    		cout << dynam_func(n, 0, 0) << "\n";
    		cin >> n;
    	}
    }
