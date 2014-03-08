package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: money
*/
import java.io.*;
import java.util.*;

public class moneyrecurse {
	static int size;
	static int[] money;
	static long[][] dp;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("money.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("money.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     size = Integer.parseInt(st.nextToken());
     int goal = Integer.parseInt(st.nextToken());
     money = new int[size+1];
     dp = new long[goal+1][size+1];
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
     for(int x = 0; x<money.length;x++){
     //	 System.out.println(money[x]);
     }
     
     
     for(int x = 0;x<=goal;x++){
    	 for(int y = 0; y<=size;y++){
    		 dp[x][y] = -1;
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
     
     System.out.println(start);
     out.println(find(goal, start));
     
     
     
     
    out.close();                             
    System.exit(0);                            
  }
  static long find(int sum, int index){
	  
	  if(sum<0||index<0) return 0;
	  if(sum==0) return 1;
	  if(index == 0) return 0;
	  if(dp[sum][index]!=-1) return dp[sum][index];
	  return dp[sum][index] = find(sum-money[index], index) + find(sum, index-1);
  }
  
  
}