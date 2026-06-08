#include <iostream>
using namespace std;

struct Student {
    int id, a, b, sum;
};
bool better (Student x, Student y) {
    if (x.sum != y.sum) return x.sum > y.sum;
    if (x.b != y.b) return x.b > y.b;
    return x.id < y.id;
}
void quickSort(Student s[], int left, int right){
    int i = left, j = right;
    Student pivot = s[(left + right) / 2];

    while (i <= j){
        while (better(s[i], pivot)) i++;
        while (better(pivot, s[j])) j--;
        if (i <= j){
            Student temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--; 
        }
    }
    if (left < j) quickSort(s, left, j);
    if (i < right) quickSort(s, i, right);
}
int main(){ 
    int n;
    cin >> n;

    Student* s = new Student[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> s[i].id >> s[i].a >> s[i].b;
        s[i].sum = s[i].a + s[i].b;
    }

    quickSort(s, 1, n);

    for (int i = 1; i <= n; i++) {
        cout << s[i].id << " " << s[i].sum << endl;
    }

    delete[] s;

    return 0;
}