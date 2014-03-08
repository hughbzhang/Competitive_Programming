package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: fence9
*/
import java.io.*;
import java.util.*;

public class fence9 {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("fence9.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fence9.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int n = Integer.parseInt(st.nextToken());
     int m = Integer.parseInt(st.nextToken());
     int p = Integer.parseInt(st.nextToken());
     
     double slope1 = ((double)n)/m;
     double slope2 = ((double)(n-p))/m;
     int points = 0;
     
    for(int x = 1;x<m;x++){
    	double start = slope1*x;
    	double end = slope2*x+p;
    	points+=(up(end)-(down(start))-1);
    	System.out.println(down(start)+" "+up(end));
    }
     out.println(points);
     
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  private static int up(double a){
	  int temp = (int)Math.floor(a);
	  if(a-temp>0.000001) temp++;
	  return temp;
  }
  private static int down(double a){
	  int temp = (int)Math.ceil(a);
	  if(temp-a>0.000001) temp--;
	  return temp;
  }
  
}