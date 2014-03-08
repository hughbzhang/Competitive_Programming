package Solved;


/*
ID: bigfish2
LANG: JAVA
TASK: packrec
*/

import java.awt.*;
import java.io.*;
import java.util.*;

public class packrec{
	
	
	
	
	
	
	
	public static void main (String[]args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("packrec.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("packrec.out")));
		
		
		
		int temp, holder;
		int height = 0;
		int width = 0;
		Rectangle[] Rect = new Rectangle[4];
		Rectangle[] filler = new Rectangle[4];
		ArrayList<Point> done = new ArrayList<Point>();
		ArrayList<Point> pos = new ArrayList<Point>();
		
		done.ensureCapacity(100);
		int area = Integer.MAX_VALUE;
		
		
		for(int x = 0; x<4;x++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			temp = Integer.parseInt(st.nextToken());
			holder = Integer.parseInt(st.nextToken());
			Rect[x] = new Rectangle(temp, holder);
		}
		
		StringBuffer template = new StringBuffer("");
		
		for(int x = 0; x<16;x++){
			template = new StringBuffer(Integer.toBinaryString(x));
			while(template.length()<4){
				template.insert(0, 0);
			}
			//System.out.println("OK");
			for(int a = 0; a<4;a++){
				if(template.charAt(a)=='0') filler[a]=Rect[a];
				else filler [a] = swap(Rect[a]);
			}
			//print(filler);
			pos = check(filler);
			
			height = pos.get(0).y;
			width = pos.get(0).x;
			
			if(height*width<area){
				
				area = height*width;
				done.clear();
				
				for(int y = 0; y<pos.size();y++){
					done.add(new Point(pos.get(y).x, pos.get(y).y));
				}
			
				
				//print(filler);
			}
			if(height*width==area){
				for(int y = 0; y<pos.size();y++){
					done.add(new Point(pos.get(y).x, pos.get(y).y));
				}
			}
		}
		
		/*
		Rectangle[] test = new Rectangle[4];
		test[0] = new Rectangle(2,1);
		test[1] = new Rectangle(2,3);
		test[2] = new Rectangle(3,4);
		test[3] = new Rectangle(5,4);
		
		pos = check(test);
		System.out.println();
		*/
		
		
		ArrayList<Point> close = new ArrayList<Point>();
		
		for(int x = 0;x<done.size();x++){
			if(close.contains(done.get(x))==false&&close.contains(new Point(done.get(x).y, done.get(x).x))==false) close.add(done.get(x));
		}
		
		
		Point[] finished = new Point[close.size()];
		
		for(int x = 0;x<finished.length;x++){
			if(close.get(x).x<close.get(x).y) finished[x]=close.get(x);
			else finished [x] = new Point(close.get(x).y, close.get(x).x);
		}
		
		
		boolean go = true;
		Point storage;
		while(go){
	  	   go = false;
	  	   for(int x = 1;x<finished.length;x++){
	  		   if(finished[x].x<finished[x-1].x){
	  			   storage = finished[x];
	  			 finished[x] = finished[x-1];
	  			 finished[x-1]=storage;
	  			   go = true;
	  		   }
	  	   }
	     }
		
		
		out.println(area);
		for(int x = 0; x<finished.length;x++){
			out.println(finished[x].x+" "+ finished[x].y);
		}
		out.close();
		System.exit(0);
		
	}
	
	static void print(Rectangle[] printer){
		for(int x = 0 ;x<printer.length;x++){
			System.out.println(printer[x].width+" "+ printer[x].height);
		}
		System.out.println();
	}
	
	static Rectangle swap(Rectangle rect){
		
		return new Rectangle(rect.height, rect.width);
		
	}
	
	
	static ArrayList<Point> check(Rectangle[] rect){
		
		//variables:
		
		int width = 0;
		int height = 0;
		ArrayList<Rectangle> pos = new ArrayList<Rectangle>(); //
		
		//System.out.println("Case 1\n");
		//Case 1: All rectangles are next to each other
		for(int x = 0;x<rect.length;x++){
			width += rect[x].width;
		}
		height = max(rect[0].height, rect[1].height, rect[2].height, rect[3].height);

		//System.out.println(width+" "+height);
		pos.add(new Rectangle(width, height));
		
		width = 0;
		height = 0;
		
		//Case 2: One Rectangle on the bottom, while all others are on top.
		//System.out.println("Case 2\n");
		
		for(int x = 0; x<4;x++){
			int sum = 0;
			int max = 0;
			
			
			for(int y = 0; y<4;y++){
				if(y!=x){
					sum+=rect[y].width;
					if(rect[y].height>max) max = rect[y].height;
				}
			}
			
			width = max(sum, rect[x].width);
			height = rect[x].height+max;

			//System.out.println(width+" "+height);
			pos.add(new Rectangle(width, height));
		}
		
		width = 0;
		height = 0;
		//Case 3: One Rectangle to the side. One Rectangle on the bottom. Two on top of the lower one.
		//System.out.println("Case 3\n");
		
		
		for(int y = 0;y<4;y++){//x is to the bottom y is on the side
			for(int x = 0;x<4;x++){
				if(x==y) continue;
				
				int sum = 0;
				int max = 0;
				for(int a = 0; a<4;a++){
					if(a!=x&&a!=y){
						sum+=rect[a].width;
						if(rect[a].height>max) max = rect[a].height;
					}
				}
				
				width = max(sum, rect[x].width)+rect[y].width;
				height = max(rect[x].height + max, rect[y].height);

			//	System.out.println(width+" "+height);
				pos.add(new Rectangle(width, height));
				
			}
		}
		height = 0;
		width = 0;
		
		//System.out.println("Case 45\n");
		
		//Case 4/5: Three on bottom. One on top
		for(int x = 0; x<4;x++){//x is on top
			
			int sum = 0;
			int min = Integer.MAX_VALUE;
			int max = 0;
			
			for(int a = 0; a<4;a++){
				if(a!=x){
					sum+=rect[a].width;
					if(rect[a].width>=rect[x].width&&rect[a].height<min) min = rect[a].height;
					if(rect[a].height>max) max = rect[a].height;
				}
			}
			if(min==Integer.MAX_VALUE) min = max;
			
			width = max(sum, rect[x].width);
			height = max(rect[x].height+min, max);
		//	System.out.println(width+" "+height);
			
			pos.add(new Rectangle(width, height));
		}
		
			
		height = 0;
		width = 0;
		
	//	System.out.println("Case 6\n");
		
		//Case 6: Two on top and two on bot.
		
		for(int y = 0; y<4;y++){
			for(int x = 0; x<4;x++){
				if(x==y) continue;
				
				int sum = 0;
				int max = 0;
				int one = -1;
				int two = -1;
				boolean first = true;
				
				for(int a = 0; a<4; a++){
					if(a!=y&&a!=x){
						sum += rect[a].width;
						if(rect[a].height>max) max = rect[a].height;
						
						
						if(first){
							one = a;
							first = false;
						}
						else if(first==false) two = a;
					}
				}
				if(sum>(rect[y].width+rect[x].width)) continue;

				
				int h1 = rect[y].height+rect[one].height;
				if(rect[y].height<rect[x].height&&rect[one].width>rect[y].width) h1 = Integer.MAX_VALUE;
				int h2 = rect[x].height+rect[two].height;
				if(rect[x].height<rect[y].height&&rect[two].width>rect[x].width) h2 = Integer.MAX_VALUE;
				int p1 = max(h1, h2);
				
				int h3 = rect[y].height+rect[two].height;
				if(rect[y].height<rect[x].height&&rect[two].width>rect[y].width) h3 = Integer.MAX_VALUE;
				int h4 = rect[x].height+rect[one].height;
				if(rect[x].height<rect[y].height&&rect[one].width>rect[x].width) h4 = Integer.MAX_VALUE;
				
				int p2 = max(h3, h4);
				
				height = Math.min(p1, p2);
				if(height==Integer.MAX_VALUE) continue;
				//height = max(rect[y].height, rect[x].height) + max;
				width = rect[y].width+rect[x].width;
		//		System.out.println(width+" "+height);
				
				pos.add(new Rectangle(width, height));
				
			}
		}
		
		
		
		
		
		return shorten(pos);
		
		
		
	}
	
	static ArrayList<Point> shorten(ArrayList<Rectangle> pos){
		
		int area = Integer.MAX_VALUE;
		int height = 0;
		int width = 0;
		ArrayList<Point> done = new ArrayList<Point>();
		
		for(int x = 0; x<pos.size();x++){
			
			height = pos.get(x).height;
			width = pos.get(x).width;
			if(height*width<area) area = height*width;
		}
		//System.out.println("Area = " + area);
		
		for(int x = 0; x<pos.size();x++){
			height = pos.get(x).height;
			width = pos.get(x).width;
			if(height*width==area) done.add(new Point(width, height));
		}
		
		//System.out.println(done.get(0).width+" "+done.get(0).height);
		//print((Rectangle[])done.toArray());
		return done;
	}
	
	
	static int max(int a, int b, int c, int d){
		return Math.max(Math.max(a, b), Math.max(c, d));
	}
	
	static int max(int a , int b, int c){
		return Math.max(Math.max(a, b), c);
	}
	static int max(int a, int b){
		return Math.max(a,b);
	}
	
	
	



}
	
