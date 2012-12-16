import java.io.*;
import java.util.*;

class Main
{
	static int max = 0;
	static int min = 10000;
	public static void main (String args[])throws IOException
	{
		Scanner sc = new Scanner(System.in);
		Vector<Integer> v = new Vector<Integer>(20000);
		for(int i = 0; i < 20000; i ++)
		{
			v.add(0);
		}
		while(sc.hasNext())
		{
			int L = sc.nextInt();
			int H = sc.nextInt();
			int R = sc.nextInt();
			if(R > max)
				max = R;
			if(L < min)
				min = L;
			for(int i = (2 * L); i <= (2 * R - 1); i ++)
			{
				if(v.elementAt(i) < H)
				{
					v.set(i, H);
				}
			}
		}
		max = 2 * max - 1;
		min = 2 * min;
		System.out.print((min + 1)/2);
		for(int i = min + 1; i <= max; i ++)
		{
			if(v.elementAt(i)  != v.elementAt(i - 1))
			{
				System.out.print(" " + v.elementAt(i - 1) + " " + ((i + 1)/2));
			}
		}
		System.out.print(" " + v.elementAt(max) + " " + ((max + 1)/2));
		System.out.println(" 0");
		}
}
