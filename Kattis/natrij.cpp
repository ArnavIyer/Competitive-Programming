#include <iostream>
#include <cmath>
using namespace std;

struct pt {
    int x;
    int y;
};

int main() {

    pt butt;


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
                        butt.x = n;
                        butt.y = m;
                    }
                }
            }
            num += abs(butt.x - i) + abs(butt.y - j);
            
        }
    }

    cout << num << endl;
    return 0;
}