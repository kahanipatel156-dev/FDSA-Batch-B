#include <iostream>
#include <vector>
using namespace std;

int iterativeBinarySearch(vector<int> books, int target) {
    int low = 0, high = books.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (books[mid] == target)
            return mid;

        if (books[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int recursiveBinarySearch(vector<int> books, int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (books[mid] == target)
        return mid;

    if (books[mid] < target)
        return recursiveBinarySearch(books, mid + 1, high, target);
    else
        return recursiveBinarySearch(books, low, mid - 1, target);
}

int main() {
    int n;
    cout << "Enter number of book codes: ";
    cin >> n;

    vector<int> books(n);

    cout << "Enter sorted book codes:\n";
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int target;
    cout << "Enter target book code: ";
    cin >> target;

    int pos1 = iterativeBinarySearch(books, target);
    if (pos1 != -1)
        cout << "Iterative Binary Search: Found at position " << pos1 + 1 << endl;
    else
        cout << "Iterative Binary Search: Book code not found." << endl;


    int pos2 = recursiveBinarySearch(books, 0, n - 1, target);
    if (pos2 != -1)
        cout << "Recursive Binary Search: Found at position " << pos2 + 1 << endl;
    else
        cout << "Recursive Binary Search: Book code not found." << endl;

    return 0;
}
