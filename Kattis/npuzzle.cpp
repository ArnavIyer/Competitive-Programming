#include <iostream>
#include <cmath>
using namespace std;

struct p {
    int x;
    int y;
};

int main() {

    p b;


    int num = 0;

    char a[4][4];
    char f[4][4];
    char ct = 'A';
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) {
            if (ct == 'P') ct = '.';
            f[i][j] = ct;
            ct++;
        }
    }
    
    //for each letter
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) {

            //ignore the dot
            if (a[i][j] == '.') continue;

            for (int n = 0; n<4; n++) {
                for (int m = 0; m<4; m++) {
                    if (f[n][m]==a[i][j]) {
                        b.x = n;
                        b.y = m;
                    }
                }
            }
            num += abs(b.x - i) + abs(b.y - j);
            
        }
    }

    cout << num << endl;
    return 0;
}
