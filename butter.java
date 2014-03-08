package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: butter
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class butter {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("butter.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("butter.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     //System.out.println("start");
     int cows = Integer.parseInt(st.nextToken());
     int pastures = Integer.parseInt(st.nextToken());
     int paths = Integer.parseInt(st.nextToken());
     int[] loc = new int[cows];
     int[][] adj = new int[pastures][pastures];
     int[][] edge = new int[pastures][pastures];
     boolean [] past = new boolean[pastures];
     
     
     for(int y = 0;y<pastures;y++){
    	 for(int x = 0;x<pastures;x++){
        	 adj[y][x] = Integer.MAX_VALUE;
        	 edge[y][x] = -1;
         }
     }
     
     for(int x = 0;x<cows;x++){
    	 loc[x] = Integer.parseInt(f.readLine())-1;
     }
     
     for(int x = 0;x<paths;x++){
    	 st = new StringTokenizer(f.readLine());
    	 int a = Integer.parseInt(st.nextToken())-1;
    	 int b = Integer.parseInt(st.nextToken())-1;
    	 adj[a][b] = Integer.parseInt(st.nextToken());
    	 adj[b][a] = adj[a][b];
     }
     for(int x = 0;x<pastures;x++) adj[x][x] = 0;
     
     int counter = 0;
     
     for(int x = 0;x<pastures;x++){
    	 for(int a = 0;a<pastures;a++){
    		 if(adj[x][a]!=Integer.MAX_VALUE&&adj[x][a]!=0){
    			 edge[x][counter] = a;
    			 counter++;
    		 }
    	 }
    	 counter = 0;
     }
     
     int least = Integer.MAX_VALUE;
     //Disjerta
     int[] dist = new int[pastures];
     final Comparator<Point> mine = new Comparator<Point>(){
			public int compare(Point one, Point two){
				if(one.y<two.y) return -1;
				if(one.y>two.y) return 1;
				else return 0;
			}
		};
		
     PriorityQueue<Point> list = new PriorityQueue<Point>(pastures, mine);
     int current;
     //System.out.println("start");
     
    for(int x = 0;x<loc.length;x++){//each cow pasture
    	 //list.clear();
    	 int start = loc[x];
    	 dist[0] = Integer.MAX_VALUE;
    	 past[0] = false;
    	 for(int a = 1;a<pastures;a++){
    		 dist[a]  = adj[start][a];//clear dist log
    		 list.add(new Point(a,dist[a]));
    		 past[a] = false;
    	 }
    	 dist[start] = 0;// dist from start point
    	 //begin
    	 current = start;
    	 //System.out.println("new");
    	 top: while(true){
    		 int dest = edge[current][0];
    		 past[current]= true;
    		 int a = 0;
	    	 while(dest!=-1){
	    		 
	    		 if(dist[current]+adj[current][dest]<dist[dest]){
	    			 //list.remove(new Point(dest, dist[dest]));
	    			 dist[dest] = dist[current]+adj[current][dest];
	    			 adj[start][dest] = dist[dest];
	    			 list.add(new Point(dest, dist[dest]));
	    		 }
	    		 a++;
	    		 dest = edge[current][a];
	    	 }
	    	 
	    	 while(past[current]){
	    		 if(list.size()==0) break top;
	    		 current = list.poll().x;;
	    	 }
    	 }
    	 //for(int b = 0;b<dist.length;b++) adj[start][b] = dist[b];
    	 
     }
     int temp = 0;
     top: for(int x = 0;x<pastures;x++){
     	temp = 0;
    	 for(int b = 0; b<cows;b++){
			 temp+=adj[loc[b]][x];
			 if(adj[loc[b]][x]==Integer.MAX_VALUE) continue top;
		 }
     	 if(temp<least) least = temp;
     }
     out.println(least);
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
}