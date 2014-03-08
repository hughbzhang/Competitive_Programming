package Algorithms;

import java.awt.Point;
import java.util.ArrayList;

public class interval {//insert an interval into our arraylist with old intervals taking priority
	
	public static void main(String[] args){
		ArrayList<Point> interval = new ArrayList<Point>();
		interval.add(new Point(2, 4));
		interval.add(new Point(7, 10));
		insert(interval, new Point(8, 9));
		
		System.out.println(interval);
		
	}
	
	static ArrayList<Point> insert(ArrayList<Point> interval, Point next){
		
		for(int x = 0;x<interval.size();x++){
			Point cur = interval.get(x);
			if(next.x<cur.x){//base easiest case
				if(next.y<cur.x){
					interval.add(x, next);
					return interval;
				}
				else{//have to split up interval
					interval.add(x, new Point(next.x, cur.x-1));
					if(next.y<=cur.y) return interval;
					next.setLocation(cur.y+1, next.y);
					x++;//compensate for inserting an element in.
				}
			}
			else if(next.x<=cur.y){
				if(next.y>cur.y) next.setLocation(cur.y+1, next.y);
				else return interval;
			}
			
			
		}
		
		interval.add(next);
		return interval;
	}
}
