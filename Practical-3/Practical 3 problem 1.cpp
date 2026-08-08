#include <iostream>
using namespace std;


void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);

    cout << "Bubble Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[i], a[min]);
    }

    cout << "Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int a[n], b[n], c[n];

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }

    bubbleSort(a,n);
    selectionSort(b,n);
    insertionSort(c,n);

    return 0;
}
