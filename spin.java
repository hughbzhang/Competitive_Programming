package Solved;

/*
ID: bigfish2
TASK: spin
LANG: JAVA
 */


import java.awt.Point;
import java.io.*;
import java.util.StringTokenizer;

public class spin{
    
    static int[] speed;
    static int[][] wedges;
    static boolean[] marker = new boolean[360];
    
    static boolean print = false;
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader f = new BufferedReader(new FileReader("spin.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("spin.out")));
        
        speed = new int[5];
        wedges = new int[5][10];
        for(int y = 0;y<5;y++) for(int x = 0;x<10;x++) wedges[y][x] = -1;
        for(int x = 0;x<5;x++){
            StringTokenizer st = new StringTokenizer(f.readLine());
            speed[x] = Integer.parseInt(st.nextToken());
            int number = Integer.parseInt(st.nextToken());
            for(int a = 0;a<number;a++){
                wedges[x][2*a]=Integer.parseInt(st.nextToken());
                wedges[x][2*a+1] = wedges[x][2*a]+Integer.parseInt(st.nextToken());
                wedges[x][2*a+1]%=360;
            }
        }
    	if(check()){
    		out.println(0);
    		f.close();
    		out.close();
    		System.exit(0);
    	}
        for(int x = 1;x<360;x++){
        	add();
        	//if(x==298) print = true;
        	if(print) print();
        	if(check()){
        		out.println(x);
        		f.close();
        		out.close();
        		System.exit(0);
        	}
        	print = false;
        	
        }
        
        
        out.println("none");
        f.close();
        out.close();
        System.exit(0);
    }
    static void print(){
        for(int y = 0;y<5;y++){
            for(int x = 0;x<10;x++){
                System.out.print(wedges[y][x]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
    
    static void add(){
        for(int y = 0;y<5;y++){
            for(int x = 0;x<10;x++){
                if(wedges[y][x]==-1) break;
                wedges[y][x]+=speed[y];
                wedges[y][x]%=360;
            }
        }
    }
    static boolean check(){
        Point temp;
        for(int a = 0;a<5;a++){
            if(wedges[0][2*a]==-1) break;//for the initial spinning disk
            int ONE = wedges[0][2*a];
            int one = wedges[0][2*a+1];
            for(int b = 0;b<5;b++){
                if(wedges[1][2*b]==-1) break;//for the initial spinning disk
                temp = window(ONE, one, wedges[1][2*b], wedges[1][2*b+1]);
                if(temp==null) continue;
                int TWO = temp.x;
                int two = temp.y;
                for(int c = 0;c<5;c++){
                    if(wedges[2][2*c]==-1) break;//for the initial spinning disk
                    temp = window(TWO, two, wedges[2][2*c], wedges[2][2*c+1]);
                    if(temp==null) continue;
                    int THREE = temp.x;
                    int three = temp.y;
                    for(int d = 0;d<5;d++){
                        if(wedges[3][2*d]==-1) break;//for the initial spinning disk
                        temp = window(THREE, three, wedges[3][2*d], wedges[3][2*d+1]);
                        if(temp==null) continue;
                        int FOUR = temp.x;
                        int four = temp.y;
                        for(int e = 0;e<5;e++){
                            if(wedges[4][2*e]==-1) break;//for the initial spinning disk
                            temp = window(FOUR, four, wedges[4][2*e], wedges[4][2*e+1]);
                            if(temp==null) continue;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    static Point window(int a, int b, int c, int d){
    	if(b<a) b+=360;
    	if(d<c) d+=360;
    	for(int x = a; x<=b;x++){
    		marker[x%360] = true;
    	}
    	boolean first = false;
    	int start = -1;
    	int end = -1;
    	for(int x = c;x<=d;x++){
    		if(first==false&&marker[x%360]){
    			start = x%360;
    			first = true;
    		}
    		if(first&&marker[x%360]==false){
    			end = x-1;
    			break;
    		}
    	}
    	start%=360;
    	end %=360;
    	if(start ==-1) return null;
    	if(end == -1) end = start;
    	return new Point(start, end);
    	
    }
    static void clear(){
    	for(int x = 0;x<marker.length;x++){
    		marker[x] = false;
    	}
    }
    
    static Point sect(int a, int b, int c, int d){
    	if(print)System.out.println(a+" "+b+" "+c+" "+d);
    	if(intersect(a, b, c, d)==false) return null;
    	if((a>b&&c<=d)){
    		if(b>d) return new Point(c, d);
    		if(b>c) return new Point(b, c);
    	}
    	else if((a<=b&&c>d)){
    		if(d>b) return new Point(a, b);
    		if(d>a) return new Point(a, d);
    	}
    	
    	if(b<a) b+=360;
    	if(d<c) d+=360;
    	int x = Math.max(a,c)%360;
    	int y = Math.min(b,d)%360;
    	return new Point(x, y);
    }
    static boolean intersect(int x, int y, int a, int b){//VERY TRICKY
        
        if(x<=y&&a<=b){
        	if(a>y) return false;//false for base case
        	if(x>b) return false;
        	return true;
        }
        if(x>y&&a>b) return true;//if both reversed then guaranteed intersect
        if(b<x&&a>y) return false;//last case
        return true;
    }
    
}
