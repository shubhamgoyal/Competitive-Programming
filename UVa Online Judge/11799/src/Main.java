import java.io.*;
import java.util.*;

class Main 
{
	static int max = 0;
	public static void main(String args[])throws IOException
	{
		Scanner str = new Scanner(System.in);
		int T = str.nextInt();
		for(int i = 1; i <= T; i ++)
		{
			int N = str.nextInt();
			max = 0;
			//int max = str.nextInt();
			for(int j = 1; j <= N; j ++)
			{
				int k = str.nextInt();
				if(max < k)
					max = k;
			}
			System.out.println("Case " + i + ": " + max);
		}
		System.exit(0);
	}
}
