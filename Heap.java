package Algorithms;

import java.awt.Point;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Heap {
	
	public static void main(String[] args){
		
	     final Comparator<Point> mine = new Comparator<Point>(){
				public int compare(Point one, Point two){
					if(one.y<two.y) return -1;
					if(one.y>two.y) return 1;
					else return 0;
				}
			};
			
	     PriorityQueue<Point> list = new PriorityQueue<Point>(20, mine);
		
	     list.add(new Point(1, 1));
	     list.add(new Point(1, 7));
	     list.add(new Point(1, 8));
	     
	     
	     
	     
		
	}
	
	
}
