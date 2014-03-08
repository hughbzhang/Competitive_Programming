package Contest;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/

//add an external stack

import java.io.*;
import java.util.StringTokenizer;

public class msched {
	static int[] dp;
	static int[][] lim;
	static int[] time;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("msched.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("msched.out")));
     StringTokenizer st  = new StringTokenizer(f.readLine());
    
     int cows = Integer.parseInt(st.nextToken());
     int limits = Integer.parseInt(st.nextToken());
     time = new int[cows+1];
     dp = new int[cows+1];
     
     for(int x = 1;x<=cows;x++){
    	 time[x] = Integer.parseInt(f.readLine());
     }
     int[] count = new int[cows+1];
     int[][] holder = new int[limits][2];
     for(int x = 0;x<limits;x++){
    	 st = new StringTokenizer(f.readLine());
    	 int a = Integer.parseInt(st.nextToken());
    	 int b = Integer.parseInt(st.nextToken());
    	 holder[x][0] = a;
    	 holder[x][1] = b;
    	 count[b]++;
     }
     int large = 0;
     for(int x = 0;x<count.length;x++){
    	 if(count[x]>large) large = count[x];
     }
     lim = new int[cows+1][large];
     
     for(int x = 0;x<limits;x++){
    	 int a = holder[x][0];
    	 int b = holder[x][1];
     
	     int counter = 0;
		 while(lim[b][counter]!=0) counter++;
		 lim[b][counter] = a;
     }
	 
	 
	 
     int max = 0;
     
     for(int x = 1;x<=cows;x++){
    	 if(lim[x][0]==0) dp[x]=time[x];
     }
     
     for(int x = 1;x<=cows;x++){
    	 dp[x] = find(x);
    	 if(dp[x]>max) max = dp[x];
     }
     
     
     out.println(max);
     
     
     
   
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static int find(int x){
	  if(dp[x]!=0) return dp[x];
	  int counter = 0;
	  int add = 0;
	  while(counter<lim[0].length&&lim[x][counter]!=0){
		  if(add<find(lim[x][counter])) add = find(lim[x][counter]);
		  counter++;
	  }
	  return dp[x] = time[x]+add;
  }
  
  
  
  void print(int[][] lim){
	  for(int y = 0;y<lim.length;y++){
	    	 for(int x = 0;x<lim[0].length;x++){
	    		 System.out.print(lim[y][x]+" ");
	    	 }
	    	 System.out.println();
	     }
  }
}