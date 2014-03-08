package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: fence4
*/


import java.util.*;
import java.io.*;



public class fence4 {
	static class Point{//REDEFINE POINT TO HAVE DOUBLE X AND Y
		public double x;
		public double y;
		public Point(double a, double b){
			x = a;
			y = b;
		}
		public Point copy(){
			return new Point(this.x, this.y);
		}
		public String toString(){
			return "["+x+","+y+"]";
		}
		
	}
	
	static class triangle{
		Point a;
		Point b;
		Point c;
		Point center;
		
		public triangle(int x, int y, int z, int d, int e, int f){
			a = new Point(x, y);
			b = new Point(z, d);
			c = new Point(e, f);
			center = center();
		}
		public triangle(Point one, Point two, Point three){
			a = one.copy();
			b = two.copy();
			c = three.copy();
			center = center();
		}
		public boolean inside(Point point){//test if a point is inside triangle
			return (sameSideNoTies(a, b, point, center)&&sameSideNoTies(b,c, point, center)&&sameSideNoTies(a,c, point, center));
		}
		
		private Point center(){
			double x = (a.x+b.x+c.x)/3;
			double y = (a.y+b.y+c.y)/3;
			return new Point(x,y);
		}
	}
	
	static class vector{
		double x;
		double y;
		double z;
		double length;
		
		public vector(double a, double b, double c){//standard vector
			x = a;
			y = b;
			z = c;//can be 0
			length = length();
		}
		public vector(Point one, Point two){
			x = two.x-one.x;
			y = two.y-one.y;
			z = 0;
			length = length();
		}
		
		
		private double length(){ return Math.sqrt(x*x+y*y+z*z);	}
		public String toString(){ return "["+x+", "+y+", "+z+"]";}
	}
	
	public static void main(String[] args)throws IOException{
		Scanner in = new Scanner(new FileReader("fence4.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fence4.out")));
		
		Point one = new Point(1,1);
		Point two = new Point(-2,1);
		Point three = new Point(1,3);
		Point four = new Point(1,2);
		System.out.println(intersectRay(three,four,one,two));
		
		int number = in.nextInt();
		Point see = new Point(in.nextInt(),in.nextInt());
		
		int[][] corners = new int[number+1][2];
		Point[] cor = new Point[number+1];
		for(int y = 0;y<number;y++){
			corners[y][0] = in.nextInt();
			corners[y][1] = in.nextInt();
			cor[y] = new Point(corners[y][0],corners[y][1]);
			for(int x = y-3;x>=0;x--){
				if(intersectSeg(cor[y-1],cor[y], cor[x], cor[x+1])){
					//System.out.println(x+" "+y);
					out.println("NOFENCE");
					out.close();
					in.close();
					System.exit(0);
				}
			}
		}
		corners[number][0] = corners[0][0];
		corners[number][1] = corners[0][1];
		cor[number] = new Point(corners[0][0], corners[0][1]);//last is wraparound
		
		ArrayList<Integer> fences = new ArrayList<Integer>();//fences are refered to by the first corner. Fence 0 is the first fence and Fence number-1 is the last one.
		ArrayList<Integer> answer = new ArrayList<Integer>();//fences that are the answer;
		
		for(int x = 0;x<number;x++){//fences
			triangle cur = new triangle(see, cor[x], cor[x+1]);//this is the triangle of interest
			fences.clear();
			for(int y = 0;y<number;y++){//others
				if(y==x) continue;
				if(cur.inside(cor[y])||cur.inside(cor[y+1])){
					if(x==5) System.out.print("INSIDE "+y+" ");
					fences.add(y);
				}
				else if(intersectSeg(cor[y], cor[y+1], see, cor[x])&&intersectSeg(cor[y], cor[y+1], see, cor[x+1])){
					if(x==5) System.out.print("SECT "+y+" ");
					fences.add(y);
				}
			}
			//At this point all possible blocking fences should be inside. THIS IS CHECKED
			//System.out.println();
			
			//PLEASE OPTIMIZE THIS PART IF NECESSARY
			boolean saw = false;
			Point mid = cor[x];//start at cor[x] and move toward cor[x+1]
			top: while(sameSideNoTies(see, cor[x+1], cor[x], mid)){//exit condition is mid point is past segment and no vision
				if(x==5) System.out.println(mid);
				for(int a = 0;a<fences.size();a++){
					if(intersectRay(see, mid, cor[fences.get(a)], cor[fences.get(a)+1])){//if a ray intersects
						Point old = mid;
						
						if(sameSideNoTies(see, cor[x+1], cor[fences.get(a)], mid)==false) break top;
						if(sameSideNoTies(see, cor[x+1], cor[fences.get(a)+1], mid)==false) break top;
						
						if(dist(cor[fences.get(a)], see, cor[x+1])>dist(cor[fences.get(a)+1], see, cor[x+1])) mid = cor[fences.get(a)+1];
						else mid = cor[fences.get(a)];//set mid to get close to the destination
	
						
						if(dist(old, see, cor[x+1])==dist(mid, see, cor[x+1])&&onLine(cor[x+1],mid,see)) break top;//if you get further quit
						
						System.out.println(fences.get(a));
						fences.remove(a);
						continue top;
					}
				}
				saw = true;
				break;
			}
			if(saw) answer.add(x);
			
		}
		
