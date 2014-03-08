package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: range
*/
import java.io.*;

public class range {
	
	static int size;
	static boolean[][] grid;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("range.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("range.out")));
     size = Integer.parseInt(f.readLine());
     grid = new boolean[size][size];
     for(int y = 0;y<size;y++){
    	 String temp = f.readLine();
    	 for(int x = 0;x<size;x++){
    		 int index = temp.charAt(x)-48;
    		 if(index==1) grid[y][x] = true;
    		 else grid[y][x] = false;
    	 }
     }
     int cur = size;
     int large = 1;
     int count = 0;
     int[] win = solve();
     if(win!=null){
    	 for(int x = 2;x<win.length;x++){
    		 if(win[x]==0) break;
    		 out.println(x+" "+win[x]);
    	 }
    	 f.close();
    	 out.close();                             
    	 System.exit(0);
     }
    // boolean[][] dp = new boolean[size-1][size-1];
     boolean past = false;
	    
     
     do{
    	 count = 0;
    	 large++;
    	 cur--;
     	for(int y = 0;y<cur;y++){
	    	 if(grid[y][0]&&grid[y+1][0]) past = true;
	    	 else past = false;
	    	 for(int x = 0;x<cur;x++){
	    		grid[y][x]=false;
	    		 if(grid[y][x+1]&&grid[y+1][x+1]){
	    			if(past){
	    				grid[y][x]=true;
	    				count++;
	    			}
	    			past=true;
	    			
	    		}
	    		else past = false;
	    	 }
	     }
	     if(count!=0) out.println(large+" "+count);
	     //print(grid, cur);
     }     while(count>0);
    	
     
     
     
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static int[] solve(){
	  int[][] dp = new int[size][size];
	  int[] win = new int[size+1];
	  for(int x = 0;x<size;x++){
		  if(grid[0][x]) dp[0][x] = 1;
		  else dp[0][x] = 0;
	  }
	  for(int y = 0;y<size;y++){
		  if(grid[y][size-1]) dp[y][size-1] = 1;
	  }
	  
	  for(int y = 1;y<size;y++){
		  for(int x = size-2;x>-1;x--){
			  if(grid[y][x]){
				  dp[y][x] = min(dp[y-1][x], dp[y-1][x+1], dp[y][x+1])+1;
				  for(int a = 2; a<=dp[y][x];a++) win[a]++;
			  }
			  else dp[y][x] = 0;
			  
		  }
	  }
	  //print(dp, size);
	  //for(int x = 0; x<win.length;x++) System.out.print(win[x]+" ");
	  return win;
	  
  }
  static int min(int a, int b, int c){
	  return Math.min(Math.min(a, b), c);
  }
  
  
  static void print(){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  System.out.print(grid[y][x]);
		  }
		  System.out.println();
	  }
  }
  static void print(int[][] dp, int size){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  System.out.print(dp[y][x]);
			  }
		  System.out.println();
	  }
	  System.out.println();
  }
  static void print(boolean[][] dp, int size){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  if(dp[y][x])System.out.print(1);
			  else System.out.print(0);
		  }
		  System.out.println();
	  }
	  System.out.println();
  }
  
}