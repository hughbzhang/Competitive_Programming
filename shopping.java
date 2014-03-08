package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: shopping
*/
import java.io.*;
import java.util.*;

public class shopping {
	
	static int options;
	static int[][] path;
	static long[][][][][] dp;
	static int[][] items;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("shopping.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shopping.out")));
          
     options = Integer.parseInt(f.readLine());
     path = new int[options][12];
    
     for(int y = 0; y<options;y++){
	     StringTokenizer st = new StringTokenizer(f.readLine());
	     path[y][0] = Integer.parseInt(st.nextToken());
    	 for(int x = 1; x<=2*path[y][0];x++){
	    	 path[y][x] = Integer.parseInt(st.nextToken());
	     }
    	 path[y][2*path[y][0]+1] = Integer.parseInt(st.nextToken());
     }
     int want = Integer.parseInt(f.readLine());
     items = new int[want][3];
     for(int y = 0;y<want;y++){
	     StringTokenizer st = new StringTokenizer(f.readLine());
    	 items[y][0] = Integer.parseInt(st.nextToken());
    	 items[y][1] = Integer.parseInt(st.nextToken());
    	 items[y][2] = Integer.parseInt(st.nextToken());
     }
     dp = new long[6][6][6][6][6];
     
     for(int y = 0;y<path.length;y++){
		  int width = path[y][0];
		  for(int x = 1;x<=width;x++){
			  if(path[y][2*x-1]==items[0][0]) path[y][2*x-1] = 0;
			  else if(path[y][2*x-1]==items[1][0]) path[y][2*x-1] = 1;
			  else if(path[y][2*x-1]==items[2][0]) path[y][2*x-1] = 2;
			  else if(path[y][2*x-1]==items[3][0]) path[y][2*x-1] = 3;
			  else if(path[y][2*x-1]==items[4][0]) path[y][2*x-1] = 4;
		  }
	  }
     int[] temp = new int[5];
     for(int x = 0;x<items.length;x++){
    	 temp[x] = items[x][1];
     }
     long answer = recurse(temp[0], temp[1], temp[2], temp[3], temp[4]);
     out.println(answer);
    // print();
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static void print(){
	  for(int y = 0;y<6;y++){
		  for(int x = 0;x<6;x++){
			  System.out.print(dp[y][x][0][0][0]);
		  }
		  System.out.println();
	  }
  }
  
  static long recurse(int a, int b, int c, int d, int e){
	  if(a==0&&b==0&&c==0&&d==0&&e==0){
		  //System.out.println("zero");
		  return 0;
	  }
	  if(a<0||b<0||c<0||d<0||e<0) return Integer.MAX_VALUE;
	  if(dp[a][b][c][d][e]!=0) return dp[a][b][c][d][e];
	  
	  long min = Integer.MAX_VALUE;
	  long result;
	  
	  result = recurse(a-1, b, c, d, e)+items[0][2];
	  if(result<min) min = result;
	  if(items.length>1){
		  result = recurse(a, b-1, c, d, e) + items[1][2];
		  if(result<min) min = result;
		  if(items.length>2){
			  result = recurse(a, b, c-1, d, e) + items[2][2];
			  if(result<min) min = result;
			  if(items.length>3){
				  result = recurse(a, b, c, d-1, e) + items[3][2];
				  if(result<min) min = result;
				  if(items.length>4){
					  result = recurse(a, b, c, d, e-1) + items[4][2];
					  if(result<min) min = result;
				  }
			  }
		  }
	  }
	  for(int y = 0;y<path.length;y++){
		  int width = path[y][0];
		  int A = a;
		  int B = b;
		  int C = c;
		  int D = d;
		  int E = e;
		  for(int x = 1;x<=width;x++){
		
			  
			  if(path[y][2*x-1]==0) A-=path[y][2*x];
			  else if(path[y][2*x-1]==1) B-=path[y][2*x];
			  else if(path[y][2*x-1]==2) C-=path[y][2*x];
			  else if(path[y][2*x-1]==3) D-=path[y][2*x];
			  else if(path[y][2*x-1]==4) E-=path[y][2*x];
			  
		  }
		  //System.out.println(A+" "+B+" "+C+" "+D+" "+E);
		  result = recurse(A, B, C, D, E)+path[y][2*width+1];
		  if(result<min) min = result;
	  }
	  
	  return dp[a][b][c][d][e] = min;
	  
	  
  }
  
  
  static void print(int[][] path){
	  for(int y = 0;y<path.length;y++){
		  for(int x = 0;x<path[0].length;x++){
			  //if(path[y][x] == 0) break;
			  System.out.print(path[y][x]+" ");
		  }
		  System.out.println();
	  }
  }
}