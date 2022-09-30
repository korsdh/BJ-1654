#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned int> vec;
unsigned int maxNum = 0;
unsigned int N, k;
unsigned int result = 0;

void bns(unsigned int low, unsigned int high) {
	unsigned int mid = (low + high) / 2;
	while (low <= high) {
		unsigned int now = 0;
		for (int i = 0; i < vec.size(); i++) {
			now += vec[i] / mid;
		}
		if (now >= N) {
			low = mid + 1;
			result = max(result, mid);
		}
		else {
			high = mid - 1;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> k >> N;
	for (int i = 0; i < k; i++) {
		unsigned int a;
		cin >> a;
		vec.push_back(a);
		maxNum = max(a, maxNum);
	}
	bns(1, maxNum);
	cout << result << "\n";
	return 0;
}