/*
ID: iyerarn1
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n; fin >> n;

    vector<pair<int,int>> t;

    for (int i = 0; i<n; i++) {
        pair<int,int> temp;
        int a,b;
        fin >> a >> b;
        temp = make_pair(a,b);
        t.push_back(temp);
    }

    sort(t.begin(), t.end());
    int i = 0;
    int ans1 = 0;
    int ans2 = 0;

    while (i<n) {
        int j = i;
        int max = t[i].second;
        while (j <n && max >= t[j].first) {
            if (max < t[j].second) max = t[j].second;
            j++;
        }
        if (ans2 < t[j].first - max) ans2 = t[j].first - max;
        j--;
        if (ans1 < max - t[i].first) ans1 = max - t[i].first;
        i = j+1;
    }

    fout << ans1 << " " << ans2 <<  endl;
    return 0;
}