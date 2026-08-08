#include <iostream>
#include <vector>
#include <string>
using namespace std;

int iterativeSearch(vector<string> plates, string target) {
    for (int i = 0; i < plates.size(); i++) {
        if (plates[i] == target)
            return i;
    }
    return -1;
}


int recursiveSearch(vector<string> plates, string target, int index) {
    if (index >= plates.size())
        return -1;

    if (plates[index] == target)
        return index;

    return recursiveSearch(plates, target, index + 1);
}

int main() {
    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    vector<string> plates(n);

    cout << "Enter license plate numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    string target;
    cout << "Enter target license plate: ";
    cin >> target;


    int pos1 = iterativeSearch(plates, target);
    if (pos1 != -1)
        cout << "Iterative Search: Found at position " << pos1 + 1 << endl;
    else
        cout << "Iterative Search: License plate not found." << endl;


    int pos2 = recursiveSearch(plates, target, 0);
    if (pos2 != -1)
        cout << "Recursive Search: Found at position " << pos2 + 1 << endl;
    else
        cout << "Recursive Search: License plate not found." << endl;

    return 0;
}
