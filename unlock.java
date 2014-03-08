package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: grazing
*/
import java.io.*;
import java.util.*;

public class unlock {
	
	static int[][] field = new int[27][27]; //coodinate system.
	static int[][] origin = new int [27][27];
	static boolean go = false;
	
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("unlock.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("unlock.out")));
    StringTokenizer st = new StringTokenizer(f.readLine());
    
    int N1 = Integer.parseInt(st.nextToken());
    int N2 = Integer.parseInt(st.nextToken());
    int N3 = Integer.parseInt(st.nextToken());
    int x, y;
    //System.out.println(x + " " + y);
    
    for(int a = 0; a<N1;a++){
        StringTokenizer one = new StringTokenizer(f.readLine());
        x = Integer.parseInt(one.nextToken())+9;
        y = Integer.parseInt(one.nextToken())+9;
        field[x][y] = 1;
        origin[x][y] = 1;
    }
    for(int a = 0; a<N2;a++){
        StringTokenizer two = new StringTokenizer(f.readLine());
        x = Integer.parseInt(two.nextToken())+9;
        y = Integer.parseInt(two.nextToken())+9;
        field[x][y] = 2;
        origin[x][y] = 2;
    }
    for(int a = 0; a<N3;a++){
        StringTokenizer three = new StringTokenizer(f.readLine());
        x = Integer.parseInt(three.nextToken())+9;
        y = Integer.parseInt(three.nextToken())+9;
        field[x][y] = 3;
        origin[x][y] = 3;
    }
    boolean luck = true;
    boolean go1 = true;
    boolean go2 = true;
    boolean go3 = true;
    
    while(luck){
    	luck = false;
    if(go1&&fiddle(1,1,0,0)==false||fiddle(1,-1,0,0)==false||fiddle(1,0,1,0)==false||fiddle(1,0,-1,0)==false){
    	remove(1);
    	luck = true;
    	go1 = false;
    }
    if(go2&&fiddle(2,1,0,0)==false||fiddle(2,-1,0,0)==false||fiddle(2,0,1,0)==false||fiddle(2,0,-1,0)==false){
    	remove(2);
    	luck = true;
    	go2 = false;
    }
    if(go3&&fiddle(3,1,0,0)==false||fiddle(3,-1,0,0)==false||fiddle(3,0,1,0)==false||fiddle(3,0,-1,0)==false){
    	remove(3);
    	luck = true;
    	go3 = false;
    	//System.out.println("YAY");
    }
    }
    
    if(go1==false&&go2==false&&go3==false) out.println(1);
    else out.println(0);          
    out.close();                                 
    System.exit(0);                       
  }
  private static boolean checkmove(int ID, int xdir, int ydir){
	  for (int b = 7; b<20;b++){
		  for(int a = 7; a<20;a++){
			  if(field[a][b]==ID){
				 // if(ID==3&&xdir==1&&ydir==0) System.out.println("Go");
				  int x = a+xdir;
				  int y = b+ydir;
				  
				  if(x<0||x>26||y<0||y>26){
					  return false;
				  }

				  if(field[x][y]!=0&&field[x][y]!=ID) return false;

			  }
		  }
	  }

  return true;
  }

  
  
  
  
  
  private static boolean fiddle(int ID, int xdir, int ydir, int counter) throws IOException{
	  if(counter>1000){
		  PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("unlock.out")));
		  out.println(0);
		  out.close();
		  System.exit(0);
	  }
	 
	  if(checkmove(ID,xdir,ydir)){
		  
		  move(ID,xdir,ydir);
		  if(checktouch(ID)) return false;
		  System.out.println("GO");
		  if(fiddle(ID, 1, 0, ++counter)==false) return false;
		  if(fiddle(ID, -1, 0,++counter)==false) return false;
		  if(fiddle(ID, 0, 1,++counter)==false) return false;
		  if(fiddle(ID, 0, -1,++counter)==false) return false;  
		  
	  }
	  
	  return true;
  }
  
  
  
  
  
  
  private static boolean checktouch(int ID){
	  for (int b = 0; b<27; b++){
		  for(int a = 0; a<27; a++){
			  if(field[a][b]==ID){
				  if(a==27||a==0||b==27||b==0) return true;
			  }
		  }
	  }
	  return false;
  }
  private static void move(int ID, int xdir, int ydir){
	  for (int b = 9; b<18;b++){
		  for(int a = 9; a<18;a++){
			  if(field[a][b]==ID){
			  field[a][b] = 0;
			  field[a+xdir][b+ydir] = ID;
			  
			  
			  }
		  }
	  }
  }
    
  
  
  private static void remove(int ID){//UPSIDE DOWN VISUAL ON THE FIELD.
	  for (int y = 9; y<18;y++){
		  for(int x = 9; x<18;x++){
			  if(field[x][y]==ID) field[x][y] = 0;
		  }
		  //System.out.println();
	  }
  }
  
  
  
  private static void view(){//UPSIDE DOWN VISUAL ON THE FIELD.
	  for (int y = 9; y<18;y++){
		  for(int x = 9; x<18;x++){
			  System.out.print(field[x][y]+" ");
		  }
		  System.out.println();
	  }
  }



}