#include <iostream>

using namespace std;

int n, m;
int board[50][50];


int solution()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
			scanf("%d", &board[y][x]);
	}

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
