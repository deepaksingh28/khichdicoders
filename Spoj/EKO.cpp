//============================================================================
// Name        : Spoj_Submissions.cpp
// Author      : dks
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define lli long long int

int bin_search(lli arr[], lli start, lli end, lli val) {

	if(start >= end) {
		if(arr[start] >= val){
			return start;
		} else {
			return start+1;
		}
	}

	int mid = (start + end)/2;

	if(arr[mid] == val) {
		return mid;
	}

	if(arr[mid] > val) {
		end = mid-1;
	} else {
		start = mid + 1;
	}

	return bin_search(arr, start, end, val);
}

int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	lli n,m, maxm = -1, sum = 0, temp, val;
	lli mid, start, end, res = 0;
			;
	scanf("%lld %lld", &n, &m);
	lli arr[n], arr1[n];

	for(int i = 0; i<n; i++) {
		scanf("%lld", &arr[i]);
		maxm = arr[i] > maxm ? arr[i] : maxm;
	}

	sort(arr, arr + n);

	for(int i = 0; i<n; i++) {
		sum += arr[i];
		arr1[i] = sum;
	}

	start = 0;
	end = maxm;

	while(start <= end) {
		mid = (start + end)/2;
		temp = bin_search(arr, 0, n-1, mid);
		if(temp < n) {
			val = temp > 0 ? arr1[temp-1] : 0;
			val += (n-temp) * mid;
			val = arr1[n-1] - val;
			if(val == m) {
				printf("%lld\n", mid);
				return 0;
			}
			if(val > m) {
				start = mid+1;
				res = res < mid ? mid : res;
			} else {
				end = mid - 1;
			}
		}
	}

	/*temp = bin_search(arr, 0, n-1, start);

	if(temp < n) {
		val = temp > 0 ? arr1[temp-1] : 0;
		val += (n-temp) * mid;
		val = arr1[n-1] - val;
		if(val == m) {
			printf("%lld\n", start);
			return 0;
		}
		if(val > m) {
			printf("%lld\n", start);

		} else {
			printf("%lld\n", start + 1);
		}
	}*/


	printf("%lld\n", res);


	return 0;
}
