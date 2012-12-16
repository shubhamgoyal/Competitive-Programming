
import java.io.*;
import java.util.*;
class Main 
{
	static int a = 0;
	static int b = 0;
	public static void main(String args[])throws IOException
	{
		Scanner str = new Scanner(System.in);
		int N = str.nextInt();
		for(int i = 1; i <= N; i ++)
		{
			int high = 0;
			int low = 0;
			int n = str.nextInt();
			a = str.nextInt();
			for(int j = 0; j < (n - 1); j ++)
			{
				b = str.nextInt();
				if(a < b)
					high ++;
				if(b < a)
					low ++;
				a = b;
			}
			System.out.println("Case " + i + ": " + high + " " + low);
		}
	}
}
