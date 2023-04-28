#include <iostream>
#include <vector>
using namespace std;

void getSubseq(int index, vector<int>& arr, vector<vector<int>>& combineArr, vector<int> arr2) {
	if (index >= arr.size()) {
		combineArr.push_back(arr2);
		return;
	}
	getSubseq(index + 1, arr, combineArr, arr2);
	arr2.push_back(arr.at(index));
	getSubseq(index + 1, arr, combineArr, arr2);
}

int getMaxModulo(vector<vector<int>>& combineArr, int m) {
	int max = 0;
	for (vector<int>& e : combineArr) {
		if (e.empty()) {
			continue;
		}
		long long sum = 0;
		for (int i : e) {
			sum += i;
		}
		max = max >= (sum % m) ? max : (sum % m);
	}
	return max;
}

int main() {
	int n = 1;
	int m = 1;
	cin >> n >> m;
	vector<int> inputArr;
	for (int i = 0; i < n; i++) {
		int value = 0;
		cin >> value;
		inputArr.push_back(value);
	}
	vector<vector<int>> combineArr;
	getSubseq(0, inputArr, combineArr, vector<int>());
	cout << getMaxModulo(combineArr, m) << endl;
	return 0;
}
