#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
int N, room[2000005], count1;
priority_queue< int, vector<int>, greater<int> > pq;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main()
{
	cin >> N;
	vector<pair<int, int>> time;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		time.emplace_back(a, b);
	}

	sort(time.begin(), time.end(), comp);
	pq.push(time[0].second);

	for (int i = 1; i < N; i++) {
		if (time[i].first < pq.top())
			pq.push(time[i].second);
		else {
			pq.pop();
			pq.push(time[i].second);
		}	
	}
	cout << pq.size();
}