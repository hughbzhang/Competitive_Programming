package Algorithms;

/**
 * This is my library for Algorithmical Computational Geometry. It is based on the USACO text and does not include complex algorithms such as Convex Hull.
 * 
 * Also missing 3D lines
 * 
 * 
 */

public class Geometry {
	
	static class Point3D{//3D Point
		public double x;
		public double y;
		public double z;
		public Point3D(double a, double b, double c){
			x = a;
			y = b;
			z = c;
		}
	}
	
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
	}
	
	static class line{
		double slope;
		double intercept;
		vector vector;
		public line(double a, double b){
			slope = a;
			intercept = b;
			vector = new vector(1, slope, 0);
		}
		public line (Point one, Point two){//y = mx+b returns Point(m,b)
			if(two.x-one.x==0){
				slope=Double.NaN;
				intercept = Double.NaN;
				vector = null;
			}
			else{
				slope = ((double)(two.y-one.y))/(two.x-one.x);
				intercept = two.y-slope*two.x;
				vector = new vector(two.x-one.x, two.y-one.y, 0);
			}
		}
		
		public double calc(double x){ return slope*x+intercept;} //calculate the y when given the x
		public String toString(){return "y="+slope+"x+"+intercept;}
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
		public vector(Point3D one, Point3D two){
			x = two.x-one.x;
			y = two.y-one.y;
			z = two.z-one.z;
			length = length();
		}
		
		private double length(){ return Math.sqrt(x*x+y*y+z*z);	}
		public String toString(){ return "["+x+", "+y+", "+z+"]";}
	}
	
	static class triangle{
		Point a;
		Point b;
		Point c;
		Point center;
		double area;
		
		public triangle(int x, int y, int z, int d, int e, int f){
			a = new Point(x, y);
			b = new Point(z, d);
			c = new Point(e, f);
			area = area();
			center = center();
		}
		public triangle(Point one, Point two, Point three){
			a = one.copy();
			b = two.copy();
			c = three.copy();
			center = center();
		}
		
		public boolean inside(Point point){//test if a point is inside triangle
			return (sameSide(a, b, point, center)&&sameSide(b,c, point, center)&&sameSide(a,c, point, center));
		}
		
		private Point center(){
			double x = (a.x+b.x+c.x)/3;
			double y = (a.y+b.y+c.y)/3;
			return new Point(x,y);
		}
		private double area(){
			vector u = new vector(b.x-a.x, b.y-a.y, 0);
			vector v = new vector(c.x-a.x, c.y-a.y, 0);
			return 0.5*cross(u,v).length;
		}
		public double heron(int a, int b, int c){//a b c are side lengths
			double s = (a+b+c)/2;
			return Math.sqrt(s*(s-a)*(s-b)*(s-c));
		}
	}
	static class polygon{//polygons with integer coodinates always have areas that end in .5 or .0
		
		Point[] corners;
		int number;
		double area;
		Point center;
		public polygon(Point... args){
			corners = args;
			number = corners.length;
			area = area();
			center = center();
		}
		public boolean insideConcave(Point point){//test if a point is inside CONCAVE polygon
			for(int a = 0;a<number;a++){
				int next = a+1;
				if(next==number) next = 0;
				if(sameSide(corners[a], corners[next], center, point)==false) return false;
			}
			return true;
		}
		
		private double area(){
			int answer = 0;
			for(int x = 0;x<number;x++){
				int next = x+1;
				if(next==number) next = 0;
				answer+=corners[x].x*corners[next].y;
				answer-=corners[x].y*corners[next].x;
			}
			return Math.abs(answer/2);
		}
		private Point center(){
			double x = 0;
			double y = 0;
			for(int a = 0;a<number;a++){
				x+=corners[a].x;
				y+=corners[a].y;
			}
			return new Point(x/number,y/number);
		}
	}
	
	//d(P,AB) = |(P - A) x (B - A)| / | B - A|
	public static double dist(Point point, Point A, Point B){//AB is a line point is the point dist from point to line
		vector u = new vector(point.x-A.x,point.y-A.y, 0);
		vector v = new vector(B.x-A.x, B.y-A.y, 0);
		return cross(u,v).length/v.length;//If distance is zero, point is on the line
	}
	public static double dist(Point one, Point two){//dist between two points
		return Math.sqrt(Math.pow(two.x-one.x,2)+Math.pow(two.y-one.y,2));
	}
	
	public static vector cross(vector u, vector v){//if zero then they are parallel
		double a = u.y*v.z-v.y*u.z;
		double b = u.z*v.x-u.x*v.z;
		double c = u.x*v.y-u.y*v.x;
		return new vector(a, b, c);
	}
	
	public static double dot(vector a, vector b){//if positive acute angle if zero right if negative obtuse
		return a.x*b.x+a.y*b.y+a.z*b.z;
	}
	public static boolean equal(double a, double b){//floating point errors
		if(Math.abs(a-b)<0.000001) return true;
		else return false;
	}
	
	public static boolean sameSide(line test, Point C, Point D){
		if(onLine(C, test)||onLine(D, test)) return true;//if its on the line lets just say that it is on the same side
		Point A = new Point(0, test.calc(0));
		Point B = new Point(1, test.calc(1));
		vector first = new vector(A,B);
		vector second = new vector(A,C);
		vector third = new vector(A,D);
		double answer = cross(first, second).z*cross(first, third).z;
		if(equal(answer,0)){
			System.out.println("PROBLEM WITH SAME SIDE FUNCTION");
			return true;
		}
		if(answer>0) return true;
		else return false;
		
		//(B - A) x (C - A) and (B - A) x (D - A)
	}
	public static boolean sameSideNoTies(line test, Point C, Point D){
		if(onLine(C, test)||onLine(D, test)) return true;//if its on the line lets just say that it is on the same side
		Point A = new Point(0, test.calc(0));
		Point B = new Point(1, test.calc(1));
		vector first = new vector(A,B);
		vector second = new vector(A,C);
		vector third = new vector(A,D);
		double answer = cross(first, second).z*cross(first, third).z;
		if(equal(answer,0)){
			System.out.println("PROBLEM WITH SAME SIDE FUNCTION");
			return false;
		}
		if(answer>0) return true;
		else return false;
		
		//(B - A) x (C - A) and (B - A) x (D - A)
	}
	public static boolean sameSide(Point A, Point B, Point C, Point D){//if on line returns false; AB and Points C and D
		vector first = new vector(A,B);
		vector second = new vector(A,C);
		vector third = new vector(A,D);
		double answer = cross(first, second).z*cross(first, third).z;
		if(equal(answer,0)){
			System.out.println("ON THE LINE");
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
			System.out.println("ON THE LINE");
			return false;
		}
		if(answer>0) return true;
		else return false;
		//(B - A) x (C - A) and (B - A) x (D - A)
	}
	
	public static boolean onLine(Point point, line line){ return point.y==line.calc(point.x); }
	public static boolean onSeg(Point point, Point A, Point B){
		if(onLine(point, new line(A,B))==false) return false;
		if(dist(point, A)+dist(point,B)!=dist(A,B)) return false;
		return true;
	}
	public static boolean coplane(Point3D[] points){//checks if the following points are coplaner
		if(points.length<=3) return true;
		vector one = new vector(points[0],points[1]);
		vector two = new vector(points[0],points[2]);
		vector calc = cross(one, two);
		
		for(int x = 3;x<points.length;x++){
			vector next = new vector(points[0],points[x]);
			if(equal(dot(next,calc),0)==false) return false;
		}
		return true;
	}//(B - A) x (C - A)) · (D - A)
	public static boolean parallel(line one, line two){
		return equal(one.slope, two.slope);
	}
	public static boolean intersectSeg(Point A, Point B, Point C, Point D){ //AB and CD intersect?
		return !sameSideNoTies(A,B,C,D)&&!sameSideNoTies(C,D,A,B);
	}
	
	public static void main(String[] args){
		Point A = new Point(0,0);
		Point B = new Point(5,5);
		Point C = new Point(0,5);
		Point D = new Point(5,0);
		System.out.println(intersectSeg(A,C,B,D));
	}
}
