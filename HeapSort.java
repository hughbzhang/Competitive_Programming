package Algorithms;

import java.awt.Point;
import java.util.Comparator;
import java.util.PriorityQueue;

public class HeapSort {
	public static void main(String[] args){
		
		int[] list = sort(new int[]{45, 23, 32 ,53,23, 21,31,2, 1,2, 1,2 ,234, 2,4, 3,5, 2,3 });
		
		
		for(int x = 0;x<list.length;x++) System.out.print(list[x]+" ");
		
		
		
	}
	static int[] sort(int[] list){
		
		PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
		for(int x = 0;x<list.length;x++) heap.add(list[x]);
		for(int a = 0;a<list.length;a++) list[a] = heap.poll();
		return list;
		
	}
	
	final Comparator<Point> mine = new Comparator<Point>(){
		public int compare(Point one, Point two){
			if(one.y<two.y) return -1;
			if(one.y>two.y) return 1;
			else return 0;
		}
	};
	
	
	
	
	
}
