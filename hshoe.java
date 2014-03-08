package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: hshoe
*/
import java.io.*;

public class hshoe {
	static int size;
	static int[][] grid;
	static boolean[][] path; 	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("hshoe.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hshoe.out")));
     
     size = Integer.parseInt(f.readLine());
     grid = new int[size][size];
     path = new boolean[size][size];
     for(int y = 0;y<size;y++){
    	 String temp = f.readLine();
    	 for(int x = 0;x<size;x++){
    		 if(temp.charAt(x)=='(') grid[y][x] = 1;
    		 else grid[y][x]=0;
    	 }
     }
     
     out.println(2*search(0,0,0,0));
     print();
     
     
     
     
    out.close();                             
    System.exit(0);                            
  }
  static void print(){
	  for(int y = 0;y<size;y++){
	     for(int x = 0;x<size;x++){
	   		System.out.print(grid[y][x]+" ");
	     }
	     System.out.println();
	  }
  }
  static int search(int y, int x, int forward, int backward){
	  
	  if(y<0||y>=size||x<0||x>=size) return 0;
	  if(path[y][x]) return 0;
	  path[y][x]=true;
	 
	  if(grid[y][x]==1){
		  if (backward==0) forward++;
		  else{
			  path[y][x]=false;
			  if(forward==backward) return forward;
			  else return 0;
		  }
	  }
	  else{
		  backward++;
	  }
	  if(backward>=forward){
		  path[y][x]=false;
		  return forward;
	  }

	  int a = search(y+1, x, forward, backward);
	  int b = search(y-1, x, forward, backward);
	  int c = search(y, x+1, forward, backward);
	  int d = search(y, x-1, forward, backward);
	  path[y][x]=false;
	  
	  return max(a,b,c,d);
	  
	  
  }
  static int max(int a, int b, int c, int d){
	  
	  return Math.max(Math.max(a, b), Math.max(c, d));
	  
  }

}