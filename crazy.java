package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: crazy
*/
import java.io.*;
import java.awt.Point;
import java.util.*;

public class crazy {
	
	static int[][] field;
	
	static int counter = 0;
	static int rooms = 0;
	static int[][] fence;
	static int[][] slant;
	static int[][] cows;
	static int number;
	static int cowsLeft;
	static int Xbuffer;
	static int Ybuffer;
	
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("crazy.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crazy.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     number = Integer.parseInt(st.nextToken());
     cowsLeft = Integer.parseInt(st.nextToken());
     fence = new int[number][4];
     cows  = new int[cowsLeft][2];
     int maxX = 0;
     int maxY = 0;
     int minX = Integer.MAX_VALUE;
     int minY = Integer.MAX_VALUE;
     
     int max = 1;
    
     for(int x = 0;x<number;x++){
    	 st = new StringTokenizer(f.readLine());
    	 fence[x][0] = Integer.parseInt(st.nextToken());
    	 if(maxX<fence[x][0]) maxX = fence[x][0];
    	 if(minX>fence[x][0]) minX = fence[x][0];
    	 fence[x][1] = Integer.parseInt(st.nextToken());
    	 if(maxY<fence[x][1]) maxY = fence[x][1];
    	 if(minY>fence[x][1]) minY = fence[x][1];
    	 
    	 
    	 for(int a = 2;a<4;a++){
    		 fence[x][a] = Integer.parseInt(st.nextToken());
    	 }
     }
     
     for(int x = 0;x<cowsLeft;x++){
    	 st = new StringTokenizer(f.readLine());
    	 
    	 cows[x][0] = Integer.parseInt(st.nextToken());
    	 if(maxX<cows[x][0]) maxX = cows[x][0];
    	 if(minX>cows[x][0]) minX = cows[x][0];
    	 cows[x][1] = Integer.parseInt(st.nextToken());
    	 if(maxY<cows[x][1]) maxY = cows[x][1];
    	 if(minY>cows[x][1]) minY = cows[x][1];
    	 
     }
     
     Xbuffer = maxX-minX;
     Ybuffer = maxY-minY;
     field = new int[Ybuffer+1][Xbuffer+1];
     
     for(int x = 0;x<cowsLeft;x++){ 	 
    	 field[cows[x][1]-minY][cows[x][0]-minX] = 1;
     }
   
     for(int x = 0;x<number;x++){
    	 fence[x][0]-=minX;
    	 fence[x][1]-=minY;
    	 fence[x][2]-=minX;
    	 fence[x][3]-=minY;
     }
     
     for(int x = 0;x<number;x++){
    	 if(fence[x][0]==fence[x][2]){
    		 for(int y = fence[x][1];y<=fence[x][3];y++){
    			 field[y][fence[x][0]]=2;
    		 }
    		 for(int y = fence[x][3];y<=fence[x][1];y++){
    			 field[y][fence[x][0]]=2;
    		 }
    	 }
    	 else if(fence[x][1]==fence[x][3]){
    		 for(int a = fence[x][0];a<=fence[x][2];a++){
    			 field[fence[x][1]][a]=2;
    		 }
    		 for(int a = fence[x][2];a<=fence[x][0];a++){
    			 field[fence[x][1]][a]=2;
    		 }
    	 }
    	 
    	 
    	 
     }
     Point holder = empty();
     max = 0;
     while(holder!=null){
    	 counter = 0;
    	 fill(holder.x,holder.y);
    	 if(max<counter) max = counter;
    	 holder = empty();
    	 //System.out.println("h");
    	 
     }
     out.println(max-1);
     
     
    out.close();                             
    System.exit(0);                            
  }
  	static Point empty(){
  		for(int x = 0;x<Xbuffer;x++){
  			for(int y = 0; y<Ybuffer;y++){
  				if(field[y][x]==0||field[y][x]==1) return new Point(x, y);
  			}
  		}
  		return null;
  	}
  	
  
	static void fill(int x, int y){
		
		if(y<0||x<0||y>=Ybuffer||x>=Xbuffer) return;
		if(field[y][x]==2) return;
		if(field[y][x]==1) counter++;
		
		field[y][x] = 2;
		
		fill(y+1, x);
		fill(y-1, x);
		fill(y, x+1);
		fill(y, x-1);
		
		return;
		
	}
  
  
  
  
 /* static void findRooms(int x, int y, boolean past){
	  
	  if(check(x, y)){
		  rooms++;
		  return;
	  }
	  for(int a = 0;a<number;a++){
		    
			if(fence[a][0]==x&&fence[a][1]==y){
				
			}
			if(fence[a][3]==x&&fence[a][4]==y){	
				
			}
	  }
	  
  }
  static boolean check(int x, int y){
	  for(int a = 0;a<travel.length;a++){
		    
		if(travel[a][0]==-1) break;
		if(travel[a][0]==x&&travel[a][1]==y) return true;
		if(travel[a][1]==x&&travel[a][0]==y) return true;
	  }
		  
	  return false;
  }*/
  
  
}