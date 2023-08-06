#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countElements(int x, vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> freq; // Stores the frequency of each element
    int count = 0; // Keeps track of the maximum number of elements we can remove
    
    for (int i = 0; i < n; i++) {
        // Check if removing the current element exceeds the limit 'X'
cout<<freq[a[i]]<<" ";
    }
    for (int i = 0; i < n; i++) {
        // Check if removing the current element exceeds the limit 'X'
        if (freq[a[i]] < x) {
            freq[a[i]]++;
            count++;
        }
    }

    return count;
}

int main() {
    int x, n;
    cin >> x >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = countElements(x, a);
    cout << result << endl;

    return 0;
}
