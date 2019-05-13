/*
ID: iyerarn1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;fin.open("beads.in");
    ofstream fout;fout.open("beads.out");

    int n; fin >> n;
    string s; fin >> s;
    s+=s;
    int maxlen = 0;
    for (int i = 0; i<2*n; i++) {
        char currchar;
        int len = 0;
        currchar = s[i];
        bool crossyet = false;
        for (int j = i; j<2*n; j++) {
            if (s[j] == 'w' || s[j] == currchar) {
                len++;
                continue;
            }
            else {
                if (currchar == 'w') {
                    currchar = s[j];
                    len++;
                    continue;
                }
                if (!crossyet) {
                    len++;
                    crossyet = true;
                    currchar = s[j];
                    continue;
                }
                else break;
            }
        }
        if (maxlen <len) maxlen = len;
    }
    if (maxlen > n) maxlen = n;
    fout << maxlen << endl;

    fin.close();
    fout.close();
    return 0;
}   