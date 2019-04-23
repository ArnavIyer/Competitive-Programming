#include <iostream>
using namespace std;

int main() {
    int n; cin >>n;
    for (int i = 0; i<n; i++) {
        int x1, x2,y1,y2,xmid1, ymid1, xmid2, ymid2;
        char input;
        cin >> input >> y1;
        x1 = input - 'A' +1;
        cin >> input >> y2;
        x2 = input -'A' +1;
        if ((x1 +y1)%2 != (x2+y2)%2)  {
            cout << "Impossible" << endl;
            continue;
        }
        if (x1 == x2 && y1 == y2) {
            cout << 0 << " " << input << " " << y2 << endl;
            continue;
        }
        xmid1 = y2 + x2 -y1 + x1;
        xmid1 /= 2;
        ymid1 = xmid1 + y1 - x1;

        xmid2 = y1 + x1 - y2 + x2;
        xmid2 /= 2;
        ymid2 = xmid2 + y2-x2;

        if (xmid1<1 || ymid1<1 || xmid1>8 || ymid1>8) {
            xmid1 = xmid2;
            ymid1 = ymid2;
        }
        if (xmid1 == x2 && ymid1 == y2) {
            cout << 1 << " " << static_cast<char>(x1 + 'A' -1) << " " << y1 << " " << input << " " << y2 << endl;
            continue;
        }
        if (xmid1 == x1 && ymid1 == y1) {
            cout << 1 << " " << static_cast<char>(x1 + 'A' -1) << " " << y1 << " " << input << " " << y2 << endl;
            continue;
        }
        cout << 2 << " " << static_cast<char>(x1 + 'A' -1) << " " << y1 << " " << static_cast<char>(xmid1-1+'A') << " " << ymid1 << " " << input << " " << y2 << endl;
    }
}
