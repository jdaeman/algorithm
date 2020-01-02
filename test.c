#include <stdio.h>

int val[] = {5, 2, 3, 4, 1};
int len = 5;

void bubble()
{
	for (int i = 0; i < len; i++) //시작은 무조건 처음부터,
	{
		for (int j = 0; j < len - (i + 1); j++) //뒤쪽은 정렬된 상태이므로 갈 필요가 없다.
		{
			if (val[j] > val[j + 1])
			{
				int t = val[j];
				val[j] = val[j + 1];
				val[j + 1] = t;
			}
		}
	}
}

void insert()
{
	for (int i = 1; i < len; i++) //첫번째는 정렬된 구간이라 가정하고 시작,
	{
		int j;
		int v = val[i]; //바뀔 수 있기 때문에 미리 저장해두어야 함.

		for (j = i - 1; j >= 0; j--) //정렬된 영역을 순회하면서,
		{
			if (val[j] > v)
				val[j + 1] = val[j]; //실제 swap 이 아니라 이동만 시킴.
			else //삽입할 위치 발견.
				break;		
		}

		val[j + 1] = v; //탈출한 인덱스를 기준으로 오른쪽에 삽입되어야 함.
	}
}

void show()
{
	for (int i = 0; i < len; i++)
		printf("%d ", val[i]);
	puts("");
}

int main()
{
	//bubble();
	insert();
	show();
	return 0;
}
