import java.io.*;
import java.util.Scanner;
public class Main {
	public static void main(String args[])throws IOException{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n != 2){
			System.out.println(2 * (n - 2));
			System.out.print(2);
			for(int i = 3; i < n; i ++){
				System.out.print(" " + i);
			}
			for(int i = n - 1; i > 1; i --){
				System.out.print(" " + i);
			}
			System.out.println();
		}
		else
			System.out.println("2\n2 2");
	}
}