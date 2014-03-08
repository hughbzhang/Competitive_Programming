package Contest;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class tractor {
	
	static int[][] field;
	static int size;
	static int counter = 0;
	static boolean[][] visit;
	static int solution = -1;
	static int target;

	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("tractor.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tractor.out")));
     size = Integer.parseInt(f.readLine());
     field = new int[size][size];
     visit = new boolean[size][size];
     target = (int)Math.ceil(0.5*size*size);
     int max = 0;
     int min = Integer.MAX_VALUE;
     StringTokenizer st;
     
     for(int y = 0;y<size;y++){
     	st = new StringTokenizer(f.readLine());
     	for(int x = 0;x<size;x++){
     		field[y][x] = Integer.parseInt(st.nextToken());
     		if(min>field[y][x]) min = field[y][x];
     		if(max<field[y][x]) max = field[y][x];
     	}
     }
     
     int bot = 0;
     int top = max-min;
     while(top>bot){
    	 int mid = (top+bot)/2;
    	 if(search(mid)) top = mid;
    	 else bot = mid+1;
     }
     
     System.out.println(search(104782));
     
     out.println(top);
     f.close();
     out.close();                             
     System.exit(0);                            
  }
  static boolean search(int x){
	 clear();
 	 Point temp = find();
 	 while(temp!=null){
 		 counter = 0;
 		 flood(x, field[temp.y][temp.x], temp.x, temp.y);
 		 print();
 		 System.out.println(x);
 		 if(counter>=target){
 			 System.out.println(true);
     		 return true;
     	 }
 		 temp = find();
 	 }
 	 System.out.println(false);
 	 return false;
  }
  static Point find(){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  if(visit[y][x] == false) return new Point(x, y);
		  }
	  }
	  return null;
  }
  
  static void clear(){
	  for(int y = 0;y<size;y++){
		  for(int x = 0;x<size;x++){
			  visit[y][x] = false;
		  }
	  }
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
  static void flood(int cost, int past, int x, int y){
	  if(x<0||x>=size||y<0||y>=size) return;
	  if(visit[y][x]) return;
	  if(field[y][x]-past>cost) return;
	  visit[y][x] = true;
	  counter++;
	  
	  flood(cost, field[y][x], x+1, y);
	  flood(cost, field[y][x], x-1, y);
	  flood(cost, field[y][x], x, y+1);
	  flood(cost, field[y][x], x, y-1);
	  
	  return;
	  
  }
  
  
  
  
  
}