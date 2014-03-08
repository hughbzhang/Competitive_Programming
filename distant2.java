package Contest;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/

import java.io.*;
import java.util.*;

public class distant {
	
	static class node{
		int x;
		int y;
		int dist;
		public node(int a, int b, int c){
			x = a;
			y = b;
			dist = c;
		}
		
	}
	
	
	static boolean[][] field;
	static int size;
	static int diff;
	static int same;
	
	static final Comparator<node> mine = new Comparator<node>(){
		public int compare(node one, node two){
			if(one.dist<two.dist) return -1;
			if(one.dist>two.dist) return 1;
			else return 0;
		}
	};
	static PriorityQueue<node> heap = new PriorityQueue<node>(1000, mine);//x represents vertex y represents distance
	
	
	
	public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("distant.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("distant.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     size = Integer.parseInt(st.nextToken());
     same = Integer.parseInt(st.nextToken());
     diff = Integer.parseInt(st.nextToken());
     field = new boolean[size][size];
     
     
     for(int y = 0;y<size;y++){
    	 String temp = f.readLine();
    	 
    	 for(int x = 0;x<size;x++){
    		 if(temp.charAt(x)=='(') field[y][x] = true;
    		 else field[y][x] = false;
    	 }
     }
     
     for(int y = 0;y<size;y++){
    	 for(int x = 0;x<size;x++){
    		 System.out.println(search(y, x));
    	 }
     }
  
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static void print(boolean[][] field, int size){
	   for(int y = 0;y<size;y++){
	    	 for(int x = 0;x<size;x++){
	    		 if(field[y][x]) System.out.print(1);
	    		 else System.out.print(0);
	    	 }
	    	 System.out.println();
	     }
  }
  static int search(int y, int x){
	  
	  	boolean visit[][] = new boolean[size][size];
		int[][] dist = new int[size][size];
	  	for(int a = 0;a<size;a++){
			for(int b = 0;b<size;b++){
				if(field[y][x]!=field[a][b]) heap.add(new node(b, a, diff));
				else heap.add(new node(b, a, same));
				dist[a][b] = Integer.MAX_VALUE;
			}
		}
	  	dist[y][x] = 0;
		
		top: while(!heap.isEmpty()){
			node next = heap.poll();//get the next point
			while(visit[next.y][next.x]){
				next = heap.poll();//if already visited continue getting next point. We do not remove from queue if updating
				if(next==null) break top;
			}
			visit[next.y][next.x] = true;
			int b = next.y;
			int a = next.x;
			
			if(a+1<size){
				int far;
				if(field[b][a]==field[b][a+1]) far = same;
				else far = diff;
				if(dist[b][a+1]>dist[b][a]+far){
					dist[b][a+1]=dist[b][a]+far;
					heap.add(new node(a, b, dist[b][a+1]));
				}
			}
			if(a-1>-1){
				int far;
				if(field[b][a]==field[b][a-1]) far = same;
				else far = diff;
				if(dist[b][a-1]>dist[b][a]+far){
					dist[b][a-1]=dist[b][a]+far;
					heap.add(new node(a, b, dist[b][a-1]));
				}
			}
			if(b+1<size){
				int far;
				if(field[b][a]==field[b+1][a]) far = same;
				else far = diff;
				if(dist[b+1][a]>dist[b][a]+far){
					dist[b+1][a]=dist[b][a]+far;
					heap.add(new node(a, b, dist[b+1][a]));
				}
			}
			if(b-1>=0){
				int far;
				if(field[b][a]==field[b-1][a]) far = same;
				else far = diff;
				if(dist[b-1][a]>dist[b][a]+far){
					dist[b-1][a]=dist[b][a]+far;
					heap.add(new node(a, b, dist[b-1][a]));
				}
			}
			
		}
	  
	  	int max = 0;
	  	for(int b = 0;b<size;b++){
	  		for(int a = 0;a<size;a++){
	  			System.out.print(dist[b][a]);
	  			if(dist[b][a]>max) max = dist[b][a];
	  		}
	  	}
	  	return max;
	  
	  
	  
  }
}