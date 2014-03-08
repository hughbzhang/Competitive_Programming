package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: nocows
*/
import java.io.*;
import java.util.*;

public class nocowsnowork {
	
	static int number;
	static int depth;
	static long dp[][];
	static long dpN[][];
	static boolean bot = false;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("nocows.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("nocows.out")));
     
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     number = Integer.parseInt(st.nextToken());
     depth = Integer.parseInt(st.nextToken());
     dp = new long[depth][number];
     dpN = new long[depth-1][number];
     if(depth<2){
    	 out.println(1);
    	 out.close();
    	 System.exit(0);
    }
     else if(number<2*depth-1){
    	 out.println(0);
    	 out.close();
    	 System.exit(0);
     }
     for(int y = 0; y<depth;y++){
    	 for(int x = 0;x<number;x++){
    		 dp[y][x]=0;
    	 }
     }
     long bad = Nsearch(0, number-1);
     print(1);
     long good = search(0, number-1);
     print();
     out.println(good-bad);
     
     
    out.close();                             
    System.exit(0);            
    
  }

	static long search(int deep, int counter){
	  if(counter==0) return 1;
	  if(deep==depth-1){
		 
		  return 0;
	  }
	  if(dp[deep][counter]!=0) return dp[deep][counter];
	  for(int x = 1; x<=counter;x=x+2){
		  dp[deep][counter]+=(search(deep+1, x-1)*search(deep+1, counter-x-1));
	  }
	  return dp[deep][counter];
	}
	
	static long Nsearch(int deep, int counter){
	  if(counter==0) return 1;
	  if(deep==depth-2){
		 
		  return 0;
	  }
	  if(dpN[deep][counter]!=0) return dpN[deep][counter];
	  for(int x = 1; x<=counter;x=x+2){
		  dpN[deep][counter]+=(Nsearch(deep+1, x-1)*Nsearch(deep+1, counter-x-1));
		 // print(1);
		  //System.out.println(deep+" "+counter+" "+ (x-1));
	  }
	  return dpN[deep][counter];
	}

  
  static void print(){
	  for(int y = 0; y<depth;y++){
		  for(int x = 0;x<number;x++){
	    	 System.out.print(dp[y][x]+" ");
	   	 }
	   	 System.out.println();
	  }
	  System.out.println();
  }
  static void print(int a){
	  for(int y = 0; y<depth-1;y++){
		  for(int x = 0;x<number;x++){
	    	 System.out.print(dpN[y][x]+" ");
	   	 }
	   	 System.out.println();
	  }
	  System.out.println();
  }

}

  /*static long search(int deep, int counter){
	  if(deep==depth) bot = true;
	  if(counter==0) return 1;
	  else if(bot){
		  return 0;
	  }
	  if(dp[deep][counter]!=0){
		  bot = true;
		  return dp[deep][counter];
	  }
	  for(int x = 1; x<=counter;x=x+2){
		  long holder =(search(deep+1, x-1)*search(deep+1, counter-x-1));
		  if(bot) dp[deep][counter]+=holder;
		  bot = false;
		  print();
		  System.out.println(deep+" "+counter);
	  }
	  if(dp[deep][counter]!=0) bot = true;
	  //dp[deep][counter]++;
	  return dp[deep][counter];
  }
  
  
*/
   
  
  
  
  
  
  
  
  /*static boolean check(){
	  
	  int deep = 0;
	  
	  for(int x = 0;x<tree.length;x++){
		  if(tree[x]==0) return false;
		  if(tree[x]%2==0) deep = tree[x]/2;
		  else deep = (tree[x]+1)/2;
		  
		  if(deep+x+2>depth) return false;
	  }
	  return true;
	  
  }*/