#include<iostrream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long h;
    cin >> h;

    h = h % n;


    for (int i = h; i < n; i++)
        cout << arr[i] << " ";

    for (int i = 0; i < h; i++)
        cout << arr[i] << " ";

    return 0;
}
