package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: cowtour
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class cowtour {
	
	static int[][] split;//holds the different fields
	static double[][] matrix;//holds the distances between each pasture
	static boolean[] travel;//holds the path to makes sure no infinite loop
	static int[][] pos;//positions of each field
	static int pastures;//number of pastures
	static double[] max;//max diameter from each vertice.
	static double[] corner;//diameter of each field
	static int depth;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("cowtour.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowtour.out")));
     
     pastures = Integer.parseInt(f.readLine());
     pos = new int[pastures][2];
     matrix = new double[pastures][pastures];
     travel = new boolean[pastures];
     split = new int[pastures][pastures];
     max = new double[pastures];
     
     for(int y = 0;y<pastures;y++){
    	 StringTokenizer st = new StringTokenizer(f.readLine());
    	 pos[y][0] = Integer.parseInt(st.nextToken());
    	 pos[y][1] = Integer.parseInt(st.nextToken());
     }
     
     for(int y = 0; y<pastures;y++){
    	 String temp = f.readLine();
    	 for(int x = 0;x<pastures;x++){
    		 matrix[y][x] = temp.charAt(x)-48; 
    		 split[y][x]=-1;
    	 }
     }
     int index = 0;
     int start = check();
     while(start>=0){
    	 floodfill(index, start);
    	 start = check();
    	 index++;
     }
     
     depth = 0;
     boolean go = true;
     for(int y = 0;y<pastures;y++){
    	 if(go&&split[y][0]==-1){
    		 go = false;
    		 depth = y;
    	 }
     }
    
     
     //FLOWD-WARSHALL ALGORITHM
     for(int y = 0;y<pastures;y++){
    	 for(int x = 0;x<pastures;x++){
    		 if(matrix[y][x]==0.0) matrix[y][x]=Double.MAX_VALUE;
    	 }
     }
     
     for(int a = 0; a<depth;a++){//this increments the different fields
    	 
    	 
    	 
	     for(int y = 0;y<pastures;y++){//fill original depths
	    	 if(split[a][y]==-1) break;
	    	 for(int x = 0;x<pastures;x++){
	    		 if(split[a][x]==-1) break;
	    		 int first = split[a][y];
	    		 int second = split[a][x];
	    		 
	    		 if(matrix[first][second]==Double.MAX_VALUE) continue;
	    		 matrix[first][second] = dist(first, second);
	    		 matrix[second][first]= matrix[first][second];
	    	 }
	     }
	     
	     for(int b = 0;b<pastures;b++){
	    	 if(split[a][b]==-1) break;
		     for(int y = 0;y<pastures;y++){
		    	 if(split[a][y]==-1) break;
		    	 for(int x = 0;x<pastures;x++){
		    		 if(split[a][x]==-1) break;
		    		 if(y==b||x==b||x==y) continue;
		    		 int B = split[a][b];
		    		 int Y = split[a][y];
		    		 int X = split[a][x];
		    		 if(matrix[Y][B]==Double.MAX_VALUE||matrix[B][X]==Double.MAX_VALUE) continue;
		    		 
		    		 if(matrix[Y][B]+matrix[B][X]<matrix[Y][X]){
		    			 matrix[Y][X] = matrix[Y][B]+matrix[B][X];
		    			 matrix[X][Y] = matrix[Y][B]+matrix[B][X];
			    			
		    		 }
		    		 
		    	 }
		     }
	     }
	     
     }
     
     
     
     
     for(int y = 0;y<pastures;y++){
    	 for(int x = 0;x<pastures;x++){
    		 if(matrix[y][x]==Double.MAX_VALUE) matrix[y][x]=0;
    		 if(matrix[y][x]>max[y]) max[y]=matrix[y][x];
    	 }
    	 
     }
     
     
     
     
     
     corner = new double[depth];
     for(int y = 0;y<depth;y++){
    	 for(int x = 0;x<pastures;x++){
    		 if(split[y][x]==-1) break;
    		 if(max[x]>corner[y]) corner[y]=max[x];
    	 }
     }
     
     for(int x = 0;x<corner.length;x++){
    	 System.out.println(corner[x]);
     }
     
     
     double answer = Double.MAX_VALUE;
     
     for(int y = 0;y<pastures;y++){
    	 for(int x = y+1;x<pastures;x++){
    		 Point temp = same(x, y);
    		 if(temp==null) continue;
    		 //double storage = max[x]+max[y]+dist(x,y);
    		 double storage = max(max[x]+max[y]+dist(x,y), corner[temp.x], corner[temp.y]);
    		 if(storage<answer) answer = storage;
    		 
    		 
    	 }
     }
     
     if(answer==Double.MAX_VALUE) answer = 1;
     
     //for(int x = 0;x<depth;x++) System.out.println(corner[x]);
     
     
     
     /*for(int y = 0;y<pastures;y++){
    	 for(int x = 0;x<pastures;x++){
    		 //System.out.print((int)matrix[y][x]+" ");
    	 }
    	// System.out.println();
     }*/
     
     answer = Math.round(answer*1000000);
     
     String done = Double.toString(answer/1000000);
     boolean good = false;
     int count = 0;
     
     for(int x = 0;x<done.length();x++){
    	 if(good) count++;
    	 if(done.charAt(x)=='.') good=true;
     }
     while(count<6){
    	 count++;
    	 done+="0";
     }
     
     
     
     
     out.println(done);
     
     
     
     
     
     
    f.close();                          
    out.close();                             
    System.exit(0);                            
  }
  static double max(double a, double b, double c){
	  
	  return Math.max(Math.max(a, b), c);
  }
  
  static Point same(int x, int y){
	  
	  int first = -1;
	  int second = -1;
	  
	  for(int a = 0; a<depth;a++){
		  for(int b = 0;b<pastures;b++){
			 if(split[a][b]==x) first = a;
			 else if(split[a][b]==y) second = a;
		  }
		  if(first!=-1&&second!=-1) break;
	  }
	  if(first==second) return null;
	  else return new Point(first, second);
  }
  
  static double dist(int start, int end){
	  
	  int startX = pos[start][0];
	  int startY = pos[start][1];
	  int endX   = pos[end][0];
	  int endY   = pos[end][1];
	  
	  
	  return Math.sqrt(Math.pow(endX-startX, 2)+Math.pow(endY-startY, 2));
	  
  }
  
  
  static void floodfill(int index, int start){
	  travel[start]=true;
	  for(int a = 0;a<pastures;a++){//add to split fields
		  if(split[index][a]==-1){
			  split[index][a]=start;
			  break;
		  }
	  }
	  
	  for(int x = 0; x<pastures;x++){
		  if(travel[x]==false&&matrix[start][x]!=0){//go through adjacency matrix and see possible edges.
			  
			  floodfill(index, x);//recurse
		  }
	  }
	  return;
  }
  
  
  static int check(){//returns true if still someplace unvisited
	  for(int x = 0; x<travel.length;x++){
		  if(travel[x]==false) return x;
	  }
	  return -1;
  }
}



/*
for(int y = 0; y<pastures;y++){

for(int x = 0;x<pastures;x++){
	 System.out.print(matrix[y][x]);
}
System.out.println();
}*/