		/*
		 * Idea is this:
		 * 
		 * For each side of the fence:
		 * 
		 * 
		 * Determine all the fence segments that possibly could be blocking your view
		 * This is done by finding segments that 
		 * 1. either have a point(s) inside the cone formed from the see point to the end points of the fence segment. TIES DO NOT COUNT
		 * 2. OR intersect the edge TIES DO COUNT
		 * 
		 * Once this determined, draw the bot most ray. If it intersects a subset of these blocking fences, remove that fence, and draw a ray at its top endpoint.
		 * 
		 * If the endpoint is is outside of the top most ray, then fence is not visible.
		 * 
		 * 
		 * 
		 */
		if(answer.contains(number-1)&&answer.contains(number-2)){
			answer.remove(answer.size()-2);
			answer.add(number-2);
		}
		
		out.println(answer.size());
		for(int a = 0;a<answer.size();a++){
			int x = answer.get(a);
			if(x==number-1){
				out.println((int)cor[x+1].x+" "+(int)cor[x+1].y+" "+(int)cor[x].x+" "+(int)cor[x].y);
			}
			else out.println((int)cor[x].x+" "+(int)cor[x].y+" "+(int)cor[x+1].x+" "+(int)cor[x+1].y);
		}
		in.close();
		out.close();
		System.exit(0);
		
	}

	public static boolean onLine(Point A, Point B, Point C){
		return equal(A.x*(B.y-C.y)-A.y*(B.x-C.x)+B.x*C.y-C.x*B.y, 0);
	}
	
	public static boolean intersectSeg(Point A, Point B, Point C, Point D){ //AB and CD intersect?
		if(onLine(A,B,C)&&onLine(A,B,D)) return false;
		return !sameSideNoTies(A,B,C,D)&&!sameSideNoTies(C,D,A,B);
	}
	public static boolean intersectRay(Point A, Point B, Point C, Point D){ //Ray AB and Segment CD intersect?
		return !sameSideNoTies(A,B,C,D);
	}
	public static boolean sameSide(Point A, Point B, Point C, Point D){//if on line returns false; AB and Points C and D
		vector first = new vector(A,B);
		vector second = new vector(A,C);
		vector third = new vector(A,D);
		double answer = cross(first, second).z*cross(first, third).z;
		if(equal(answer,0)){
			//System.out.println("ON THE LINE");
			return true;
		}
		if(answer>0) return true;
		else return false;
		
		//(B - A) x (C - A) and (B - A) x (D - A)

	}
	public static boolean sameSideNoTies(Point A, Point B, Point C, Point D){//if on line returns false; AB and Points C and D
		vector first = new vector(A,B);
		vector second = new vector(A,C);
		vector third = new vector(A,D);
		double answer = cross(first, second).z*cross(first, third).z;
		if(equal(answer,0)){
			//System.out.println("ON THE LINE");
			return false;
		}
		if(answer>0) return true;
		else return false;
		//(B - A) x (C - A) and (B - A) x (D - A)
	}
	public static vector cross(vector u, vector v){//if zero then they are parallel
		double a = u.y*v.z-v.y*u.z;
		double b = u.z*v.x-u.x*v.z;
		double c = u.x*v.y-u.y*v.x;
		return new vector(a, b, c);
	}
	public static boolean equal(double a, double b){//floating point errors
		if(Math.abs(a-b)<0.000001) return true;
		else return false;
	}
	public static double dist(Point point, Point A, Point B){//AB is a line point is the point dist from point to line
		vector u = new vector(point.x-A.x,point.y-A.y, 0);
		vector v = new vector(B.x-A.x, B.y-A.y, 0);
		return cross(u,v).length/v.length;//If distance is zero, point is on the line
	}
}
