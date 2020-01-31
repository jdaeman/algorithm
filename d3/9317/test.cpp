#include <iostream>

using namespace std;

char str1[100001];
char str2[100001];

int solution()
{
	int N;
	int ret = 0;

	cin >> N;
	cin >> str1;
	cin >> str2;

	for (int i = 0; i < N; i++)
	{
		if (str1[i] == str2[i])
			ret += 1;
	}

	return ret;
}

int main(int argc, char ** argv)
{
	int TC;
	
	cin >> TC;

	for (int cnt = 1; cnt <= TC; cnt++)
	{
		int ans = solution();
		printf("#%d %d\n", cnt, ans);
	}

	return 0;
}
