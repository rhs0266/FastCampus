#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> arr;
long long int ans[3];

void input()
{
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();

	sort(arr.begin(), arr.end());
	long long best = LONG_MAX; // 최소값 찾는 문제니까 초기값은 최대값

	for (int i = 0; i < n - 2; i++)
	{
		int left = i + 1, right = n - 1;

		while (left < right)
		{
			long long sum = arr[i] + arr[left] + arr[right];
			if (abs(best) > abs(sum)) // 기존 합보다 새로운 세 수의 합이 작으면 갱신
			{
				best = sum;
				ans[0] = arr[i];
				ans[1] = arr[left];
				ans[2] = arr[right];
			}

			if (sum > 0) // 세 수의 합이 양수면 더 작게 만들기
				right--;
			else if (sum < 0) // 세 수의 합이 음수면 더 크게 만들기
				left++;
			else // 합이 0이면 바로 끝내기
			{
				i = n;
				break;
			}
		}
	}

	sort(ans, ans + 3);
	for (auto num : ans)
	{
		cout << num << " ";
	}
	return 0;
}