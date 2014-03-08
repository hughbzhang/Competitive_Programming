package Algorithms;

import java.awt.Point;
import java.util.*;
import java.io.*;

public class DijkstraHeap {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("heap.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("heap.out")));
		
		StringTokenizer st;
		int number = Integer.parseInt(f.readLine());
		int[][] edgelist = new int[number][3];
		int max = 1;
		for(int y = 0;y<number;y++){
			st = new StringTokenizer(f.readLine());
			for(int x = 0;x<3;x++){
			edgelist[y][x] = Integer.parseInt(st.nextToken());
			}
			if(edgelist[y][0]>max) max = edgelist[y][0];
			if(edgelist[y][1]>max) max = edgelist[y][1];
		}
		int[][] matrix = new int[max+1][max+1];
		int[][] adj = new int[max+1][number];
		for(int y = 0;y<=max;y++) for(int x = 0;x<number;x++) adj[y][x] = -1;
		for(int y = 0;y<=max;y++) for(int x = 0;x<=max;x++) matrix[y][x] = Integer.MAX_VALUE;
		for(int a = 0;a<=max;a++) matrix[a][a] = 0;
		
		for(int x =0 ;x<number;x++){
			int start = edgelist[x][0];
			int end = edgelist[x][1];
			int dist = edgelist[x][2];
			matrix[start][end] = dist;
			matrix[end][start] = dist;
			int a = 0;
			while(adj[start][a]!=-1) a++;
			adj[start][a] = end;
			a = 0;
			while(adj[end][a]!=-1) a++;
			adj[end][a] = start;
		}
		
		int start = 1;
		boolean[] visit = new boolean[number];
		visit[start]=true;
		final Comparator<Point> mine = new Comparator<Point>(){
			public int compare(Point one, Point two){
				if(one.y<two.y) return -1;
				if(one.y>two.y) return 1;
				else return 0;
			}
		};
		PriorityQueue<Point> heap = new PriorityQueue<Point>(2*number, mine);//x represents vertex y represents distance
		for(int x = 2;x<=max;x++){
			heap.add(new Point(x, matrix[1][x]));
		}
		
		top: while(!heap.isEmpty()){
			Point next = heap.poll();//get the next point
			while(visit[next.x]){
				next = heap.poll();//if already visited continue getting next point. We do not remove from queue if updating
				if(next==null) break top;
			}
			int dest = next.x;
			visit[dest] = true;
			
			for(int x = 0;x<number;x++){
				int pos = adj[dest][x];
				if(pos==-1) break;
				if(matrix[start][pos]>matrix[start][dest]+matrix[dest][pos]){
					
					matrix[start][pos] = matrix[start][dest]+matrix[dest][pos];
					heap.add(new Point(pos, matrix[start][pos]));
					
				}
			}
		}
		
		
		
		
		
		
		
		
		/*for(int y = 0;y<=max;y++){
			for(int x = 0;x<number;x++){
				if(adj[y][x]==-1) break;
				System.out.print(adj[y][x]+" ");
			}
			System.out.println();
		}*/
		
		
		
		
		
		f.close();
		out.close();
		System.exit(0);
		
		
	}
	
	
	
	
	
	
	
	
	
	
}
