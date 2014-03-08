package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: agrinet
*/
import java.io.*;
import java.util.*;

public class agrinet {
	static int[] dist;
	static boolean tree[];
	static int[][] adj;
	static int farms;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("agrinet.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("agrinet.out")));
     StringTokenizer st;
     farms = Integer.parseInt(f.readLine());
     adj = new int[farms][farms];
     dist = new int[farms];
     tree = new boolean[farms];
     
     int length = 0;
     for(int x = 0;x<farms;x++) dist[x]=Integer.MAX_VALUE;
     StringBuffer HOLDER = new StringBuffer("");
     String temp = f.readLine();
     while(temp!=null){
    	 HOLDER.append(temp);
    	 HOLDER.append(" ");
    	 temp=f.readLine();
     }
     System.out.println(HOLDER);
     st = new StringTokenizer(HOLDER.toString());
     for(int y = 0;y<farms;y++){
    	  for(int x = 0;x<farms;x++){
    		 adj[y][x]=Integer.parseInt(st.nextToken());
    	 }
     }
     for(int x = 0;x<farms;x++){
    	 dist[x]=adj[0][x];
     }
     tree[0] = true;
     
     while(true){
    	 int next = find();
    	 if(next==-1) break;
    	 tree[next] = true;
    	 length+=dist[next];
    	 for(int x = 0;x<farms;x++){
        	 if(dist[x]>adj[next][x]) dist[x]=adj[next][x];
         }
    	 
    	 
    	 
     }
     
     out.println(length);
     
    out.close();                             
    System.exit(0);                            
  }
  static int find(){
	  int max = Integer.MAX_VALUE;
	  int index = -1;
	  
	  for(int a = 0;a<dist.length;a++){
		  if(tree[a]==false&&max>dist[a]){
			  max = dist[a];
			  index=a;
		  }
	  }
	  return index;
	  
  }
}