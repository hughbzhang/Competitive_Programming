package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: checker
*/
import java.io.*;

public class checker {
	
	static boolean[][] board;
	static int size;
	static int counter = 0;
	static int pointer = 0;
	static int[][] solutions;
	static boolean[] row;
	static boolean[] col;
	static boolean[] up;
	static boolean[] down;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("checker.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("checker.out")));
     
     size = Integer.parseInt(f.readLine());     
     board = new boolean[size][size];
     solutions = new int[3][size];
     row = new boolean[size];
     col = new boolean[size];
     up = new boolean[2*size-1];
     down = new boolean[2*size-1];
     place(0);
    
   
    for(int x = 0;x<solutions.length;x++){
    	
    	out.print(solutions[x][0]+1);
    	
    	for(int y = 1 ;y<size;y++){
    		out.print(" " + (solutions[x][y]+1));
    	}
    	out.println();
    }
     
    out.println(counter);
    out.close();                             
    System.exit(0);                            
  }
  
  static void print(){
	  for(int x = 0; x<size;x++){
		  for(int y = 0; y<size;y++){
			  if(board[x][y]) System.out.print(0+" ");
			  else System.out.print(1+" ");
		  }
		  System.out.println();
	  }
  }
  
  static void place(int index){
	  if(index == size){
		  counter++;
		  if(pointer<3){
			  for(int x = 0;x<size;x++){
				 for(int y = 0;y<size;y++){
					 if(board[x][y]){
						 solutions[pointer][x] = y; 
						 break;
					 }
				 }
				  
			  }
			  pointer++;
		  }
		  return;
	  }
	  
	  for(int x = 0;x<size;x++){
		  if(row[x]||col[index]||up[index+x]||down[size+index-x-1]) continue;
		  
		  board[index][x] = true;
		  row[x] = true;
		  col[index] = true;
		  up[index+x] = true;
		  down[size+index-x-1] = true;
		  
		  place(index+1);
		  
		  board[index][x] = false;
		  row[x] = false;
		  col[index] = false;
		  up[index+x] =false;
		  down[size+index-x-1] = false;
	 
	  }
	  
	  return;
	 
  }
  
  
  
  static boolean check(int index, int width){
	  for(int x = 0; x<size;x++){
		  if(board[index][x]) return false;
		  if(board[x][width]) return false;
	  }

	  int y = index-1;
	  int x = width-1;
	  
	  while(y>-1&&x>-1){
		  if(board[y][x]) 	 return false;
		  x--;
		  y--;
	  }
	  y = index+1;
	  x = width+1;
	  
	  while(y<size&&x<size){
		  
		  if(board[y][x]==true) return false;
		  x++;
		  y++;
	  }

	  y = index+1;
	  x = width-1;
	  
	  while(y<size&&x>-1){
		  
		  if(board[y][x]==true) return false;
		  x--;
		  y++;
	  }
	  

	  y = index-1;
	  x = width+1;
	  
	  while(y>-1&&x<size){
		  
		  if(board[y][x]==true) return false;
		  x++;
		  y--;
	  }
	  
	  return true;
  }

  static boolean slant(int index, int width){
	  

	  
	  int y = index-1;
	  int x = width-1;
	  
	  while(y>-1&&x>-1){
		  if(board[y][x]) 	 return false;
		  x--;
		  y--;
	  }
	  y = index+1;
	  x = width+1;
	  
	  while(y<size&&x<size){
		  
		  if(board[y][x]==true) return false;
		  x++;
		  y++;
	  }

	  y = index+1;
	  x = width-1;
	  
	  while(y<size&&x>-1){
		  
		  if(board[y][x]==true) return false;
		  x--;
		  y++;
	  }
	  

	  y = index-1;
	  x = width+1;
	  
	  while(y>-1&&x<size){
		  
		  if(board[y][x]==true) return false;
		  x++;
		  y--;
	  }
	  
	
		return true;  
		  
	 
	  }
  
}
  
  
  
/*
 * int lowy = index-1;
	  int lowx = width-1;
	  int highy = index+1;
	  int highx = width+1;
	  boolean first = true;
	  boolean second = true;
	  boolean third = true;
	  boolean fourth = true;
	  
	  
	  while(first||second||third||fourth){
		  
		  first = lowy>-1&&lowx>-1;
		  second = highy<size&&highx<size;
		  third = lowy>-1&&highx<size;
		  fourth = highy<size&&lowx>-1;
		  
		  
		  if(first&&board[lowy][lowx]) return false;
		  if(second&&board[highy][highx]) return false;
		  if(third&&board[lowy][highx]) return false;
		  if(fourth&&board[highy][lowx]) return false;		  
		  
		  lowx--;
		  lowy--;
		  highx++;
		  highy++;
	  }
 */


  
  /*
  
  
  int y = index-1;
  int x = width-1;
  
  while(y>-1&&x>-1){
	  if(board[y][x]) 	 return false;
	  x--;
	  y--;
  }
  y = index+1;
  x = width+1;
  
  while(y<size&&x<size){
	  
	  if(board[y][x]==true) return false;
	  x++;
	  y++;
  }

  y = index+1;
  x = width-1;
  
  while(y<size&&x>-1){
	  
	  if(board[y][x]==true) return false;
	  x--;
	  y++;
  }
  

  y = index-1;
  x = width+1;
  
  while(y>-1&&x<size){
	  
	  if(board[y][x]==true) return false;
	  x++;
	  y--;
  }*/