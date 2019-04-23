#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
   
    
    while (n!=0 && m!=0) {
        unordered_set<int> jack;
        int count = 0;
        for (int i = 0; i<n; i++) {
            int x; cin >> x;
            jack.insert(x);
        }
        for (int i = 0; i<m; i++) {
            int x; cin >> x;
            if (jack.count(x)) count++;
        }
        cout << count << endl;
        cin >> n >> m;
    }

}