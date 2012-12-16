import java.io.*;
import java.util.*;

class Main 
{
	static Vector<Vector <Integer>> list;
	static String s;
	static int[] pos;
	public static void main(String args[])throws IOException
	{
		Scanner str = new Scanner(System.in);
		int n = str.nextInt();
		list = new Vector <Vector <Integer>>(n);
		pos = new int[n];
		for(int i = 0; i < n; i ++)
		{
			Vector<Integer> v = new Vector<Integer>();
			v.add(i);
			list.add(i, v);
		}
		for(int i = 0; i < n; i ++)
			pos[i] = i;
		str.nextLine();
		while((s = str.nextLine()).equals("quit") == false)
		{
			StringTokenizer st = new StringTokenizer(s);
			String s1 = st.nextToken();
			st.nextToken();
			String s2 = st.nextToken();
			char c1 = s1.charAt(0);
			char c2 = s2.charAt(1);
			Scanner sc = new Scanner(s);
			sc.next();
			int i1 = sc.nextInt();
			sc.next();
			int i2 = sc.nextInt();
			if((i1 == i2) || (pos[i1] == pos[i2]))
			{
			}
			else if(c1 == 'm')
			{
				if(c2 == 'n')
				{
					Vector<Integer> a = new Vector<Integer>();
					a = list.get(pos[i1]);
					int p = 0;
					for(int i = 0; i < a.size(); i ++)
					{
						if(a.get(i) == i1)
						{
							p = i;
							break;
						}
					}
					Vector<Integer> b = new Vector<Integer>();
					for(int i = 0; i < p; i ++)
					{
						b.add(a.get(i));
					}
					for(int i = p + 1; i < a.size(); i ++)
					{
						list.get(a.get(i)).add(a.get(i));
						pos[a.get(i)] = a.get(i);
					}
					list.remove(pos[i1]);
					list.add(pos[i1], b);
					pos[i1] = pos[i2];
					Vector<Integer> c = new Vector<Integer>();
					c = list.get(pos[i2]);
					int q = 0;
					for(int i = 0; i < c.size(); i ++)
					{
						if(c.get(i) == i2)
						{
							q = i;
							break;
						}
					}
					Vector<Integer> d = new Vector<Integer>();
					for(int i = 0; i <= q; i ++)
					{
						d.add(c.get(i));
					}
					d.add(i1);
					for(int i = q + 1; i < c.size(); i ++)
					{
						list.get(c.get(i)).add(c.get(i));
						pos[c.get(i)] = c.get(i);
					}
					list.remove(pos[i2]);
					list.add(pos[i2], d);
				}
				else
				{
					Vector<Integer> a = new Vector<Integer>();
					a = list.get(pos[i1]);
					int p = 0;
					for(int i = 0; i < a.size(); i ++)
					{
						if(a.get(i) == i1)
						{
							p = i;
							break;
						}
					}
					Vector<Integer> b = new Vector<Integer>();
					for(int i = 0; i < p; i ++)
					{
						b.add(a.get(i));
					}
					for(int i = p + 1; i < a.size(); i ++)
					{
						list.get(a.get(i)).add(a.get(i));
						pos[a.get(i)] = a.get(i);
					}
					list.remove(pos[i1]);
					list.add(pos[i1], b);
					pos[i1] = pos[i2];
					list.get(pos[i2]).add(i1);
				}
			}
			else
			{
				if(c2 == 'n')
				{
					int temp = pos[i1];
					int q = 0;
					Vector<Integer> c = new Vector<Integer>();
					c = list.get(pos[i2]);
					for(int i = 0; i < c.size(); i ++)
					{
						if (c.get(i) == i2)
						{
							q = i;
							break;
						}
					}
					for(int i = q + 1; i < c.size(); i ++)
					{
						list.get(c.get(i)).add(c.get(i));
						pos[c.get(i)] = c.get(i);
					}
					Vector<Integer> d = new Vector<Integer>();
					for(int i = 0; i <= q; i ++)
					{
						d.add(c.get(i));
					}
					Vector<Integer> a = new Vector<Integer>();
					a = list.get(pos[i1]);
					int p = 0;
					for(int i = 0; i < a.size(); i ++)
					{
						if(a.get(i) == i1)
						{
							p = i;
							break;
						}
					}
					for(int i = p; i < a.size(); i ++)
					{
						d.add(a.get(i));
						pos[a.get(i)] = pos[i2];
					}
					list.remove(pos[i2]);
					list.add(pos[i2], d);
					Vector<Integer> b = new Vector<Integer>();
					for(int i = 0; i < p; i ++)
					{
						b.add(a.get(i));
					}
					list.remove(temp);
					list.add(temp, b);
				}
				else
				{
					Vector<Integer> a = new Vector<Integer>();
					a = list.get(pos[i1]);
					int p = 0;
					for(int i = 0; i < a.size(); i ++)
					{
						if(a.get(i) == i1)
							p = i;
					}
					Vector<Integer> b = new Vector<Integer>();
					for(int i = 0; i < p; i ++)
					{
						b.add(a.get(i));
					}
					list.remove(pos[i1]);
					list.add(pos[i1], b);
					Vector<Integer> c = new Vector<Integer>();
					c = list.get(pos[i2]);
					for(int i = p; i < a.size(); i ++)
					{
						c.add(a.get(i));
						pos[a.get(i)] = pos[i2];
					}
					list.remove(pos[i2]);
					list.add(pos[i2], c);
				}
			}
		}
		for(int i = 0; i < n; i ++)
		{
			if(list.get(i).size() == 0)
				System.out.println(i + ":");
			else if(list.get(i).size() == 1)
			{
				System.out.print(i + ": ");
				System.out.println(list.get(i).firstElement());
			}
			else
			{
				System.out.print(i + ": ");
				for(int j = 0; j < (list.get(i).size() - 1); j ++)
				{
					System.out.print(list.get(i).get(j) + " ");
				}
				System.out.println(list.get(i).get(list.get(i).size() - 1));
			}
		}
	}
}
