package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: ttwo
*/
import java.io.*;

public class ttwo {
	static int[][] field = new int[10][10];
	static int CX = 0, CY = 0, FX =0 , FY=0, FD = 0, CD = 0;//0N 1E 2S 3W
    
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("ttwo.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ttwo.out")));

     
 	 int obs = 0;
     for(int y = 0;y<10;y++){
    	 String temp = f.readLine();
    	 for(int x = 0;x<10;x++){
    		 char key = temp.charAt(x);
    		 if(key=='*'){
    			 field[y][x]=1;
    			 obs++;
    		 }
    		 else if(key=='F'){
    			 field[y][x] = 5;
    			 FY=y;
    			 FX=x;
    		 }
    		 else if(key=='C'){
    			 CX = x;
    			 CY = y;
    			 field[y][x] = 7;
    		 }
    		 else field[y][x] = 0;
    		 
    	 }
     }
     int total = (int) Math.pow(4*(100-obs),2);
     int counter = 0;
     while(true){
    	 counter++;
    	 if(counter>total){
    		 counter = 0;
    		 break;
    	 }
    	 move();
    	 if(CX==FX&&CY==FY) break;
    	
    	
     }
     
     
     
    out.println(counter);
     
    out.close();                             
    System.exit(0);        
    
    
    
    
  }
  static void move(){
	 switch(FD){
 	 case 0:
 		 if(FY==0||field[FY-1][FX]==1){
 			 FD++;
 			 if(FD==4) FD=0;
 		 }
 		 else FY--;
 		 break;
 	 
 	 case 1:
 		 if(FX==9||field[FY][FX+1]==1){
 			 FD++;
 			 if(FD==4) FD=0;
 		 }
 		 else FX++;
 		 break;
 	 
  	 case 2:
 		 if(FY==9||field[FY+1][FX]==1){
 			 FD++;
 			 if(FD==4) FD=0;
 		 }
 		 else FY++;
 		 break;
 	 
	 case 3:
 		 if(FX==0||field[FY][FX-1]==1){
 			 FD++;
 			 if(FD==4) FD=0;
 		 }
 		 else FX--;
 		 break;
		
 	 default: break;
 	 }
	 
	 switch(CD){
 	 case 0:
 		 if(CY==0||field[CY-1][CX]==1){
 			 CD++;
 			 if(CD==4) CD=0;
 		 }
 		 else CY--;
 		 break;
 	 
 	 case 1:
 		 if(CX==9||field[CY][CX+1]==1){
 			 CD++;
 			 if(CD==4) CD=0;
 		 }
 		 else CX++;
 		 break;
 	 
  	 case 2:
 		 if(CY==9||field[CY+1][CX]==1){
 			 CD++;
 			 if(CD==4) CD=0;
 		 }
 		 else CY++;
 		 break;
 	 
		 case 3:
 		 if(CX==0||field[CY][CX-1]==1){
 			 CD++;
 			 if(CD==4) CD=0;
 		 }
 		 else CX--;
 		 break;
		
 	 default: break;
 	 }
  }
  
  static void print(int[][]field){
	  for(int y = 0;y<10;y++){
		  for(int x = 0;x<10;x++){
			  System.out.print(field[y][x]);
		  }
		  System.out.println();
	  }
  }
}