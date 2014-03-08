package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: camelot
*/


import java.util.*;
import java.io.*;
import java.awt.*;


public class camelot {
	
	static class search{
		int y;
		int x;
		int value;
		public search(int a, int b, int c){
			x = a;
			y = b;
			value = c;
		}
	}
	
	static int[][] field;//0 = empty 1 = knight 2=king
	static ArrayList<Point> knights;
	static int[][] dist;//first is knight index second is board index value is distance
	static int max;
	static int rows;
	static int cols;
	static int LOC;
	static int[] index;
	static int[][] kings;
	static int[] kingsLOC;
	static Point king;
	static int walk;
	
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("camelot.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("camelot.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		rows = Integer.parseInt(st.nextToken());
		cols = Integer.parseInt(st.nextToken());
		field = new int[rows][cols];
		max = rows*cols;
		st = new StringTokenizer(f.readLine());
		king = new Point(st.nextToken().charAt(0)-65, Integer.parseInt(st.nextToken())-1);
		int KING = convert(king.y,king.x);
		field[king.y][king.x] = 2;
		knights = new ArrayList<Point>();
		LOC = convert(king.y, king.x);//king location
		kings = new int[49][max];
		kingsLOC = new int[49];
		String temp = f.readLine();
		while(temp!=null){
			st = new StringTokenizer(temp);
			while(st.hasMoreTokens()){
				Point a = new Point(st.nextToken().charAt(0)-65, Integer.parseInt(st.nextToken())-1);
				knights.add(a);
				field[a.y][a.x] = 1;
			}
			temp = f.readLine();	
		}
		System.out.println("start");
		dist = new int[knights.size()][max];
		index = new int[knights.size()];
		for(int a = 0;a<kingsLOC.length;a++){
			int up = (int)(a/7);
			int left = a%7;
			int y = king.y-3+up;
			int x = king.x-3+left;
			kingsLOC[a] = convert(y,x);
			if(y>=rows||y<0||x>=cols||x<0) kingsLOC[a] = -1;
		}
		
		for(int x = 0;x<index.length;x++){
			index[x] = convert(knights.get(x).y, knights.get(x).x);
		}
		for(int y = 0; y<knights.size();y++){
			for(int x = 0;x<max;x++){
				dist[y][x] = Integer.MAX_VALUE;
			}
		}
		for(int y = 0; y<49;y++){
			for(int x = 0;x<max;x++){
				kings[y][x] = Integer.MAX_VALUE;
			}
		}
		for(int x = 0;x<knights.size();x++){
			fill(x, knights.get(x).y, knights.get(x).x, dist, 0);
		}
		System.out.println("half");
		for(int x = 0;x<kingsLOC.length;x++){
			int a = kingsLOC[x];
			if(a==-1) continue;
			int start = kingDist(a, KING);
			
			fill(x, (int)(a/cols), a%cols, kings, start);
		}
		
		
		
		
		System.out.println("last");
		
		
		/*for(int x = 0;x<max;x++){
			if(x%cols==0) System.out.println();
			System.out.print(dist[0][x]+" ");
		}*/
		
		int cur = Integer.MAX_VALUE;
		
		//int debug = -1;
		
		for(int x = 0;x<max;x++){//destination
			//base case king walks there himself
			int base = base(x);
			if(base==-1) continue;
			if(cur>base) cur = base;
			base-=walk;
			int margin = cur-base;
			if(margin<=0) continue;
			for(int y = 0;y<knights.size();y++){//which knight picks up the king
				for(int a = 0;a<49;a++){
					if(kingsLOC[a]==-1) continue;
					if(dist[y][kingsLOC[a]]==Integer.MAX_VALUE) continue;
					if(kings[a][x]==Integer.MAX_VALUE) continue;
					if(dist[y][x]==Integer.MAX_VALUE) continue;
					
					int pos = dist[y][kingsLOC[a]]+kings[a][x]-dist[y][x];
					if(pos<margin){
					//	debug = a;
						margin = pos;
					}
				}
			}
			if(cur>margin+base){
				cur = margin+base;
				//System.out.println(cur+" "+debug);
			}
		}
		
		out.println(cur);
		
		
		
		f.close();
		out.close();
		System.exit(0);
	}
	static int base(int a){
		int answer = 0;
		for(int x = 0;x<knights.size();x++){
			if(dist[x][a]==Integer.MAX_VALUE) return -1;
			answer+=dist[x][a];
		}
		Point dest = revert(a);
		walk = Math.max(Math.abs(dest.x-king.x),Math.abs(dest.y-king.y));
		answer+=walk;
		
		
		return answer;
	}
	static int kingDist(int a, int b){
		Point one = revert(a);
		Point two = revert(b);
		return Math.max(Math.abs(one.x-two.x),Math.abs(one.y-two.y));
		
	}
	
	static void print(int[][] field){
		for(int y = 0;y<field.length;y++){
			for(int x = 0;x<field[0].length;x++){
				System.out.print(field[y][x]);
			}
			System.out.println();
		}
	}
	/*static void fill(int knight, int value, int y, int x, int[][] dist){
		if(y<0||y>=rows||x<0||x>=cols) return; //if outside board return
		if(dist[knight][y*cols+x]>value) dist[knight][y*cols+x] = value;//fill in value
		else return;
		value++;
		fill(knight, value, y+1, x+2, dist);
		fill(knight, value, y+1, x-2, dist);
		fill(knight, value, y-1, x+2, dist);
		fill(knight, value, y-1, x-2, dist);
		fill(knight, value, y-2, x+1, dist);
		fill(knight, value, y-2, x-1, dist);
		fill(knight, value, y+2, x+1, dist);
		fill(knight, value, y+2, x-1, dist);
		//send to 8 next spots
		return;
	}*/
	static void fill(int knight, int y, int x, int[][] dist, int start){
		if(y<0||y>=rows||x<0||x>=cols) return; //if outside board return
		Queue<search> list = new LinkedList<search>();//x is the location y is the value
		list.add(new search(x,y,start));
		
		while(!list.isEmpty()){
			search cur = list.poll();
			x = cur.x;
			y = cur.y;
			if(y<0||y>=rows||x<0||x>=cols) continue; //if outside board return
			if(dist[knight][y*cols+x]>cur.value) dist[knight][y*cols+x] = cur.value;//fill in value
			else continue;
			int value = cur.value+1;
			list.offer(new search(x+2,y+1, value));
			list.offer(new search(x+2,y-1, value));
			list.offer(new search(x-2,y+1, value));
			list.offer(new search(x-2,y-1, value));
			list.offer(new search(x+1,y+2, value));
			list.offer(new search(x+1,y-2, value));
			list.offer(new search(x-1,y+2, value));
			list.offer(new search(x-1,y-2, value));
		}
		
	}
	
	
	
	static int carry(int knight, int dest, int y, int x){
		int king = convert(y, x);
		return dist[knight][king]+dist[king][dest];
	}
	static int convert(int y, int x){
		return y*cols+x;
	}
	static Point revert(int loc){
		int y = (int)(loc/cols);
		int x = loc%cols;
		return new Point(x,y);
	}
}
