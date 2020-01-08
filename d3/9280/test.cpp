#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int parking[100];
int used[100];

int cars[2001];
int position[2001];

int lookup()
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!used[i])
			break;
	}

	printf("%d\n", i);
	return i;	
}

int solution()
{
	queue<int> q;
	queue<int> qq;

	int op, avail, tot = 0, ret = 0;
	int pos;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &parking[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &cars[i]);
	for (int i = 0; i < (m << 1); i++)
	{
		scanf("%d", &op);
		q.push(op);
	}

	avail = n;
	memset(used, 0, sizeof(used));
	memset(position, 0, sizeof(position));

	while (tot < m)
	{	
		if (qq.size() && avail)
		{
			op = qq.front();
			qq.pop();

			pos = lookup();
			used[pos] = op;
			position[op] = pos;

			tot += 1;
			avail -= 1;

			ret += (cars[op] * parking[pos]);
		}
		else if (q.size())
		{
			op = q.front();
			q.pop();

			if (op < 0)
			{
				pos = position[-op];
				used[pos] = 0;

				avail += 1;
			}
			else
			{
				if (!avail)
					qq.push(op);
				else
				{
					pos = lookup();
					used[pos] = op;
					position[op] = pos;

					tot += 1;
					avail -= 1;
					ret += (cars[op] * parking[pos]);
				}
			}
		}
	}

	return ret;
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
