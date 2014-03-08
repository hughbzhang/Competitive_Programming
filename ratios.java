package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: ratios
*/
import java.io.*;
import java.util.*;


public class ratios {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("ratios.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ratios.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     boolean change = false;
     int[] target = new int[3];
     int[] holder = new int[3];
     int sum = Integer.MAX_VALUE;
     int[] winner = new int[4];
     for(int x = 0;x<3;x++){
    	 target[x] = Integer.parseInt(st.nextToken());
     }
     int[][] feed = new int[3][3];
     for(int y = 0;y<3;y++){
    	 st = new StringTokenizer(f.readLine());
    	 for(int x = 0;x<3;x++){
    		 feed[y][x] = Integer.parseInt(st.nextToken());
    	 }
     }
     
     for(int a = 0;a<100;a++){
    	 for(int b = 0;b<100;b++){
    		 for(int c = 1;c<100;c++){
    			 if(a+b+c>=sum) break;
    			 holder[0] = a*feed[0][0]+b*feed[1][0]+c*feed[2][0];
    			 holder[1] = a*feed[0][1]+b*feed[1][1]+c*feed[2][1];
    			 holder[2] = a*feed[0][2]+b*feed[1][2]+c*feed[2][2];
    			 
    			 int value = 0;
    			 boolean initial = false;
    			 if(target[0]==0){
    				 if(holder[0]!=0) continue;
    			 }
    			 else{
    				if(holder[0]%target[0]!=0) continue;
    				else{
    					value = holder[0]/target[0];
    					initial = true;
    				}
    			 }
    			 if(target[1]==0){
    				 if(holder[1]!=0) continue;
    			 }
    			 else{
    				 if(holder[1]%target[1]!=0) continue;
    				 int temp = holder[1]/target[1];
 					
    				 if(initial==false){
    					value = temp;	
    					initial = true;
    				
    				 }
    				 else{
    					 if(value!=temp) continue;
    				 }
    			 }
    			 if(target[2]==0){
    				 if(holder[2]!=0) continue;
    			 }
    			 else{
    				 if(holder[2]%target[2]!=0) continue;
    				 int temp = holder[2]/target[2];
 					
    				 if(initial==false){
    					value = temp;	
    					initial = true;
    				
    				 }
    				 else{
    					 if(value!=temp) continue;
    				 }
    			 }
    			 
				 change = true;
				 winner[0] = a;
				 winner[1] = b;
				 winner[2] = c;
				 winner[3] = value;
				 sum = a+b+c;
				  
    		 }
    	 }
     }
     
     
    if(change) out.println(winner[0]+" "+winner[1]+" "+winner[2]+" "+winner[3]);
    else out.println("NONE");
    f.close();
    out.close();                             
    System.exit(0);                            
  }
}
