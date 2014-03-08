package Contest;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.awt.Point;
import java.io.*;
import java.util.StringTokenizer;

public class perimeter {
	static int points;
	static boolean[][] field;
	static boolean[][] visit;
	static int height;
	static int width;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("perimeter.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("perimeter.out")));
    
     points = Integer.parseInt(f.readLine());
     int[][] holder = new int[points][2];
     
     int minX = Integer.MAX_VALUE;
     int minY = Integer.MAX_VALUE;
     int maxX = 0;
     int maxY = 0;
     
     for(int x = 0;x<points;x++){
    	 StringTokenizer st = new StringTokenizer(f.readLine());
    	 holder[x][0] = Integer.parseInt(st.nextToken());
    	 holder[x][1] = Integer.parseInt(st.nextToken());
    	 minX = Math.min(minX, holder[x][0]);
    	 minY = Math.min(minY, holder[x][1]);
    	 maxX = Math.max(maxX, holder[x][0]);
    	 maxY = Math.max(maxY, holder[x][1]);
     }
     
     height = maxY-minY+1;
     width = maxX-minX+1;
     field = new boolean[height][width];
     visit = new boolean[height][width];
     
     for(int a = 0;a<points;a++){
    	 
    	 int x = holder[a][0]-minX;
    	 int y = holder[a][1]-minY;
    	 field[y][x] = true;
    	 visit[y][x]=true;
     }
     
     int per = 2*(height+width);
     
     
     Point temp = find();
     while(temp!=null){
    	 if(flood(temp.x, temp.y)==false) mark(temp.x, temp.y);
    	 else{
    		 if(check(temp.x, temp.y)==false) per+=2;
    		 visit[temp.y][temp.x] = true;
    		 
    		 
    		 
    		 
    	 }
    	 temp = find();
     }
     
     
     
     
     
     
     
     
     
     
     
     
     out.println(per);
    
     
     
     f.close();
    out.close();                             
    System.exit(0);                            
  }
  static boolean check(int x, int y){
	  
	  boolean cond1 = false;
	  boolean cond2 = false;
	  boolean cond3 = false;
	  boolean cond4 = false;
	  
	  for(int a = 0;a<x;a++){
		  if(field[y][a]){
			  cond1 = true;
			  break;
		  }
	  }
	  for(int a = x;a<width;a++){
		  if(field[y][a]){
			  cond2 = true;
			  break;
		  }
	  }
	  if(cond1&&cond2) return false;
	  
	  
	  
	  
	  for(int a = 0;a<y;a++){
		  if(field[a][x]){
			  cond3 = true;
			  break;
		  }
	  }
	  for(int a = y;a<height;a++){
		  if(field[a][x]){
			  cond4 = true;
			  break;
		  }
	  }
	  if(cond3&&cond4) return false;
	  else return true;
  }
  
  
  static Point find(){
	  for(int y = 0;y<field.length;y++){
		  for(int x = 0;x<field[0].length;x++){
			  if(visit[y][x]==false) return new Point(x, y);
		  }
	  }
	  return null;
  }
  static void mark(int x, int y){
	  if(x<0||x>=width||y<0||y>=height) return;
	  if(field[y][x]) return;
	  field[y][x]=true;
	  visit[y][x]=true;
	  
	  mark(x+1, y);
	  mark(x-1, y);
	  mark(x, y+1);
	  mark(x, y-1);
	  
  }
  static boolean flood(int x, int y){
	  if(x<0||x>=width||y<0||y>=height) return true;
	  if(field[y][x]) return false;
	  
	  if(flood(x+1, y)) return true;
	  if(flood(x-1, y)) return true;
	  if(flood(x, y+1)) return true;
	  if(flood(x, y-1)) return true;
	  
	  return false;
	  
  }
  
  
  static void print(){
	  for(int y = 0;y<field.length;y++){
	    	 for(int x = 0;x<field[0].length;x++){
	    		 System.out.print(field[y][x]+" ");
	    	 }
	    	 System.out.println();
	     }
  }
}