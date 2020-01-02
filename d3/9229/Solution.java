import java.util.Scanner;

public class Solution
{
	private static Scanner sc = new Scanner(System.in);

	public static int solution()
	{
		int N, M;
		int max = -1;
		int [] vals = new int[1000];

		N = sc.nextInt();
		M = sc.nextInt();

		for (int idx = 0; idx < N; idx++)
		{
			vals[idx] = sc.nextInt();
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

	public static void main(String[] args)
	{
		int T = sc.nextInt();
		
		for (int cnt = 1; cnt <= T; cnt++)
		{
			System.out.printf("#%d %d", cnt, solution());
			System.out.println();
		}
	}
}
