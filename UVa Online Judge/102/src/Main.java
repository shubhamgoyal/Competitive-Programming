import java.io.*;
import java.util.*;

public class Main 
{
	static int a[][] = new int [3][3];
	//first row -> first bin
	//second row -> second bin
	//third row -> third bin
	//first column -> brown
	//second column -> green
	//third column -> clear
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			//String s = sc.nextLine();
			//Scanner sca = new Scanner(s);
			for(int i = 0; i < 3; i ++)
			{
				for(int j = 0; j < 3; j ++)
				{
					a[i][j] = sc.nextInt();
					//a[i][j] = sca.nextInt();
				}
			}
			int b[] = new int[6];
			//String c[] = new String[6];
			//c[1] = "BGC";
			b[1] = a[1][0] + a[2][0] + a[0][1] + a[2][1] + a[0][2] + a[1][2];
			//c[0] = "BCG";
			b[0] = a[1][0] + a[2][0] + a[0][1] + a[1][1] + a[0][2] + a[2][2];
			//c[4] = "GBC";
			b[4] = a[0][0] + a[2][0] + a[1][1] + a[2][1] + a[0][2] + a[1][2];
			//c[5] = "GCB";
			b[5] = a[1][1] + a[2][1] + a[0][2] + a[2][2] + a[0][0] + a[1][0];
			//c[2] = "CBG";
			b[2] = a[1][2] + a[2][2] + a[0][0] + a[2][0] + a[0][1] + a[1][1];
			//c[3] = "CGB";
			b[3] = a[1][2] + a[2][2] + a[0][1] + a[2][1] + a[0][0] + a[1][0];
			/*for(int i = 0; i < 6; i ++)
			{
				for(int j = 0; j < (5 - i); j ++)
				{
					if(b[j] > b[j + 1])
					{
						int temp = b[j];
						b[j] = b[j + 1];
						b[j + 1] = temp;
						String tmp = c[j];
						c[j] = c[j + 1];
						c[j + 1] = tmp;
					}
				}
			}*/
			int min = b[0];
			for(int i = 1; i < 6; i ++)
			{
				if(b[i] < min)
					min = b[i];
			}
			if(min == b[0])
			{
				System.out.println("BCG " + b[0]);
				//System.exit(0);
			}
			else if(min == b[1])
			{
				System.out.println("BGC " + b[1]);
				//System.exit(0);
			}
			else if(min == b[2])
			{
				System.out.println("CBG " + b[2]);
				//System.exit(0);
			}
			else if(min == b[3])
			{
				System.out.println("CGB " + b[3]);
				//System.exit(0);
			}
			else if(min == b[4])
			{
				System.out.println("GBC " + b[4]);
				//System.exit(0);
			}
			else
			{
				System.out.println("GCB " + b[5]);
				//System.exit(0);
			}
				//System.out.println(c[0] + " " + b[0]);
		}
	}
}
