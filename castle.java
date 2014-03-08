package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: castle
*/

import java.io.*;
import java.util.*;

public class castle{
	
	static int width;
	static int height;
	static int[][] field;//1 is an obstruction 0 is empty and 2 is passable wall
	static int[][] path;
	static int counter = 1;
	static int marker = 2;
	static ArrayList<Integer> size = new ArrayList<Integer>();
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("castle.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		width  =  2*Integer.parseInt(st.nextToken())+1;
		height = 2*Integer.parseInt(st.nextToken())+1;
		field = new int[height][width];
		path = new int [height][width];
		int PX = 0;
		int PY = 0;
		StringBuffer temp;
		
		
		
		for(int y = 0;y<height-1;y=y+2){
			st = new StringTokenizer(f.readLine());			
			for(int x  = 0; x<width-1;x=x+2){
				temp = new StringBuffer(Integer.toBinaryString(Integer.parseInt(st.nextToken())));
				while(temp.length()<4) temp.insert(0, "0");
				
				if(temp.charAt(0)=='1'){
					field[y+2][x]=1;
					field[y+2][x+1]=1;
					field[y+2][x+2]=1;
				}
				else{
					field[y][x]=1;
					field[y][x+1]=2;
					field[y][x+2]=1;
				}
				if(temp.charAt(1)=='1'){
					field[y][x+2]=1;
					field[y+1][x+2]=1;
					field[y+2][x+2]=1;
				}
				else{
					field[y][x]=1;
					field[y][x+1]=2;
					field[y][x+2]=1;
				}
				if(temp.charAt(2)=='1'){
					field[y][x]=1;
					field[y][x+1]=1;
					field[y][x+2]=1;
				}
				else{
					field[y][x]=1;
					field[y][x+1]=2;
					field[y][x+2]=1;
				}
				if(temp.charAt(3)=='1'){
					field[y][x]=1;
					field[y+1][x]=1;
					field[y+2][x]=1;
				}
				else{
					field[y][x]=1;
					field[y+1][x]=2;
					field[y+2][x]=1;
				}
			}
		}
		
		for(int y = 0; y<height;y++){
			for(int x = 0; x<width;x++){
				if(field[y][x]==1) path[y][x]=1;
				else path[y][x]=0;
			}
		}
		
		
		for(int y = 0; y<height;y++){
			for(int x = 0; x<width;x++){
				if(path[y][x]==0){
					fill(y, x, false);
					size.add(counter);
					counter = 1;
					marker++;
				}
			}
		}
		
		
		int holder = 0;
		int max = 0;
		
		//print(field);
		
		
		for(int x = 1;x<width-1;x++){
			for(int y = height-2;y>0;y--){
				if(path[y][x]==1){
					
					int a = path[y+1][x]-2;
					int b = path[y-1][x]-2;
					int c = path[y][x+1]-2;
					int d = path[y][x-1]-2;
					
					if(a==b) a = -1;
					if(a==c) a = -1;
					if(a==d) a = -1;
					if(b==c) b = -1;
					if(b==d) b = -1;
					if(c==d) c = -1;
					
					if(a>=0) a = size.get(a);
					
					if(b>=0) b = size.get(b);
					
					if(c>=0) c = size.get(c);
					
					if(d>=0) d = size.get(d);
					
					
					
					holder = sum(a, b, c, d);
					if(max<holder){
						max = holder;
						PY = y;
						PX = x;
						
					}
				}
			}
		}
		
		
		
		
		int largest = 0;
		
		for(int x = 0;x<size.size();x++){
			if(size.get(x)>largest) largest = size.get(x);
		}
		
		out.println(size.size());
		out.println(largest);
		out.println(max);
		
		int x, y;
		
		if(PX%2==0) x = (PX)/2;
		else x = (PX+1)/2;
		
		if(path[PY+1][PX]!=1){
			
			if(PY%2==0) y = (PY+2)/2;
			else y = (PY+3)/2;
			
			out.println(y+" "+x+" "+ "N");
		}
		else{
			if(PY%2==0) y = (PY)/2;
			else y = (PY+1)/2;			
			
			out.println(y+" "+x+" "+ "E");
		}
		
		
		
		out.close();
		System.exit(0);
	}
	static int sum(int a, int b, int c, int d){

		int max1 = Math.max(a,b);
		int max2 = Math.max(c, d);
		if(max1>max2) return max1+Math.max(max2, Math.min(a,b));
		else		  return max2+Math.max(max1, Math.min(c,d));
		
	}
	
	
	static void print(int[][] field){
		for(int y = 0; y<height;y++){
			for(int x = 0; x<width;x++){
				if(field[y][x]==1) System.out.print("#");
				else if(field[y][x]==2) System.out.print('|');
				else System.out.print(" ");
			}
			System.out.println();
		}
	}
	
	static void fill(int y, int x, boolean pass){
		
		if(y<0||x<0||y>=height||x>=width) return;
		if(path[y][x]!=0) return;
		
		path[y][x] = marker;
		if(pass) counter++;
		pass = false;
		if(field[y][x] == 2) pass = true;

		fill(y+1, x, pass);
		fill(y-1, x, pass);
		fill(y, x+1, pass);
		fill(y, x-1, pass);
		
		return;
		
	}
	
}