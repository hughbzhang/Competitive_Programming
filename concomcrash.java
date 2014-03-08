package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: concom
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class concomcrash {
	
	static ArrayList<Point> sol = new ArrayList<Point>();
	static int[] edge;
	static int[][] list;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("concom.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("concom.out")));
     
     int number = Integer.parseInt(f.readLine());
     StringTokenizer st;
     int max = 0;
     list = new int [number][3];//down then across        1 2 NUMBER
     for(int x = 0; x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 list[x][0] = Integer.parseInt(st.nextToken());
    	 list[x][1] = Integer.parseInt(st.nextToken());
    	 list[x][2] = Integer.parseInt(st.nextToken());
    	 int temp = Math.max(list[x][0],list[x][1]);
    	 if(max<temp) max = temp;
     }
     edge = new int[max+1];
     for(int x = 1;x<=max;x++){
    	
    	 check(x);
    	 for(int a = 0;a<edge.length;a++){
    		 if(edge[a]>50) sol.add(new Point(x, a));
    		 edge[a]=0;
    	 }
     }
     
     for(int x = 0;x<sol.size();x++){
    	 out.println(sol.get(x).x+" "+sol.get(x).y);
     }
     
    out.close();                             
    System.exit(0);                            
  }
  static void check(int a){
	  for(int x = 0;x<list.length;x++){
		  if(list[x][0]==a){
			  edge[list[x][1]]+=list[x][2];
			  if(edge[list[x][1]]>50) check(list[x][1]);
		  }
	  }
	  
	  
  }
  
  
  static void clear(){
	  for(int x = 0 ;x<edge.length;x++){
		  edge[x]=0;
	  }
  }
  
  
  static void print(int[][] list){
	  for(int x = 0;x<list.length;x++){
		  System.out.println(list[x][0]+" "+list[x][1]+" "+list[x][2]);
	  }
  }
}