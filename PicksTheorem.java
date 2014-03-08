package Algorithms;
/*
ID: bigfish2
LANG: JAVA
TASK: fence9
*/
import java.io.*;
import java.util.*;

public class PicksTheorem {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("fence9.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fence9.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int n = Integer.parseInt(st.nextToken());
     int m = Integer.parseInt(st.nextToken());
     int p = Integer.parseInt(st.nextToken());
     
     int area = m*p;//Picks theorem 2A = 2I+B-2 A = area I = inside points B = boundary points
     int bound = p+1;//bottom bound points
     bound+=GCF(m,n);//add GCF intersection points
     bound+=GCF(Math.abs(n-p),m);
     bound--;//subtract double count;
     out.println((area-bound+2)/2);
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  private static int GCF(int a, int b){
	  
	  	if(a<b){
			int temp = a;
			a = b;
			b=temp;
		}
		while(b!=0){
			int m = a%b;
			a = b;
			b = m;
		}
		return a;
  }
}