#include <iostream>
#include <map>
#include <string>
using namespace std;
bool check(string temp) {
	string one = "RBL";
	string two = "RLB";
	string three = "LRB";
	string four = "LBR";
	string five = "BLR";
	string six = "BRL";
	if (temp == one ||temp == two ||temp == three ||temp == four ||temp == five ||temp == six) return true;
	else return false;
}
int main() {
	string buffer = "";
	map<char,char> a;
	a['R'] = 'S';
	a['B'] = 'K';
	a['L'] = 'H';
	char curr;
	while (cin >> curr) {
		//if (curr == 'a') break;
		buffer.push_back(curr);
	}	
	for (int i = 0; i<buffer.size();i++) {
		if (i > buffer.size()-3) {
			cout << a[buffer[i]];
			continue;
		}
		string temp;
		temp.push_back(buffer[i]);
		temp.push_back(buffer[i+1]);
		temp.push_back(buffer[i+2]);
		if (check(temp)) {
			cout << 'C';
			i += 2;
			continue;
		} else {
			cout << a[buffer[i]];
		}
	}
	return 0;
}
