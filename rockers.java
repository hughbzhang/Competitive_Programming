package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: rockers
*/
import java.io.*;
import java.util.StringTokenizer;
import java.awt.*;

public class rockers {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("rockers.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("rockers.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int songs = Integer.parseInt(st.nextToken());
     int time = Integer.parseInt(st.nextToken());
     int disks = Integer.parseInt(st.nextToken());
     int[] length = new int[songs+1];
     st = new StringTokenizer(f.readLine());
     for(int x = 1;x<=songs;x++) length[x] = Integer.parseInt(st.nextToken());
     Point[][] dp = new Point[songs+1][songs+1];//Y = MAX ID NUMBER OF SONG USED --------- X = number of songs used
     
     //dp[y][x] = min(dp[y-1][x],dp[y-1][x-1]+length of current song)
     
     for(int y = 0;y<=songs;y++) dp[y][0] = new Point(0,0);
     for(int x = 1;x<=songs;x++) dp[0][x] = new Point(99999,99999);
   
     for(int y = 1;y<=songs;y++){
    	 for(int x = 1;x<=songs;x++){
    		 if(length[y]>time){
    			 dp[y][x] = dp[y-1][x];
    			 continue;
    		 }
    		 Point next = (Point)dp[y-1][x-1].clone();
    		 next.y+=length[y];
    		 if(next.y>time){
    			 next.y=length[y];
    			 next.x++;
    		 }
    		 dp[y][x] = min(next,dp[y-1][x]);
    	 }
     }
     print(dp);
     for(int x = 0;x<dp.length;x++){
    	 if(dp[songs][x].x>=disks){
    		 out.println(x-1);
    		 out.close();
    		 f.close();
    		 System.exit(0);
    	 }
     }
     out.println(songs);
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  public static void print(Point[][] dp){
	  int songs = dp.length-1;
	  for(int y = 0;y<=songs;y++){
	    	 for(int x = 0;x<=songs;x++){
	    		 if(dp[y][x]==null) System.out.print(null+" ");
	    		 else assist(dp[y][x]);
	    	 }
	    	 System.out.println();
	     }
  }
  
  public static void assist(Point print){
	  System.out.print("["+print.x+","+print.y+"] ");
  }
  public static Point min(Point one, Point two){
	  if(one.x<two.x) return one;
	  else if(one.x>two.x) return two;
	  else if(one.y<two.y) return one;
	  else return two;//return two in case of draw
	  
  }
}