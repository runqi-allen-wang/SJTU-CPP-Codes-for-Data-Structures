#include <iostream>
using namespace std;

struct Record{
    int id, level, time;
};
void mergeSort(Record a[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    Record *temp = new Record[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (a[i].level > a[j].level || (a[i].level == a[j].level && a[i].time <= a[j].time)) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (int p = 0; p < k; p++) {
        a[left + p] = temp[p];
    }
    delete[] temp;
}
int main(){
    int n;
    cin >> n;
    Record a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].level >> a[i].time;
        a[i].id = i;
    }
    mergeSort(a, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i].id << endl;
    }
    cout << endl;
    return 0;
}