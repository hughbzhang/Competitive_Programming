package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: butter
*/
import java.io.*;
import java.util.*;

public class oldButter {
	
	static int[] dist;
    static int [] list;
    static int start;
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("butter.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("butter.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     
     int cows = Integer.parseInt(st.nextToken());
     int pastures = Integer.parseInt(st.nextToken());
     int paths = Integer.parseInt(st.nextToken());
     int[] loc = new int[cows];
     int[][] adj = new int[pastures][pastures];
     int[][] edge = new int[pastures][pastures];
     dist = new int[pastures];
     list = new int[pastures];
     
     for(int y = 0;y<pastures;y++){
    	 for(int x = 0;x<pastures;x++){
        	 adj[y][x] = Integer.MAX_VALUE;
        	 edge[y][x] = -1;
         }
     }
     
     for(int x = 0;x<cows;x++){
    	 loc[x] = Integer.parseInt(f.readLine())-1;
     }
     
     for(int x = 0;x<paths;x++){
    	 st = new StringTokenizer(f.readLine());
    	 int a = Integer.parseInt(st.nextToken())-1;
    	 int b = Integer.parseInt(st.nextToken())-1;
    	 adj[a][b] = Integer.parseInt(st.nextToken());
    	 adj[b][a] = adj[a][b];
     }
     for(int x = 0;x<pastures;x++) adj[x][x] = 0;
     
     int counter = 0;
     
     for(int x = 0;x<pastures;x++){
    	 for(int a = 0;a<pastures;a++){
    		 if(adj[x][a]!=Integer.MAX_VALUE&&adj[x][a]!=0){
    			 edge[x][counter] = a;
    			 counter++;
    		 }
    	 }
    	 counter = 0;
     }
     /*for(int x = 0;x<pastures;x++){
    	 for(int a = 0;a<pastures;a++){
    		 System.out.print(edge[x][a]+" ");
    	 }
    	 System.out.println();
     }*/
     
     
     int least = Integer.MAX_VALUE;
     //Disjerta
     boolean[] visit = new boolean[pastures];
     
     int current;
     start = 1;
     
     
     
    top: for(int x = 0;x<pastures;x++){//each central pasture for the sugar cube
    	 
    	 for(int a = 0;a<pastures;a++){
    		 visit[a] = false;//clear visit log
    		 dist[a]  = Integer.MAX_VALUE;//clear dist log
    		 list[a] = a;
    	 }
    	 dist[x] = 0;// dist from start point
    	 start = 1;
    	 list[0] = x;
    	 list[x] = 0;
    	 //begin
    	 current = x;
    	 //System.out.println("new");
    	 while(true){
    		
    		 visit[current] = true;
	    	 for(int a = 0;a<pastures;a++){
	    		 int dest = edge[current][a];
	    		 if(dest==-1) break;
	    		 if(dist[current]+adj[current][dest]<dist[dest]){
	    			 dist[dest] = dist[current]+adj[current][dest];
	    			 change(dest);
	    		 }
	    		 
	    	 }
	    	 //for(int a = 0;a<list.length;a++) System.out.print(dist[list[a]]+" ");
	    	// System.out.println();
	    	 
	    	 if(start == pastures) break;
	    	 
	    	 
	    	 /*for(int b = pastures-1;b>start;b--){
    			 int a = b-start; 
    			 //System.out.println(a);
    			 if(a%2==0){
    				 int second = a/2-1+start;
    				 if(dist[list[b]]<dist[list[second]]){
    					 int storage = list[b];
    					 list[b] = list[second];
    					 list[second] = storage;
    		
    				 }
    			 }
    			 else{
    				 int second = a/2+start;
    				 //System.out.println(b+" "+second);
    				 if(dist[list[b]]<dist[list[second]]){
    					 
    					 int storage = list[b];
    					 list[b] = list[second];
    					 list[second] = storage;
    				 }
    			 }
    		 }*/
	    	 
	    	 current = list[start];
	    	 start++;
	    	 
    	 }
    	 int temp = 0;
    	 for(int b = 0; b<cows;b++){
    		 temp+=dist[loc[b]];
    		 if(dist[loc[b]]==Integer.MAX_VALUE) continue top;
    	 }
    	 
    	 if(temp<least){
    		 least = temp;
    	 }
    	 
     }
    
     out.println(least);
     
     
     
     
    out.close();                             
    System.exit(0);                            
  }
  static void change(int dest){
	  int index = -1;
	  
	  for(int x = 0;x<list.length;x++){
		  if(list[x]==dest) index = x;
	  }
	  
	  while(index>start){
		  //System.out.println("stuck");
		  
//		  
		  int a = index-start;
		  if(a%2==0){
			 int second = a/2-1+start;
			 if(dist[list[index]]<dist[list[second]]){
				 int storage = list[index];
				 list[index] = list[second];
				 list[second] = storage;
				 index = second;
				 //System.out.println(index+" "+second);
				 continue;
			 }
		  }
		  else{
			 int second = a/2+start;
			 //System.out.println(b+" "+second);
			 if(dist[list[index]]<dist[list[second]]){
				 
				 int storage = list[index];
				 list[index] = list[second];
				 list[second] = storage;
				 index = second;
				 //System.out.println(index+" "+second);
				 continue;
			 }
		 }
	  	 break;
		  
	  }
	  
	  
	  
  }
}