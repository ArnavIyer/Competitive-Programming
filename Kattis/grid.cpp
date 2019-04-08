#include <iostream>
#include <list>
#include <set>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
	//set<int> used;
	int n,m; cin >> n >> m;
	int num = n*m;
	int adj[num][num] = {0};
	//cout << adj[0][2] << endl << endl;
	for (int i = 0; i<n*m; i++) {
			adj[0][i] = 0;
	}	
	for (int i = 0; i<n; i++) {	
		for (int j = 0; j<m; j++) {
			//if (i == 4 && j == 2) cout << "D ' " << endl;
			//cout << i << " " << j << endl;
			int x; cin >> x;	
			for (int z=0;z<4;z++) {
				if (dx[z]*x+i < 0 || dx[z]*x+i >= n || dy[z]*x +j<0 || dy[z]*x +j>=m) {continue;}
				adj[i*m+j][(i+dx[z]*x)*m+j+dy[z]*x] = 1;//i=4,j=1,z=1
			}
		}
	}
	
	for (int i = 0; i<n*m; i++) {
		for (int j = 0 ; j<n*m; j++) {
			cout << adj[i][j];
		}
		cout << endl;
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
		//used.insert(s);
		cout << s << " ";
		queue.pop_front();
		count++;
		for (int i = 0; i<n*m; i++) {
			if (adj[s][i]!=1) continue;
			if (!visited[i]) {
				if (i == n*m-1) {
					done = true;
					break;
				}
				visited[i] = true;
				queue.push_back(i);
			}
		}
		if (done) break;
	}
	if (done) cout << "end" << " "<< count<< endl;
	//cout << endl << used.size() << endl;
}