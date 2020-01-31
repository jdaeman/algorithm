#include <iostream>

using namespace std;

int solution()
{
	int n;
	int ret = 0;
	int phase = 0; //init state
	
	int val[2];

	cin >> n;	
	cin >> val[0]; //prev
	for (int i = 1; i < n; i++)
	{
		//cin >> val[1]; //current
		scanf("%d", &val[1]);

		if (val[0] == val[1])
		{
			//empty
		}
		else if (val[0] < val[1]) //ascending order
		{
			if (phase == 0)
				phase = 1; //change phase 
			else if (phase == 2) //이전 순서가 내림차순
			{
				phase = 0; //reset
				ret += 1;
			}
		}
		else //descending order
		{
			if (phase == 0)
				phase = 2; //change phase
			else if (phase == 1) //이전 순서가 오름차순
			{
				phase = 0; //reset
				ret += 1;
			}
		}

		val[0] = val[1];
	}

	return ret + 1; //마지막 부분 배열에 대해서 처리
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
