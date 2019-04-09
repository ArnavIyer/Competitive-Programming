#include <iostream>
#include <list>
#include <map>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
	map<int,int> ans;

	int n,m; cin >> n >> m;
	int V = n*m;
	list<int> *adj;
	adj = new list<int>[V];
		
	cin.ignore();
	string in;
	for (int i = 0; i<n; i++) {	
		getline(cin, in);
		for (int j = 0; j<m; j++) {
			int x = in[j] - '0';	
			for (int z=0;z<4;z++) {
				if (dx[z]*x+i < 0 || dx[z]*x+i >= n || dy[z]*x +j<0 || dy[z]*x +j>=m) {continue;}
				adj[i*m+j].push_back((i+dx[z]*x)*m+j+dy[z]*x);
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
	list<int>::iterator i;
	while(!queue.empty()) {
		s = queue.front();
		queue.pop_front();
		for (i = adj[s].begin(); i!=adj[s].end(); i++) {
			if (!visited[*i]) {
				if (*i == n*m-1) {
					done = true;
					ans[n*m-1] = s;
					break;
				}
				visited[*i] = true;
				queue.push_back(*i);
				ans[*i] = s;
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
