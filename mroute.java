package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: mroute
*/
import java.io.*;
import java.util.*;

public class mroute {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("mroute.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mroute.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
    	
     int junct = Integer.parseInt(st.nextToken());
     int pipes = Integer.parseInt(st.nextToken());
     int total = Integer.parseInt(st.nextToken());
     int[][] flow = new int[2*pipes][4];
     
     
     for(int x = 0;x<2*pipes;x=x+2){
    	 flow[x][0] = Integer.parseInt(st.nextToken());
    	 flow[x][1] = Integer.parseInt(st.nextToken());
    	 flow[x+1][0] = flow[x][1];
    	 flow[x+1][1] = flow[x][0];
    	 
    	 for(int a = 2;a<4;a++){
    		 flow[x][a] = Integer.parseInt(st.nextToken());
    		 flow[x+1][a] = Integer.parseInt(st.nextToken());
    	 }
     }
     
     
     
     
     
    out.close();                             
    System.exit(0);                            
  }
}