#include <iostream>

using namespace std;

int N, M;
int vals[1000];

int solution(void)
{
	int max = -1;

	scanf("%d %d", &N, &M);
	for (int idx = 0; idx < N; idx++)
	{
		scanf("%d", &vals[idx]);
	}

	for (int f = 0; f < N; f++)
	{
		for (int s = f + 1; s < N; s++)
		{
			int v = vals[f] + vals[s];
			if (v <= M && v > max)
				max = v;
		}
	}	

	return max;
}


int main(int argc, char ** argv)
{
	int T;

	scanf("%d", &T);

	for (int cnt = 1; cnt <= T; cnt++)
	{
		int ans = solution();
		printf("#%d %d\n", cnt, ans);
	}

	return 0;
}
