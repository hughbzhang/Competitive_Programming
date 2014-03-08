package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/

import java.io.*;
import java.util.*;

public class distant {
	
	public static int size;
	public static int same;
	public static int different;
	public static boolean [][] path;
	public static int [][] field;
	//public static int [][][][] lengths;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("distant.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("distant.out")));
     
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     int Tsize = Integer.parseInt(st.nextToken());
     int Tsame = Integer.parseInt(st.nextToken());
     int Tdifferent = Integer.parseInt(st.nextToken());
     String temp;
     
     size = Tsize;
     same = Tsame;
     different = Tdifferent;
     
     
     field = new int[size][size]; //00 01
     									  //10 11
     path = new boolean[size][size];
    // lengths = new int[20][20][20][20];
     
     for(int y = 0; y< size; y++){
    	 
    	 temp = f.readLine();
    	 
    	 for(int x = 0; x<size;x++){
    		 if( temp.charAt(x)=='(') field[y][x] = 0;
    		 else field[y][x] = 1;
    	 }
     }
    int max = 0;
    int holder = 0;
    //int startX = 0;
    //int startY = 0;
    //int endX = 0;
    //int endY = 0;
     
    for(int y = 0; y<size;y++){
    	for(int x = 0; x<size;x++){
    		for(int a = y+1; a<size;a++){
    			for(int b = x+1; b<size;b++){
    				holder = findpath(x, y, b, a, 0, -1);
    				if(holder>max&&holder!=Integer.MAX_VALUE){
    					max = holder;
    					//startX = x;
    					//startY = y;
    					//endX = b;
    					//endY = a;
    					
    				}
    			}
    		}
    	}
    }
    out.println(max);
     
    out.close();                             
    System.exit(0);                            
  }
  private static int findpath(int x, int y, int endX, int endY, int length, int place){
	  
	  
	  if(x<0||x>=size||y<0||y>=size) return -1; //out of bounds
	  if(path[y][x] == true) return -1; //already been there
	  //if(lengths[x][y][endX][endY]!=0) return lengths[x][y][endX][endY];
	  //if(lengths[endX][endY][x][y]!=0) return lengths[endX][endY][x][y];
	  
	  if(place!=-1){//add lengths
		  if(field[y][x]==place) length+=same;
		  else length +=different;
	  }
	  
	  if(x==endX&&y==endY) return length;//success statement
	  
	  path[y][x] = true; //state that your there
		
	  
	  if(field[y][x]==0) place = 0;//determine previous position
	  else place = 1;
	  
	  int record = Integer.MAX_VALUE;
	  int holder = 0;
	  
	  holder = findpath(x+1, y, endX, endY, length, place);
	  if(holder>-1&&holder<record) record = holder;
	  holder = findpath(x-1, y, endX, endY, length, place);
	  
	  if(holder>-1&&holder<record) record = holder;
	  holder = findpath(x, y+1, endX, endY, length, place);
	  if(holder>-1&&holder<record) record = holder;
	  holder = findpath(x, y-1, endX, endY, length, place);
	  if(holder>-1&&holder<record) record = holder;
	  
	  path[y][x] = false;
	  
	  //lengths[x][y][endX][endY]=record;
	  //lengths[endX][endY][x][y]=record;
	  
	  return record;
	  
	  
  }
    
  
  
  
  
  
  
  
  
  
  /*
  private static void print(boolean[][] paper){
	  
	  
	     for(int y = 0; y<size; y++){
	    	 for(int x = 0; x<size;x++){
	    		 System.out.print(paper[y][x]);
	    	 }
	    	 System.out.println();
	     }
}


  
  
  
  
  
  private static void print(int[][] paper){
	  
	  
	     for(int y = 0; y<size; y++){
	    	 for(int x = 0; x<size;x++){
	    		 System.out.print(paper[y][x]);
	    	 }
	    	 System.out.println();
	     }
  }*/
  
}