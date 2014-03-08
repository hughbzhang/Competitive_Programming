package Contest;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class painting {
	
	static rect[] points;
	static int number;
	
	static class rect{
		int a;
		int b;
		int c;
		int d;
		
		rect(int x, int y, int z, int w){
			a = x;
			b = y;
			c = z;
			d = w;
		}
	}
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("painting.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("painting.out")));
     number = Integer.parseInt(f.readLine());
     points = new rect[number];//number down xy topx topy right
     boolean[] lap = new boolean[number];
     
     for(int x = 0;x<number;x++){
    	 StringTokenizer st = new StringTokenizer(f.readLine());
    	 int a = Integer.parseInt(st.nextToken());
    	 int b = Integer.parseInt(st.nextToken());
    	 int c = Integer.parseInt(st.nextToken());
    	 int d = Integer.parseInt(st.nextToken());
    	 points[x] = new rect(a, b, c, d);
     }
     final Comparator<rect> mine = new Comparator<rect>(){
			public int compare(rect one, rect two){
				if(one.a<two.a) return -1;
				if(one.a>two.a) return 1;
				else return 0;
			}
		};
     Arrays.sort(points, mine);
     
     
     for(int y = 0;y<number;y++){
    	 if(lap[y]) continue;
    	 int X = points[y].a;
    	 int Y = points[y].b;
    	 int max = points[y].c;
    	 int maxY = points[y].d;
    	 
    	 for(int x = y+1;x<number;x++){
    		 if(points[x].c<=X) continue;//end before you start
    		 if(points[x].a>=max) break;//start after you end
    		 if(X<=points[x].a&&max>=points[x].c&&Y<=points[x].b&&maxY>=points[x].d){
    			 lap[x] = true;
    			 
    		 }
    		 else if(X>=points[x].a&&max<=points[x].c&&Y>=points[x].b&&maxY<=points[x].d){
    			 lap[y] = true;
    			 break;
    		 }
    	 }
     }
     
    int count = 0;
    for(int x = 0;x<number;x++){
    	if(lap[x]==false) count++;
    }
    out.println(count);
     
    f.close(); 
    out.close();                             
    
    System.exit(0);                            
  }
  
  
  
  static void print(){
	  for(int y = 0;y<number;y++){
	    	 for(int x = 0;x<4;x++){
	    		 //System.out.print(points[y][x]+" ");
	    	 }
	    	 System.out.println();
	     }
  }
}