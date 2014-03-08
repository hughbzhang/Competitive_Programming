package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: game1
*/
import java.io.*;
import java.util.*;

public class game1 {
	static int[] game;
	static int[][] dpF;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("game1.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("game1.out")));
     int sum = 0;
     int size = Integer.parseInt(f.readLine());
     game = new int[size];
     dpF = new int[size][size];
     
     String temp = f.readLine();
     StringBuffer line = new StringBuffer("");
     while(temp!=null){
    	 line.append(temp);
    	 line.append(" ");
    	 temp = f.readLine();
     }
     
     
    StringTokenizer st = new StringTokenizer(line.toString());
    
    for(int x = 0;x<size;x++){
    	game[x]=Integer.parseInt(st.nextToken());
    	sum+=game[x];
    	for(int y = 0;y<size;y++){
    		dpF[x][y]=-1;
    		
    	}
    }
    
    
    
    //RECURSIVE SOLUTION
    int printer = play(0, size-1, true);
    out.println(printer+" "+ (sum-printer));
   
    
    
  
    
    
    
    
    
    out.close();                             
    System.exit(0);                            
  }
  static int play(int start, int end, boolean turn){
	  if(start>end) return 0;
	  if(dpF[start][end]!=-1) return dpF[start][end];
	  int one = play(start+1, end, !turn);
	  int two = play(start, end-1, !turn);
	  
	  if(turn == false) return dpF[start][end]=Math.min(one, two);
	  else return dpF[start][end]=Math.max(one+game[start], two+game[end]);
	  
  
  }
  
  
  
  
}