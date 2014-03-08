package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: inflate
*/
import java.io.*;
import java.util.*;

public class inflate {
	public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("inflate.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("inflate.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int time = Integer.parseInt(st.nextToken());
     int categories = Integer.parseInt(st.nextToken());
     long[] dp = new long[time+1];
     for(int x = 0;x<=time;x++) dp[x]=0;
     
     for(int x = 0;x<categories;x++){
    	 st = new StringTokenizer(f.readLine());
    	 int points = Integer.parseInt(st.nextToken());
    	 int index = Integer.parseInt(st.nextToken());
    	 if(points>dp[index]) dp[index]=points;
    		 
     }
     for(int x = 0;x<dp.length;x++){
    	 int stop = (int) Math.ceil(x/2);
    	 for(int y = 0;y<=stop;y++){
    		 if(dp[y]+dp[x-y]>dp[x]) dp[x]=(dp[y]+dp[x-y]);
    	 }
     }

     out.println(dp[time]);
     
     out.close();                             
     System.exit(0);                            

	}

}