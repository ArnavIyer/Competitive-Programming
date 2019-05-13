/*
ID: iyerarn1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <vector>

using namespace std;
bool none = true;

char key[10][4] = { "   ","   ","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};

int main() {
    ifstream dict("dict.txt");
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    vector<string> a;

    for (int i = 0; i<4617; i++) {
        string temp; dict >> temp;
        a.push_back(temp);
    }

    string num;
    fin >> num;

    for (int i = 0; i<4617; i++) {
        if (a[i].size() != num.size()) continue;
        for (int j = 0; j<num.size(); j++) {
            if (a[i][j]!=key[static_cast<int>(num[j]-'0')][0]&&a[i][j]!=key[static_cast<int>(num[j]-'0')][1]&&a[i][j]!=key[static_cast<int>(num[j]-'0')][2]) break;
            if (j == num.size()-1) {
                fout << a[i] << endl;
                none = false;
            }
        }
    }

    if (none) fout << "NONE" << endl;

    return 0;
}

