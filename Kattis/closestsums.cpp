#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int getSum(vector<int> nums, int query);

int main() {
	int n;
	int count = 1;
	while(cin >> n) {
		cout << "Case " << count <<":" << endl; count++;
		vector<int> nums(n);
		for (int i = 0; i<n; i++) {
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		int qnum; cin >> qnum;
		for (int i = 0; i<qnum; i++) {
			int x; cin >> x;
			int ans = getSum(nums, x);
			cout << "Closest sum to " << x << " is " << ans <<"."<< endl;
		}
	}
}

int getSum(vector<int> nums,int query) {
	int i = 0;
	int j = nums.size()-1;
	int best = nums[i] + nums[j];
	while(i<j) {
		int curr = nums[i]+nums[j];
		if (curr == query) return query;
		if (abs(query-best)>abs(query-curr)) best = curr;
		else if (curr < query) {
			i++;
		}
		else {
			j--;
		}
	}
	return best;
}