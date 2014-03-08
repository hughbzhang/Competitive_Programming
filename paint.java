package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.awt.Point;
import java.io.*;
import java.util.StringTokenizer;

public class paint {
	static Point[][] track;
	static int coats;
	static int number;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("paint.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     number = Integer.parseInt(st.nextToken());
     coats = Integer.parseInt(st.nextToken());
     
     track = new Point[coats+1][1000];
     int cur = 0;
     int moves = 0;
     track[0][0] = new Point(-1000000001, 1000000001);
     for(int x = 0;x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 moves = Integer.parseInt(st.nextToken());
    	 if(st.nextToken().equals("L")){
    		 find(cur-moves, cur, 0);
    		 cur -= moves;
    	 }
    	 else{
    		 find(cur, cur+moves, 0); 
    		 cur+=moves;
    	 }
    	 merge();
     }
     print();
     
     int sum = 0;
     for(int x = 0;x<1000;x++){
    	 if(track[coats][x]==null) break;
    	 sum+=(track[coats][x].y-track[coats][x].x);
     }
     sum+=2;
     
     out.println(sum);
    out.close();                             
    System.exit(0);                            
  }
  static void merge(){
	 for(int y = 0; y<=coats;y++){
		 for(int x = 999;x>-1;x--){
			 if(track[y][x]==null) continue;
			 if(track[y][x].x==track[y][x].y) track[y][x] = null;
			 else break;
		 }
	 }
  }
  static void print(){
	  for(int y = 0;y<=coats;y++){
	    	 for(int x = 0;x<1000;x++){
	    		 if(track[y][x]==null) break;
	    		 System.out.print(track[y][x].x+" "+track[y][x].y+"       ");
	    	 }
	    	System.out.println();
	     }
	  System.out.println();
  }
  
  static void find(int start, int end, int depth){
	  System.out.println(start+" "+end);
	  print();
	  merge();
	  for(int y = depth;y<coats;y++){
		 
		  int x = 0;
		  if(start>=end) break;
		  Point cur = track[y][x];
		  //if(start>cur.y) continue;
		  while(cur!=null){
			  
			  if(start == cur.x&&end==cur.y){
				  add(y+1, start, end);
				  track[y][x].setLocation(0,0);
				  return;
			  }
			  
			  if(start<cur.x&&end>cur.y){
				  add(y+1, cur.x, cur.y);
				  find(start, cur.x, y);
				  find(cur.y, end, y);
				  
			  }
			  else if(start>cur.x&&end<cur.y){
				  add(y+1, start, end);
				  add(y, end, cur.y); 
				  track[y][x].setLocation(cur.x, start);
				  return;
			  }
			  else if(end<=cur.y&&end>cur.x&&start<cur.x){
				  add(y+1, cur.x, end);
				  find(start, cur.x, y);
				  track[y][x].setLocation(end, cur.y);
				  return;
			  }
			  else if(start>=cur.x&&start<cur.y&&end>cur.y){
				  add(y+1, start, cur.y);
				  find(cur.y, end, y);
				  track[y][x].setLocation(cur.x, start);
				  return;
			  }
			  
			  x++;
			  cur = track[y][x];
		  }
	  }
	 
  }
  static void add(int depth, int start, int end){
	  int x = 0;
	  while(track[depth][x]!=null){
		  x++;
	  }
	  track[depth][x] = new Point(start, end);
  }
}