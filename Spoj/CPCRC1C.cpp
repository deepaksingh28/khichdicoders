    #include <iostream>
    #include <cstring>
    #define lli long long int
    int arr[10];
    lli parr[10];
    using namespace std;
    lli sumDigits(lli a) {

    	if (a <= 0)
    		return 0;

    	lli temp = a, sum = 0, val, prevval = 0;
    	int i = 9;
    	while (temp > 0) {
    		arr[i--] = temp % 10;
    		temp /= 10;
    	}
    	int length = 9 - i;
    	i++;
    	for (; i < 10; i++) {
    		val = ((arr[i] - 1) * arr[i]) / 2;
    		sum += prevval * arr[i] * parr[9 - i];
    		sum += val * parr[9 - i];
    		sum += arr[i] * parr[8 - i] * 45 * (9 - i);
    		//sum += arr[i] * parr[8 - i] * (45 * (9 - i) + prevval);
    		prevval += arr[i];
    	}

    	sum += prevval;
    	return sum;
    }

    int main() {
    	lli a, b, result;
    	parr[0] = 1;
    	for (int i = 1; i < 10; i++) {
    		parr[i] = parr[i - 1] * 10;
    	}
    	cin >> a >> b;
    	while (a != -1 && b != -1) {

    		result = sumDigits(b) - sumDigits(a - 1);
    		cout << result << "\n";
    		cin >> a >> b;
    	}

    }
