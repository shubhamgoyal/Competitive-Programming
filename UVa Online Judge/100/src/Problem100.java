
import java.io.*;
import java.util.*;

class Problem100
{
	static long memo[] = new long[1000000];
	//static int ans = 0;
	
	//static int a;
	static long a;
	
	//static int b;
	static long b;
	
	static boolean swapped;
	
	public static void main(String args[])throws IOException
	{
		
		for(int i = 0; i < 1000000; i ++) {
			memo[i] = -1;
		}
		
		Scanner str = new Scanner(System.in);
		while(str.hasNext())
		{
			swapped = false;
			//int a = str.nextInt();
			long a = str.nextLong();
			
			//int b = str.nextInt();
			long b = str.nextLong();
			
			//for(int i = 0; i < 3000000; i ++)
			//	memo[i] = -1;
			//memo[1] = 1;
			
			//int c = 0;
			long c = 0;
			
			if(a > b)
			{
				c = a;
				a = b;
				b = c;
				swapped = true;
			}
			c = 0;
			
			//for(int i = a; i <= b; i ++)
			for (long i = a; i <= b; i ++)
			{
				if(compute(i) > c)
					c = compute(i);
			}
			if(swapped == true)
				System.out.println(b + " " + a + " " + c);
			else
				System.out.println(a + " " + b + " " + c);
		}
	}
	
	//public static int compute(int i)
	public static long compute(long i)
	{
		
		if (i < 1000000) {
			if(memo[(int) i] != -1)
				return memo[(int) i];
			else {
				if(i == 1) {
					memo[1] = 1;
					return memo[1];
				}
				if((i % 2) == 1) {
					memo[(int)i] = 1 + compute(3 * i + 1);
					return memo[(int) i];
				}
				else {
					memo[(int) i] = 1 + compute(i / 2);
					return memo[(int) i];
				}
			}	
		}
		
		if(i == 1)
			return 1;
		//if(memo[i] != -1)
		//	return memo[i];
		//else
		//{
		//	ans = 0;
			if((i % 2) == 1)
				return (1 + compute(3 * i + 1));
			else
				return (1 + compute(i / 2));
			//memo[i] = ans;
			//return ans;
	}
}