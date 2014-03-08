package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: numtri
*/
import java.io.*;
import java.util.*;

public class numtri {
	
	static int size;
	static int[][] tree;
	static int[][] DP;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("numtri.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("numtri.out")));
     
     size = Integer.parseInt(f.readLine());
     tree = new int[size][size];
     DP = 	new int[size][size];
     
     int limit = 0;
     
     for(int y = 0; y<size;y++){
    	 StringTokenizer st = new StringTokenizer(f.readLine());
    	 limit = st.countTokens();
    	 for(int x = 0;x<limit;x++){
    		 tree[y][x] = Integer.parseInt(st.nextToken());
    	 }
    	
     }
     for(int x = 0; x<size;x++){
    	 for(int y = 0; y<size;y++){
    		 DP[x][y]=-1;
    	 }
     }
     
     int total = find(0,0);
     
    // print();
     
     
    out.println(total);
    out.close();                             
    System.exit(0);                            
  }
  static void print(){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  System.out.print(DP[y][x]+" ");
		  }
		  System.out.println();
	  }
  }
  
  static int find(int depth, int position){
	  if(depth >= size) return 0;
	  if(DP[depth][position]!=-1) return DP[depth][position];
	  
	  int total = tree[depth][position];
	  int left = find(depth+1, position);
	  int right = find(depth+1, position+1);
	  DP[depth][position] = total + Math.max(left, right);
	  
	  return DP[depth][position];
  }
  
  
  
  
}