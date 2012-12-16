
import java.io.*;
import java.util.*;

public class Main 
{
	public static void main(String args[])throws IOException
	{
		int N = 0;
		Scanner str = new Scanner(System.in);
		N = str.nextInt();
		for(int i = 1; i <= N; i ++)
		{
			System.out.print("Case " + i + ": ");
			int a = str.nextInt();
			int b = str.nextInt();
			int c = str.nextInt();
			if(a >= b)
			{
				if(a >= c)
				{
					if(b >= c)
						System.out.println(b);
					else
						System.out.println(c);
				}
				else
					System.out.println(a);
			}
			else
			{
				if(b >= c)
				{
					if(a >= c)
						System.out.println(a);
					else
						System.out.println(c);
				}
				else
					System.out.println(b);
			}
		}
	}
}
