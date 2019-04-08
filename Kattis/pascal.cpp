#include <iostream>
#include <cmath>
using namespace std;

int bf(int n) {
	if (n % 2 == 0) return n/2;
	else {
		for (int i = 3; i<=pow(n,0.5); i += 2) {
			if ((n/i)*i ==n) {
				return n/i;
			}
			else  cout << endl;
		}
	}
	return 1;
}
int main() {
	int n; cin >> n;
	cout << n - bf(n) << endl;
	return 0;
}

