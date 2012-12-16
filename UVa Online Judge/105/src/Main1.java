import java.io.*;
import java.util.*;

class Main1 
{
	Vector<Vector<Integer>> v = new Vector<Vector<Integer>>();
	Scanner sc = new Scanner(System.in);
	
	public static void main(String args[])throws IOException
	{
		Main1 ob = new Main1();
		ob.m();
	}
	
	public void m()throws IOException
	{
		while(sc.hasNext())
		{
			Vector<Integer> s = new Vector<Integer>();
			s.add(0);
			s.add(0);
			s.add(0);
			int L = sc.nextInt();
			int H = sc.nextInt();
			int R = sc.nextInt();
			s.set(0, L);
			s.set(1, H);
			s.set(2, R);
			v.add(s);
		}
		QuickSort(v, 0, v.size() - 1);
		Vector<Vector<Integer>> w = new Vector<Vector<Integer>>();
		Vector<Integer> z = new Vector<Integer>();
		z.add(10000);
		z.add(0);
		w.add(z);
		boolean flag1;
		boolean flag2;
		for(int i = 0; i < v.size(); i ++)
		{	
			flag1 = false;
			flag2 = false;
			for(int j = 0; j < w.size(); j ++)
			{
				if(flag1 == false && flag2 == false)
				{
					if(w.elementAt(j).elementAt(0) == 10000 && w.elementAt(j).elementAt(1) == 0)
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(0));
						a.add(v.elementAt(i).elementAt(1));
						a.add(0);
						w.insertElementAt(a, j);
						flag1 = true;
						continue;
					}
					else if(w.elementAt(j).elementAt(0) == v.elementAt(i).elementAt(0))
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(0));
						a.add(v.elementAt(i).elementAt(1));
						a.add(0);
						w.set(j, a);
						flag1 = true;
						continue;
					}
					else if(w.elementAt(j).elementAt(0) > v.elementAt(i).elementAt(0))
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(0));
						a.add(v.elementAt(i).elementAt(1));
						a.add(0);
						w.insertElementAt(a, j);
						flag1 = true;
						continue;
					}
					else
						continue;
				}
				else if(flag1 == true && flag2 == false)
				{
					if(w.elementAt(j).elementAt(0) == 10000 && w.elementAt(j).elementAt(1) == 0)
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(2));
						//a.add(v.elementAt(i).elementAt(1));
						a.add(0);
						a.add(1);
						w.insertElementAt(a, j);
						flag2 = true;
						break;
					}
					else if(w.elementAt(j).elementAt(0) == v.elementAt(i).elementAt(2))
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(2));
						//a.add(v.elementAt(i).elementAt(1));
						a.add(w.elementAt(j).elementAt(1));
						a.add(1);
						w.set(j, a);
						flag2 = true;
						break;
					}
					else if(w.elementAt(j).elementAt(0) > v.elementAt(i).elementAt(2))
					{
						Vector<Integer> a = new Vector<Integer>();
						a.add(v.elementAt(i).elementAt(2));
						//a.add(v.elementAt(i).elementAt(1));
						//a.add(w.elementAt(j).elementAt(1));
						//if(w.elementAt(j).elementAt(2) == 1)
							a.add(w.elementAt(j).elementAt(1));
						//else
							
						a.add(1);
						w.insertElementAt(a, j);
						flag2 = true;
						break;
					}
					else if(w.elementAt(j).elementAt(0) < v.elementAt(i).elementAt(2))
					{
						w.remove(j);
						j --;
						continue;
					}
				}
			}
		}
		for(int i = 0; i < w.size(); i ++)
		{
			System.out.println(w.elementAt(i).elementAt(0) + "\t" + w.elementAt(i).elementAt(1));
		}
	}
	public void QuickSort(Vector<Vector<Integer>> v, int n1, int n2)
	{
		int pIndex = 0;
		int p = 0;
		if(n1 >= n2)
			return;
		else
		{
			do
			{
				Random r = new Random();
				pIndex = r.nextInt(n2 - n1 + 1);
				p = partition(v, n1, n2, n1 + pIndex);
			}while((p - n1) < (n2 - n1 + 1)/10 || (p - n1) > 9*(n2 - n1 + 1)/10);
			QuickSort(v, n1, p - 1);
			QuickSort(v, p + 1, n2);
		}
	}
	public int partition(Vector<Vector<Integer>> v, int n1, int n2, int pIndex)
	{
		Vector<Integer> temp = v.elementAt(pIndex);
		v.set(pIndex, v.elementAt(n2));
		v.set(n2, temp);
		int i = n1 - 1;
		for(int j = n1; j < n2; j ++)
		{
			if(v.elementAt(j).elementAt(1) <= temp.elementAt(1))
			{
				i ++;
				Vector<Integer> t = v.elementAt(i);
				v.set(i, v.elementAt(j));
				v.set(j, t);
			}
		}
		Vector<Integer> t = v.elementAt(n2);
		v.set(n2, v.elementAt(i + 1));
		v.set(i + 1, t);
		return (i + 1);
	}
}