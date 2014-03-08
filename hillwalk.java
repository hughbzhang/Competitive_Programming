package Contest;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;

public class hillwalk {
  static class hill{
	  int x1;
	  int x2;
	  int y1;
	  int y2;
	  
	  public hill(int a, int b, int c, int d){
		  x1 = a;
		  y1 = b;
		  x2 = c;
		  y2 = d;
	  }
  	}
  static class val{
	  int x;
	  int y;
	  int index;
	  public val(int a, int b, int c){
		  x = a;
		  y = b;
		  index = c;
	  }
	  boolean contains(int a){
		  if(a>=x&&a<=y) return true;
		  else return false;
	  }
	  
  }
  static ArrayList<val> interval;
	
	public static void main (String [] args) throws IOException {
     Scanner in = new Scanner(new FileReader("hillwalk.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hillwalk.out")));
     
     int number = in.nextInt();
     interval = new ArrayList<val>();
     hill[] edge = new hill[number-1];
     hill start = new hill(in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt());
     for(int x = 0;x<number-1;x++){
    	 edge[x] = new hill(in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt());
     }
     final Comparator<hill> mine = new Comparator<hill>(){
			public int compare(hill one, hill two){
				if(one.y2<two.y2) return 1;
				if(one.y2>two.y2) return -1;
				else return 0;
			}
		};
     Arrays.sort(edge, mine);
     
     interval.add(new val(start.x1, start.x2-1, -1));
     for(int x = 0;x<edge.length;x++){
    	 insert(new val(edge[x].x1, edge[x].x2-1, x));
     }
     ArrayList<Integer> path = new ArrayList<Integer>();
     path.add(-1);
    // int pos = start.x2;
     
     

     
     
     
     
     
     in.close();
     out.close();                             
     System.exit(0);                            
  }
	static int find(int target){//RETURNS INDEX OF THE EDGE NOT THE INTERVAL
		int start = 0;
		int end = interval.size();
		int index = end/2;
		
		while(start<=end){
			val cur = interval.get(index);
			if(cur.contains(target)) return cur.index;
			else if(cur.y<target) start = index+1;
			else end = index-1;
			
			index = (start+end)/2;
			
		}
		return -2;
		
		
	}
	

	static void insert(val next){
		
		for(int x = 0;x<interval.size();x++){
			val cur = interval.get(x);
			if(next.x<cur.x){//base easiest case
				if(next.y<cur.x){
					interval.add(x, next);
					return;
				}
				else{//have to split up interval
					interval.add(x, new val(next.x, cur.x-1, next.index));
					if(next.y<=cur.y) return;
					next = new val(cur.y+1, next.y, next.index);
					x++;//compensate for inserting an element in.
				}
			}
			else if(next.x<=cur.y){
				if(next.y>cur.y) next = new val(cur.y+1, next.y, next.index);
				else return;
			}
		}
		
		interval.add(next);
		return;
	}
	
	
	static void print(hill[]edge){
		System.out.println();
	     for(int x = 0;x<edge.length;x++){
	    	 System.out.println(edge[x].x1+" "+edge[x].y1+" "+edge[x].x2+" "+edge[x].y2);
	     }
	}
}