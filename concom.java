package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: concom
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class concom {
	
	static ArrayList<Point> sol = new ArrayList<Point>();
	static int[] edge;
	static Point[][] list;
	static boolean[] visit;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("concom.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("concom.out")));
     
     int number = Integer.parseInt(f.readLine());
     StringTokenizer st;
     int max = 0;
     int a = 0;
     list = new Point [101][101];//down then across        1 2 NUMBER
     
     for(int x = 0; x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 int index =  Integer.parseInt(st.nextToken());
    	 for(a = 0;a<number;a++){
    		 if(list[index][a]==null){
    			 list[index][a]=new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
    			 break;
    		 }
    	 }
    	 
    	 
    	 
    	 int temp = Math.max(index,list[index][a].x);
    	 if(max<temp) max = temp;
     }
   /*  for(int y = 0;y<number;y++){
    	 System.out.print(y+" ");
    	 for(int x = 0;x<number;x++){
    		 if(list[y][x]==null) break;
    		 else System.out.print(list[y][x].x+" "+list[y][x].y+" ");
    	 }
    	 System.out.println();
     }*/
     
     
     visit = new boolean[max+1];
     edge = new int[max+1];
     for(int x = 1;x<=max;x++){
    	
    	 check(x);
    	 for(a = 0;a<edge.length;a++){
    		 if(edge[a]>50) sol.add(new Point(x, a));
    		 edge[a]=0;
    		 visit[a]=false;
    	 }
     }
     
     for(int x = 0;x<sol.size();x++){
    	 if(sol.get(x).x!=sol.get(x).y) out.println(sol.get(x).x+" "+sol.get(x).y);
     }
     
    out.close();                             
    System.exit(0);                            
  }
  static void check(int a){
	  visit[a]=true;
	  int counter = 0;
	  while(list[a][counter]!=null){
		  int index = list[a][counter].x;
		  edge[index]+=list[a][counter].y;
		  if(edge[index]>50&&visit[index]==false) check(index);
		  counter++;
	  }
  }
  
  
  static void print(int[][] list){
	  for(int x = 0;x<list.length;x++){
		  System.out.println(list[x][0]+" "+list[x][1]+" "+list[x][2]);
	  }
  }
}