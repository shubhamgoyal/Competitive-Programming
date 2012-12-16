import java.io.*;
import java.util.*;
class Main 
{
	public static void main(String args[])throws IOException
	{
		boolean flag = true;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt())
		{
			int k = sc.nextInt();
			int n = sc.nextInt();
			int a[][] = new int[k][n];
			for(int i = 0; i < k; i ++)
			{
				for(int j = 0; j < n; j ++)
				{
					a[i][j] = sc.nextInt();
				}
			}
			int q[] = {0, 6, 2, 8, 4, 20, 14, 10, 15, 16, 18, 17, 18};
			for(int i = 0; i < k; i ++)
			{
				for(int j = 0; j < n; j ++)
				{
					int min = a[i][j];
					int pos = j;
					for(int l = j + 1; l < n; l ++)
					{
						if(min > a[i][l])
						{
							min = a[i][l];
							pos = l;
						}
					}
					int temp = min;
					a[i][pos] = a[i][j];
					a[i][j] = temp;
				}
			}
			int b[] = new int[k];
			for(int i = 0; i < k; i ++)
				b[i] = i + 1;
			for(int i = 0; i < k; i ++)
			{
				int min = a[i][0];
				int pos = i;
				for(int j = i + 1; j < k; j ++)
				{
					if(min > a[j][0])
					{
						min = a[j][0];
						pos = j;
					}
				}
				if(pos != i)
				{
					int temp = b[i];
					b[i] = b[pos];
					b[pos] = temp;
					for(int l = 0; l < n; l ++)
					{
						temp = a[i][l];
						a[i][l] = a[pos][l];
						a[pos][l] = temp;;
					}
				}
			}
			int p[] = new int [k];
			for(int i = 0; i < k; i ++)
				p[i] = -1;
			int d[] = new int[k];
			for(int i = 0; i < k; i ++)
				d[i] = 0;
			for(int i = 0; i < k; i ++)
			{
				for(int j = i + 1; j < k; j ++)
				{
					if(check(a[i], a[j], n))
					{
						if(d[b[i] - 1] - 1 < d[b[j] - 1])
						{
							d[b[j] - 1] = d[b[i] - 1] - 1;
							p[b[j] - 1] = b[i] - 1;
						}
					}
				}
			}
			int min = d[0];
			int v = 0;
			for(int i = 0; i < k; i ++)
			{
				if(min > d[i])
				{
					min = d[i];
					v = i;
				}
			}
			Vector<Integer> path = new Vector<Integer>();
			System.out.println(((- min) + 1));
			while(v != -1)
			{
				path.add(v);
				v = p[v];
				continue;
			}
			for(int i = (path.size() - 1); i > 0; i --)
			{
				System.out.print((path.elementAt(i) + 1) + " ");
			}
			System.out.println(path.elementAt(0) + 1);
		}	
	}
	public static boolean check(int x[], int y[], int n)
	{
		for(int i = 0; i < n; i ++)
		{
			if(x[i] >= y[i])
				return false;
		}
		return true;
	}
	public static void print(int x[])
	{
		for(int i = 0; i < x.length; i ++)
		{
			System.out.print(x[i] + "\t");
		}
		System.out.println();
	}
}