package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: maze1
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class maze1 {
	static int width;
	static int height;
	static int[][] field;
	static int[][] dist;
	static boolean[][] path;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("maze1.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("maze1.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     Point start1 = new Point();
     Point start2 = new Point();
     int max;
     
     
    width  = 2*Integer.parseInt(st.nextToken())+1;    
    height = 2*Integer.parseInt(st.nextToken())+1;  
    field = new int[height][width];
    dist = new int[height][width];
    path = new boolean[height][width];
    boolean first = true;
    for(int y = 0; y<height;y++){
    	String temp = f.readLine();
    	for(int x = 0; x<width;x++){
    		if(temp.charAt(x)==' ') field[y][x]=0;
    		else field[y][x]=1;
    	}
    }
    for(int y = 0; y<height;y++){
    	for(int x = 0;x<width;x++){
    		if(field[y][x]==0&&(x==0||x==width-1||y==0||y==height-1)){
    			dist[y][x]=0;
    			if(first){
    				start1 = new Point(x, y);
    				first = false;
    			}
    			else start2 = new Point(x,y);
    			path[y][x] = true;
    		}
    		else if(field[y][x]==1){
    			path[y][x] = true;
    			dist[y][x]=-1;
    		}
    		else{
    			
    			dist[y][x]=Integer.MAX_VALUE;
    		}
    	}
    }
    
    Queue<Integer> X = new LinkedList<Integer>();
    Queue<Integer> Y = new LinkedList<Integer>();
    Queue<Integer> past = new LinkedList<Integer>();
    X.add(start1.x);
    Y.add(start1.y);
    past.add(0);
    
    clear();
    BFS(X, Y, past);
    
    //DFS(start1.x, start1.y, 0);
    int max1 = find();
    
    X = new LinkedList<Integer>();
    Y = new LinkedList<Integer>();
    past = new LinkedList<Integer>();
    
    X.add(start2.x);
    Y.add(start2.y);
    past.add(0);
    
    
    clear();
    BFS(X, Y, past);
    //DFS(start2.x, start2.y, 0);
    int max2 = find();
    System.out.println(max1+" "+max2);
    max = Math.min(max1, max2);
   
   
   
    out.println((max+1)/2);
   
    //print(field);
    
    
    
    out.close();                             
    System.exit(0);                            
  }
  static int find(){
	  int max = 0;
	  for(int y = 0; y<height;y++){
		  for(int x = 0;x<width;x++){
			  if(dist[y][x]>max) max = dist[y][x];
		  }
	  }
	  return max;
  }
  static void clear(){
	  for(int y = 0; y<height;y++){
		  for(int x = 0;x<width;x++){
			  path[y][x]=false;
		  }
	  }
  }
  static void DFS(int x, int y, int past){
	  if(y<0||y>=height||x<0||x>=width) return;
	  if(dist[y][x]==-1) return;
	  if(past<dist[y][x]) dist[y][x] = past;
	  if(path[y][x]) return;
	  path[y][x]=true;
	  //if(past>max) max = past;
	  past++;
	  DFS(x+1, y, past);
	  DFS(x-1, y, past);
	  DFS(x, y+1, past);
	  DFS(x, y-1, past);
	  return;
	  
  }
  static void BFS(Queue<Integer> X, Queue<Integer> Y, Queue<Integer> past){
	  if(X.size()==0||Y.size()==0||past.size()==0) return;
	  int y = Y.poll();
	  int x = X.poll();
	  int d = past.poll();
	  
	  
	  if(y<0||y>=height||x<0||x>=width||dist[y][x]==-1){
		  BFS(X,Y,past);
		  return;
	  }
	  
	  if(d<dist[y][x]) dist[y][x] = d;
	  if(path[y][x]){
		  BFS(X,Y,past);
		  return;
	  }
	  path[y][x]=true;
	  //if(past>max) max = past;
	  d++;
	  X.add(x+1);
	  X.add(x-1);
	  X.add(x);
	  X.add(x);
	  Y.add(y);
	  Y.add(y);
	  Y.add(y+1);
	  Y.add(y-1);
	  past.add(d);
	  past.add(d);
	  past.add(d);
	  past.add(d);
	  
	  BFS(X, Y, past);
	  
	  
	  return;
	  
  }
  
  static boolean rem(){
	  for(int y = 0; y<height;y++){
		  for(int x = 0;x<width;x++){
			  if(path[y][x]==false) return true;
		  }
	  }
	  return false;
  }
  
  
  
  static void print(int[][] field){
	  for(int y = 0; y<height;y++){
	    	for(int x = 0; x<width;x++){
	    		if(field[y][x]==-1) System.out.print(0);
	    		else System.out.print(field[y][x]);
	    	}
	    	System.out.println();
	    }
  }
}