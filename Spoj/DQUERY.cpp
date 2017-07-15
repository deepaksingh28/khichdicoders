    #include <iostream>
    #include <stdio.h>
    #include <string.h>
    int arr[2097152];
    int range[1000001];
    int query[200000][3];
    int res[200000];
    using namespace std;

void merge(int start, int mid, int end) {

    if(start >= end)
        return;
    int left[mid-start + 1][3];
    int right[end-mid][3];
    for(int i = start; i<= mid; i++) {
        left[i-start][0] = query[i][0];
        left[i-start][1] = query[i][1];
        left[i-start][2] = query[i][2];
    }
    for(int i = mid+1; i<=end; i++) {
        right[i-mid-1][0] = query[i][0];
        right[i-mid-1][1] = query[i][1];
        right[i-mid-1][2] = query[i][2];
    }
    int i = 0, j = 0, k = start;
    while(i < mid-start+1 && j < end-mid && k <= end) {
        if(left[i][1] <= right[j][1]) {
            query[k][0] = left[i][0];
            query[k][1] = left[i][1];
            query[k][2] = left[i][2];
            i++;
        } else {
            query[k][0] = right[j][0];
            query[k][1] = right[j][1];
            query[k][2] = right[j][2];
            j++;
        }
        k++;
    }
    while(i <= mid - start) {
        query[k][0] = left[i][0];
        query[k][1] = left[i][1];
        query[k][2] = left[i][2];
        k++;
        i++;
    }
}

void mergesort(int start, int end) {

    if(start >= end)
        return;
    int mid = (start + end)/2;
    mergesort(start, mid);
    mergesort(mid+1, end);
    merge(start, mid, end);
}

int executeQuery(int start, int end, int first, int last, int index) {

    if(start > end || start > last || end < first) {
        return 0;
    }

    if(start <= first && end >= last)
        return arr[index];


    int mid = (first + last)/2;

    return executeQuery(start, end, first, mid, index*2+1) + executeQuery(start, end, mid+1, last, index*2+2);

}


    int main() {

        int n, q,lindx, temp;
        scanf("%d", &n);
        temp = 2*n - 1;
        lindx = 1;
        while(temp > 0) {
            lindx *= 2;
            temp /= 2;
        }
        lindx -= 1;
        int values[n];


        for(int i = 0; i < n; i++) {
            scanf("%d", &values[i]);
        }

        scanf("%d", &q);
        for(int i = 0; i<q; i++) {
            scanf("%d %d", &query[i][0], &query[i][1]);
            query[i][0]--;
            query[i][1]--;
            query[i][2] = i;
        }

        mergesort(0, q-1);

        memset(range, -1, sizeof(range));
        int index = lindx/2, temp1, temp2, j = 0, qindex = 0;
        for(int i = index; i < index + n; i++) {
            if(range[values[j]] == -1) {
                range[values[j]] = i;
                temp1 = i;
                while(temp1 >= 0) {
                    arr[temp1]++;
                    if(temp1 == 0)
                        break;
                    temp1 = (temp1-1)/2;
                }
            } else {
                temp1 = range[values[j]];
                range[values[j]] = i;
                temp2 = i;
                while(temp1 != temp2) {
                    if(temp1 > temp2) {
                        arr[temp1]--;
                        temp1 = (temp1-1)/2;
                    } else {
                        arr[temp2]++;
                        temp2 = (temp2-1)/2;
                    }
                }

            }
            j++;

            while(query[qindex][1] < j && qindex < q) {
                temp1 = query[qindex][2];
                res[temp1] = executeQuery(query[qindex][0], query[qindex][1], 0, lindx/2, 0);
                qindex++;
            }

        }

        for(int i = 0; i<q; i++) {
            printf("%d\n", res[i]);
        }
    	return 0;
    }
