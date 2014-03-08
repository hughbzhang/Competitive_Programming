package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: comehome
*/
import java.io.*;
import java.util.*;
import java.awt.Point;

/*
 * Capital letter ASCII is from 65 to 90 inclusive
 * Lowercase is from 97 to 122 inclusive
 * 
 * Z (90) == 0
 * A (65) == 1
 * 
 * 
 * 
 * 
 */

public class comehome{
	
  static ArrayList<Integer> cows = new ArrayList<Integer>();
  static int[] dist = new int[53];
  static boolean[] path = new boolean[53];
  static Point[][] adj = new Point[53][10000];
  static int[][] matrix = new int[53][53];
  
  
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("comehome.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("comehome.out")));
     
     
     int paths = Integer.parseInt(f.readLine());
     int[][] edgelist = new int[paths][3];
     for(int y = 0; y<53;y++) for(int x = 0;x<53;x++) matrix[y][x] = Integer.MAX_VALUE;
     
     
     top: for(int x = 0;x<paths;x++){
    	 
    	 StringTokenizer st = new StringTokenizer(f.readLine());
    	 int first  = change((int)st.nextToken().charAt(0));
    	 int second = change((int)st.nextToken().charAt(0));
    	 int third  = Integer.parseInt(st.nextToken());
    	 edgelist[x][0] = first;
    	 edgelist[x][1] = second;
    	 edgelist[x][2] = third;
    	 if(matrix[first][second]>third){
    		 matrix[first][second] = third;
    		 matrix[second][first] = third;
    	 }
    	 
    	 
    	 for(int a = 0;a<10000;a++){
    		 if(adj[first][a]==null){
    			 adj[first][a] = new Point(second, third);
    			 //if(first==0&&second==15) System.out.println(third);
    			 break;
    		 }
    		 if(adj[first][a].x==second&&adj[first][a].y<=third) continue top;
    		 
    		 
    	 }
    	 for(int a = 0;a<10000;a++){
    		 if(adj[second][a]==null){
    			 adj[second][a] = new Point(first, third);
    			 //if(first==0&&second==15) System.out.println(third);
    			 break;
    		 }
    		 
    	 }
    	 
     }
     /*int max = Integer.MAX_VALUE;
     int start = 0;
     for(int x = 0;x<cows.size();x++){
    	 reset();
    	 int temp = path(cows.get(x));
    	 if (temp<max){
    		 max = temp;
    		 start = cows.get(x);
    	 }
     }
     
     
     
     
     
     out.println((char)(start+64)+" "+max);*/
     
     //Point temp = fast();
     
     //out.println((char)(temp.x+64)+" "+temp.y);
     //for(int x = 0;x<dist.length;x++) System.out.println(dist[x]);
     
    //for(int x = 0;x<cows.size();x++) System.out.println(cows.get(x));
    //print(edgelist, paths);
     for(int a = 0;a<53;a++){ 
    	 for(int y = 0; y<53;y++){
    		 for(int x = 0;x<53;x++){
    			 if(a==x||a==y) continue;
    			 if(matrix[y][a]==Integer.MAX_VALUE||matrix[a][x]==Integer.MAX_VALUE) continue;
    			 
    			 
    			 if(matrix[y][a]+matrix[a][x]<matrix[y][x]){
    				 matrix[y][x] = matrix[y][a]+matrix[a][x];
    			 }
    			 
    			 
    		 }
    	 }
     }
     
     
     
     int max = Integer.MAX_VALUE;
     int index = -1;
     
     for(int x = 1; x<27;x++){
    	 //System.out.println(matrix[0][x]);
    	 if(matrix[0][x]<max){
    		 max = matrix[0][x];
    		 index = x;
    	 }
     }
     
    out.println((char)(index+64)+" "+max);
    out.close();                             
    System.exit(0);                            
  }
  
  
  
  static int change(int first){
	 if(first==90) first = 0;
 	 else if(first > 90) first -=70;
 	 else{
 		 first-=64;
 		 cows.add(first);
 	 }
	 
	 return first;
  }
  static void print(int[][] printer, int paths){
	  for(int y = 0;y<paths;y++){
		  System.out.println(printer[y][0]+" "+printer[y][1]+" " +printer[y][2]);
	  }
  }
  static void print(Point[][] adj){
	  for(int y = 0;y<53;y++){
	    	 int x = 0;
	    	 System.out.print(y+" ");
	    	 while(adj[y][x]!=null){
	    		 System.out.print(adj[y][x].x+","+adj[y][x].y+" ");
	    		 x++;
	    	 }
	    	 System.out.println();
	     }
  }
  
  static int path(int start){
	  
	  dist[start] = 0;
	   
	  while(true){
		  path[start] = true;
		  for(int x = 0;x<10000;x++){
			  Point distance = adj[start][x];
			  if(distance==null) break;
			  
			  if(dist[distance.x]>dist[start]+distance.y) dist[distance.x]=dist[start]+distance.y;	  
		  }
		  
		  
		  start = next();
		  if(start==0) break;
	  }
	  
	  
	  
	  return dist[0];
  }
  static Point fast(){
	  reset();
	  int start = 0;
	  dist[start] = 0;
	   
	  while(true){
		  
		  path[start] = true;
		  
		  for(int x = 0;x<10000;x++){
			  
			  Point distance = adj[start][x];
			  if(distance==null) break;  
			  if(dist[distance.x]>dist[start]+distance.y) dist[distance.x]=dist[start]+distance.y;
			  
		  }
		  
		  start = find();
		  if(start==-1) break;
	  }
	  
	  
	  int small = Integer.MAX_VALUE;
	  int index = -1;
	  
	  for(int x = 1;x<27;x++){
		  if(dist[x]<small){
			  small=dist[x];
			  index =x;
			  
		  }
	  }
	  
	  
	  return new Point(index, small);
  }
  
  
  static int next(){
	  int small = Integer.MAX_VALUE;
	  int index = 0;
	  for(int x = 0;x<53;x++){
		  if(dist[x]<small&&path[x]==false) index = x;
	  }
	  
	  return index;
  }
  static int find(){
	  int small = Integer.MAX_VALUE;
	  int index = -1;
	  for(int x = 0;x<53;x++){
		  if(dist[x]<small&&path[x]==false){
			  index = x;
			  small = dist[x];
		  }
	  }
	  
	  return index;
  }
  
  static void reset(){
	  for(int x = 0;x<dist.length;x++){
		  dist[x] = Integer.MAX_VALUE;
	  }
	  for(int x = 0;x<path.length;x++){
		  path[x] = false;
	  }
  }
  
  
}