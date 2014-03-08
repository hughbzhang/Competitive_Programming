package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: rect1
*/
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class rect1 {
	
	static class rect{
		int x;
		int y;
		int topX;
		int topY;
		int value;
		
		public rect(int a, int b, int c, int d, int e){
			x=a;
			y=b;
			topX=c;
			topY=d;
			value=e;
		}
	}
	static ArrayList<rect> list;//sorted list by x
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("rect1.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("rect1.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int  width = Integer.parseInt(st.nextToken());
     int height = Integer.parseInt(st.nextToken());
     int number = Integer.parseInt(st.nextToken());
     list = new ArrayList<rect>();
     list.add(new rect(0,0,width,height,1));
     
     for(int x = 0;x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 rect next = new rect(   Integer.parseInt(st.nextToken()),
					    		 Integer.parseInt(st.nextToken()),
					    		 Integer.parseInt(st.nextToken()),
					    		 Integer.parseInt(st.nextToken()),
					    		 Integer.parseInt(st.nextToken()));
    	check(next);
    	
     }
    // print();
     
     long[] colors = new long[1001];
     for(int x = 0;x<list.size();x++){
    	 rect cur = list.get(x);
    	 int w = cur.topX-cur.x;
    	 int h = cur.topY-cur.y;
    	 colors[cur.value]+=(w*h);
     }
     
     for(int x = 0;x<colors.length;x++){
    	 if(colors[x]!=0){
    		 out.println(x+" "+colors[x]);
    	 }
     }
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static void print(){
	  for(int x = 0;x<list.size();x++){
		  rect temp = list.get(x);
		  System.out.println(temp.x+" "+temp.y+" "+temp.topX+" "+temp.topY+" "+temp.value);
	  }
  }
  
  
  static void check(rect old){
	  //boolean first = true;
	  for(int x = 0;x<list.size();x++){
		  rect cur = list.get(x);
		  if(cur.x>old.topX) continue;
		  if(cur.topX<old.x) continue;
		  if(intersect(old,cur)){
			  list.remove(x);
			  x--;
			  fill(old, cur);
		  }
	 	  //if(first){
		  //	list.add(x, old);
	  	  //	first = false;
		  //}
	  }
	  list.add(old);
  }
  static void fill(rect over, rect under){
	  
	  //corners
	  if(over.x<under.x&&over.y<under.y&&over.topX<under.topX&&over.topY<under.topY){//over to the left and down
		  list.add(new rect(under.x, over.topY, under.topX, under.topY, under.value));
		  list.add(new rect(over.topX, under.y, under.topX, over.topY, under.value));
		  return;
	  }
	  if(over.x<under.x&&over.y>under.y&&over.topX<under.topX&&over.topY>under.topY){//over to the left and up
		  list.add(new rect(under.x, under.y, under.topX, over.y, under.value));
		  list.add(new rect(over.topX, over.y, under.topX, under.topY, under.value));
		  return;
	  }
	  if(over.x>under.x&&over.y<under.y&&over.topX>under.topX&&over.topY<under.topY){//over to the right and down
		  list.add(new rect(under.x, under.y, over.x, over.topY, under.value));
		  list.add(new rect(under.x, over.topY, under.topX, under.topY, under.value));
		  return;
	  }
	  if(over.x>under.x&&over.y>under.y&&over.topX>under.topX&&over.topY>under.topY){//over to the right and up
		  list.add(new rect(under.x, over.y, over.x, under.topY, under.value));
		  list.add(new rect(under.x, under.y, under.topX, over.y, under.value));
		  return;
	  }
	  //engulfs
	  if(over.x>under.x&&over.topX<under.topX&&over.topY<under.topY&&over.y>under.y){//completely consume
		  list.add(new rect(under.x, under.y, over.x, under.topY, under.value));
		  list.add(new rect(over.x, over.topY, over.topX, under.topY, under.value));
		  list.add(new rect(over.x, under.y, over.topX, over.y, under.value));
		  list.add(new rect(over.topX, under.y, under.topX, under.topY, under.value));
		  return;
	  }
	  
	  if(over.x<=under.x&&over.topX>=under.topX){//horizontal over vertical under
		  if(under.y<over.y) list.add(new rect(under.x, under.y, under.topX, over.y, under.value));
		  if(under.topY>over.topY) list.add(new rect(under.x, over.topY, under.topX, under.topY, under.value));
		  return;
	  }
	  if(over.y<=under.y&&over.topY>=under.topY){//vertical over horizontal under
		  if(under.x<over.x) list.add(new rect(under.x, under.y, over.x, under.topY, under.value));
		  if(under.topX>over.topX) list.add(new rect(over.topX, under.y, under.topX, under.topY, under.value));
		  return;
	  }
	  //final few cases
	  
	  if(over.x>=under.x&&over.topX<=under.topX){//up/down
		  if(under.x!=over.x) list.add(new rect(under.x, under.y, over.x, under.topY, under.value));//left
		  if(under.topX!=over.topX) list.add(new rect(over.topX, under.y, under.topX, under.topY, under.value));//right
		  //mid
		  if(over.topY<under.topY) list.add(new rect(over.x, over.topY, over.topX, under.topY, under.value));
		  if(over.y>under.y) list.add(new rect(over.x, under.y, over.topX, over.y, under.value));
		  return;
	  }
	  if(over.y>=under.y&&over.topY<=under.topY){//left/right
		  if(over.topY!=under.topY) list.add(new rect(under.x, over.topY, under.topX, under.topY, under.value));//top
		  if(over.y!=under.y) list.add(new rect(under.x, under.y, under.topX, over.y, under.value));//bot
		  //mid
		  if(over.x>under.x) list.add(new rect(under.x, over.y, over.x, over.topY, under.value));
		  if(over.topX<under.topX) list.add(new rect(over.topX, over.y, under.topX, over.topY, under.value));
		  return;
	  }
	  
	  
	 return; 
  }
  
  
  static boolean intersect(rect one, rect two){
	  if(one.x>=two.topX||two.x>=one.topX) return false;
	  if(one.y>=two.topY||two.y>=one.topY) return false;
	  return true;
  }
  
  static void cross(rect bot, rect top){//if direct overlap
	  
  }
  
}