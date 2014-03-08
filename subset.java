package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: subset
*/
import java.io.*;

public class subset {
	
  static long[][] dp;
  //static int number;
  //static int sum;
  
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("subset.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("subset.out")));

     int  number = Integer.parseInt(f.readLine());
     int sum = number*(number+1)/2;
     dp = new long[sum+1][number+1];
     
     for(int y = 0;y<=sum;y++){
    	 for(int x = 0;x<=number;x++){
    		 dp[y][x]=-1;
    	 }
     }
     
     if(sum%2!=0){
    	 //System.out.println("sorry");
    	 out.println(0);
     }
     else out.println(find(sum/2, number)/2);
     
     
     
     
     
   out.close();
   System.exit(0);
  }
  
  static long find(int s, int n){
	  
	  if(s<0||n<0) return 0;
	  if(dp[s][n]!=-1) return dp[s][n];
	  if(s==0&&n==0) return 1;
	  dp[s][n] = find(s, n-1)+find(s-n, n-1);
	  //System.out.println(dp[s][n]);
	  return dp[s][n]; 
  }
  
  
  
  
  
}