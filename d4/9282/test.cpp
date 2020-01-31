#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int board[50][50];
int table[50][50][50][50];

int cut(int r1, int r2, int c1, int c2)
{
	int v = 0;
	
	for (int y = r1; y < r2; y++)
	{
		for (int x = c1; x < c2; x++)
			v += board[y][x];
	}
	
	return v;
}

int divide(int r1, int r2, int c1, int c2)
{
	int cost = 0x7fffffff, tmp;
	
	if (r2 - r1 == 1 && c2 - c1 == 1)
		return 0;
	
	for (int y = r1 + 1; y < r2; y++)
	{
		int& u = table[r1][y - 1][c1][c2 - 1];
		int& d = table[y][r2 - 1][c1][c2 - 1];
		
		if (!u)
		{
			u = cut(r1, y, c1, c2);
			u += divide(r1, y, c1, c2);
		}
		if (!d)
		{
			d = cut(y, r2, c1, c2);
			d += divide(y, r2, c1, c2);
		}
			
		tmp = u + d;
		if (tmp < cost)
			cost = tmp; 
	}
	
	for (int x = c1 + 1; x < c2; x++)
	{
		int& l = table[r1][r2 - 1][c1][x - 1];
		int& r = table[r1][r2 - 1][x][c2 - 1];
		
		if (!l)
		{
			l = cut(r1, r2, c1, x);
			l += divide(r1, r2, c1, x);
		}
		if (!r)
		{
			r = cut(r1, r2, x, c2);
			r += divide(r1, r2, x, c2);
		}
		
		tmp = l + r;
		if (tmp < cost)
			cost = tmp;
	}
	
	return cost;
}

int solution()
{
	memset(table, 0, sizeof(table));
	
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
			scanf("%d", &board[y][x]);
	}
	
	return divide(0, n, 0, m);
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
