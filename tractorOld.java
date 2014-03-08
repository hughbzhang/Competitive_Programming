package Contest;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;
import java.awt.Point;

public class tractorOld {

	static final int large = 2000000;
	static int total = 0;
	static int size;
	static int[][] field;
	static boolean[][] road;
	static boolean[][] visit;
	static boolean[][] base;
	static int step = 0;
	static int next = large;
	static Queue<Point> edge = new LinkedList<Point>();
	static int goal;
	static int low = large;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("tractor.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tractor.out")));
     size = Integer.parseInt(f.readLine());
     field = new int[size][size];
     visit = new boolean[size][size];
     road = new boolean[size][size];
     base = new boolean[size][size];
     goal = (int)Math.ceil(0.5*size*size);
     StringTokenizer st;
     
     for(int y = 0;y<size;y++){
     	st = new StringTokenizer(f.readLine());
     	for(int x = 0;x<size;x++){
     		field[y][x] = Integer.parseInt(st.nextToken());
     	}
     }
     
     Queue<Point> path = new LinkedList<Point>();
     
     
     int x, y;
     Point temp = new Point(1,4);
	     
     top: while(temp!=null){
    	 
    	 step = 0;
    	 next = large;
    	 for(int a = 0;a<size;a++) for(int b = 0;b<size;b++) road[a][b] = false;
    	 path.clear();
    	 path.add(temp);
    	 total = 0;
	     while(total<goal){

	    	
	     	while(!path.isEmpty()){
	     		 
	     			total++;
		    	 Point current = path.poll();
		    	 x = current.x;
		    	 y = current.y;
		    	// System.out.println(x+" "+y);
		    	 if(step==0)visit[y][x] = true;
		    	 road[y][x] = true;
		    	 
		    	 if(check(current, x, y+1)){
		    		 if(step==0)visit[y+1][x] = true;
		    		 road[y+1][x] = true;
		    		 if(step==0) base[y+1][x] = true;
		    		 path.add(new Point(x, y+1));
		    	 }
		    	 if(check(current, x, y-1)){
		    		 if(step==0)visit[y-1][x] = true;
		    		 road[y-1][x] = true;
		    		 path.add(new Point(x, y-1));
		    	 }
		    	 if(check(current, x+1, y)){
		    		 if(step==0)visit[y][x+1] = true;
		    		 road[y][x+1] = true;
		    		 path.add(new Point(x+1, y));
		    	 }
		    	 if(check(current, x-1, y)){
		    		 if(step==0)visit[y][x-1] = true;
		    		 road[y][x-1] = true;
		    		 path.add(new Point(x-1, y));
		    	 }
		    	 
		    }
	     	
	     	//System.out.println(step+" "+total);
	     	if(total>=goal) break;
	     	//System.out.println(step);
	     	//print();
	     	step +=next;
	     	//System.out.println(next);
	     	if(step>low){
	     		temp = out();
	     		continue top;
	     	}
	     	next = large;
	     	path = edge;
	     	edge = new LinkedList<Point>();
	     }
	     
	     if(step<low){
	    	 //System.out.println(step);
	    	 low = step;
	     }
	     temp = out();
     }
     out.println(low);
     
     
     
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static Point out(){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  if(visit[y][x]==false) return new Point(x, y);
		  }
	  }
	  return null;
  }
  
  static boolean check(Point old, int x, int y){
	  
	  int a = old.x;
	  int b = old.y;
	  
	  if(x<0||x>=size||y<0||y>=size) return false;
	  
	  int dist = Math.abs(field[y][x]-field[b][a]);
	  
	  if(dist>step){
		  if(dist-step<next){
			  edge.clear();
			  next = dist-step;
		  }
		  if(dist-step==next){
			  edge.add(new Point(x, y));
		  }
		  return false;
	  }
	  
	  if(road[y][x]) return false;
	  return true;
	  
  }
  
  
  static void print(){
	  
	  for(int y = 0;y<field.length;y++){
		  for(int x = 0;x<field[0].length;x++){
			  System.out.print(visit[y][x]+" ");
		  }
		  System.out.println();
	  }
	  System.out.println();
	  
  }
  
  
}