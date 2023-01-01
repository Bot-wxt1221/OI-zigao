#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
bool compare(pair<int, int> buf1, pair<int, int> buf2)
{
	if (buf1.first == buf2.first)
		return buf1.second < buf2.second;
	else
		return buf1.first < buf2.first;
}
 
int main()
{
    int n;
	cin >> n;
	vector<pair<int, int>> envelope(n);
	vector<int> dp(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> envelope[i].first >> envelope[i].second;
	}
	sort(envelope.begin(), envelope.end(), compare);
	for (int i = 0; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (envelope[i].first > envelope[j].first && envelope[i].second > envelope[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}