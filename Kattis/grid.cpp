#include <iostream>
#include <list>
#include <map>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
	map<int,int> ans;
	int n,m; cin >> n >> m;
	int num = n*m;
	int adj[num][num] = {0};
	for (int i = 0; i<n*m; i++) {
			adj[0][i] = 0;
	}
	cin.ignore();
	string in;
	for (int i = 0; i<n; i++) {	
		getline(cin, in);
		for (int j = 0; j<m; j++) {
			int x = in[j] - '0';	
			for (int z=0;z<4;z++) {
				if (dx[z]*x+i < 0 || dx[z]*x+i >= n || dy[z]*x +j<0 || dy[z]*x +j>=m) {continue;}
				adj[i*m+j][(i+dx[z]*x)*m+j+dy[z]*x] = 1;//i=4,j=1,z=1
			}
		}
	}
	int s = 0;
	bool visited[n*m] = {false};
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	bool done = false;
	int count = 0;
	while(!queue.empty()) {
		s = queue.front();
		queue.pop_front();
		for (int i = 0; i<n*m; i++) {
			if (adj[s][i]!=1) continue;
			if (!visited[i]) {
				if (i == n*m-1) {
					done = true;
					ans[n*m-1] = s;
					break;
				}
				visited[i] = true;
				queue.push_back(i);
				ans[i] = s;
			}
		}
		if (done) break;
	}
	int curr = n*m-1;
	while (curr != 0) {
		curr = ans[curr];
		count++;
	}
	if (done) cout << count<< endl;
	else cout << -1 << endl;
}
