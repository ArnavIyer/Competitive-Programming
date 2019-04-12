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
	int prev=nums[i]+nums[j];
	if (nums[i] + nums[j] == query) return query;
	else if (nums[i] + nums[j] < query) {
		i++;
	}
	else j--;
	int curr;
	while(i<j) {
		curr = nums[i] + nums[j];
		if (curr == query) return query;
		if (abs(query-prev)<abs(query-curr)) return prev;
		else {
			if (curr < query) {
				i++;
			}
			else j--;
		}
		prev = curr;
	}
	return curr;
}