package Contest;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.StringTokenizer;

public class bookshelf {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("bookshelf.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bookshelf.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int number = Integer.parseInt(st.nextToken());
     int maxWidth = Integer.parseInt(st.nextToken());
     int[] height = new int[number+1];
     int[] width = new int[number+1];
     long[] dp = new long[number+1];
     
     for(int x = 1;x<=number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 height[x] = Integer.parseInt(st.nextToken());
    	 width[x] = Integer.parseInt(st.nextToken());
     }
     int max = 0;
     int cur = 0;
     for(int x = 0;x<=number;x++) dp[x]= Integer.MAX_VALUE;
     
     dp[0] = 0;
     dp[1] = height[1];
     for(int x = 2;x<=number;x++){
    	 max = 0;
    	 cur = 0;
    	 for(int a = x;a>0;a--){
    		 cur+=width[a];
    		 max = Math.max(max, height[a]);
    		 if(cur<=maxWidth){
    			 dp[x] = Math.min(dp[x], dp[a-1]+max);
    		 }
    		 else break;
    	 }
     }
     
     
     //for(int x = 0;x<=number;x++) System.out.print(dp[x]+" ");
     out.println(dp[number]);
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
}