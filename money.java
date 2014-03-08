package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: money
*/
import java.io.*;
import java.util.*;

public class money {
	static int size;
	static int[] money;
	static long[] dp;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("money.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("money.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     size = Integer.parseInt(st.nextToken());
     int goal = Integer.parseInt(st.nextToken());
     money = new int[size+1];
     dp = new long[goal+1];
     int counter = 1;
     int length;
     money[0] = 0;
     
     String temp = f.readLine();
     
     while(temp!=null){
    	 st = new StringTokenizer(temp);
    	 length = st.countTokens();
    	 for(int x = 0;x<length;x++){
    		 money[counter] = Integer.parseInt(st.nextToken());
    		 counter++;
    	 }
    	 temp = f.readLine();
    	 
     }
     
     
     boolean go = true;
     int storage;
     while(go){
    	 go = false;
    	 for(int x = 1;x<money.length;x++){
    		 if(money[x]==money[x-1]) money[x]=Integer.MAX_VALUE;
    		 if(money[x]<money[x-1]){
    			 go = true;
    			 storage = money[x];
    			 money[x]=money[x-1];
    			 money[x-1]=storage;
    		 }
    	 }
     }
     int start = size;
     
     for(int x = money.length-1;x>-1;x--){
    	 if(money[x]!=Integer.MAX_VALUE){
    		 start = x;
    		 break;
    	 }
    	 //System.out.println(money[x]);
     }
     
     
     dp[0]=1;
     
     for(int x = 1; x<=start;x++){
    	 for(int a = money[x];a<dp.length;a++){
    		 dp[a] += dp[a-money[x]];
    	 }
     }
     
     out.println(dp[goal]);
     
   
     out.close();
     System.exit(0);
   
  } 
}