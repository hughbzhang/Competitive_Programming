package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: nocows
*/
import java.io.*;
import java.util.*;

public class nocows {
	
	static int number;
	static int depth;
	static long[][] dp;
	static long[][] sub;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("nocows.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("nocows.out")));
     
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     number = Integer.parseInt(st.nextToken());
     depth = Integer.parseInt(st.nextToken());
     dp = new long[depth][number];
     sub = new long[depth][number];
     
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
    		 dp[y][x]=-1;
    		 sub[y][x]=-1;
    	 }
     }
     
     //System.out.println(full(0, number-1));
     //print();
     
     out.println(full(0, number-1));
     //print();
     
     //System.out.println(sub(1,0, 0));
    out.close();                             
    System.exit(0);            
    
  }
	 static long sub(int max, int cur, int nodes){//finds all subtrees of height max and under with the number of indicated nodes
		 //System.out.println(cur+" "+max+" "+nodes);
		 if(max<0) return 0;
		 if(cur==max) return 0;
		 if(nodes==0) return 1;
		 if(sub[cur][nodes]!=-1) return sub[cur][nodes];
		 sub[cur][nodes]++;
		 for(int x = 1; x<nodes;x=x+2){
			 sub[cur][nodes] += (sub(max, cur+1, x-1)*sub(max, cur+1, nodes-x-1));
		 }
		 return sub[cur][nodes];
	 }
	 static long full(int height, int nodes){
		 if(nodes==0&&height==depth-1) return 1;
		 if(nodes==0||height==depth-1) return 0;
		 if(dp[height][nodes]!=-1) return dp[height][nodes];
		 dp[height][nodes]++;
		 for(int x = 1;x<nodes;x=x+2){
			 dp[height][nodes]+=full(height+1, x-1)*full(height+1, nodes-x-1);
			 System.out.println(dp[height][nodes]+" "+height+" "+nodes);
			 dp[height][nodes]+=full(height+1, x-1)*sub(depth-height-2 ,0, nodes-x-1);
			 System.out.println(dp[height][nodes]+" "+height+" "+nodes);
			 dp[height][nodes]+=sub(depth-height-2, 0, x-1)*full(height+1, nodes-x-1);
			 System.out.println(dp[height][nodes]+" "+height+" "+nodes);
			 
		 }
		 return dp[height][nodes];
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
	  for(int y = 0; y<depth;y++){
		  for(int x = 0;x<number;x++){
	    	 System.out.print(sub[y][x]+" ");
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