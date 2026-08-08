#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> seen, duplicates;

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        if (seen.count(id))
            duplicates.insert(id);
        else
            seen.insert(id);
    }

    if (duplicates.empty()) {
        cout << "No duplicate book IDs";
    } else {
        for (int id : duplicates)
            cout << id << " ";
    }

    return 0;
}
