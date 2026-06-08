#include <iostream>
using namespace std;

const int MAXN = 300000 + 5;

int a[MAXN], b[MAXN], uniqueArr[MAXN];

void QuickSort(int* a, int left, int right) { 
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);  
}

int LowerBound(int* a, int right, int target) {
    int result = right + 1, left = 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    QuickSort(b, 1, n);

    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || b[i] != b[i - 1]) {
            uniqueArr[++m] = b[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << LowerBound(uniqueArr, m, a[i]);
        if (i < n) cout << " ";
    }

    return 0;
}