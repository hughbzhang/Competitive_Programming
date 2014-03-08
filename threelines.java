package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: barn1
*/
import java.io.*;
import java.util.*;

public class threelines {
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("3lines.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("3lines.out")));
    int number = Integer.parseInt(f.readLine());
    int Opoints[][] = new int[number][2]; //point number x, then y. ORIGINAL
    ArrayList<Integer> NpointsX = new ArrayList<Integer>();
    ArrayList<Integer> NpointsY = new ArrayList<Integer>();
    ArrayList<Integer> lines = new ArrayList<Integer>();
    int MpointX, MpointY, temp;
    for(int x  = 0; x<number;x++){
    	StringTokenizer st = new StringTokenizer(f.readLine());
    	Opoints[x][0] = Integer.parseInt(st.nextToken());
    	Opoints[x][1] = Integer.parseInt(st.nextToken());
    
    }
    MpointX = Opoints[0][0];
    MpointY = Opoints[0][1];
    
    for(int x = 0;x<number;x++){
    	if(Opoints[x][0] != MpointX){//vertical line
    		NpointsX.add(Opoints[x][0]);
    		NpointsY.add(Opoints[x][1]);
    	}
    }
    for(int x = 0;x<NpointsX.size();x++){
    	temp = NpointsX.get(x);
    	if(lines.contains(temp)==false){
    		lines.add(temp);
    	}
    }
    if(lines.size()<3){
    	out.println(1);
        out.close();
        System.exit(0);
    }
    lines.clear();
    

    for(int x = 0;x<NpointsY.size();x++){
    	temp = NpointsY.get(x);
    	if(lines.contains(temp)==false){
    		lines.add(temp);
    	}
    }
    if(lines.size()<3){
    	out.println(1);
        out.close();
        System.exit(0);
    }
    lines.clear();
    NpointsX.clear();
    NpointsY.clear();
    
    
    
    
    
    for(int x = 0;x<number;x++){
    	if(Opoints[x][1] != MpointY){//vertical line
    		NpointsX.add(Opoints[x][0]);
    		NpointsY.add(Opoints[x][1]);
    	}
    }
    for(int x = 0;x<NpointsX.size();x++){
    	temp = NpointsX.get(x);
    	if(lines.contains(temp)==false){
    		lines.add(temp);
    	}
    }
    if(lines.size()<3){
    	out.println(1);
        out.close();
        System.exit(0);
    }
    lines.clear();
    

    for(int x = 0;x<NpointsY.size();x++){
    	temp = NpointsY.get(x);
    	if(lines.contains(temp)==false){
    		lines.add(temp);
    	}
    }
    if(lines.size()<3){
    	out.println(1);
        out.close();
        System.exit(0);
    }
    lines.clear();
    NpointsX.clear();
    NpointsY.clear();
    
    
    
    
    
    
    out.println(0);
    out.close();
    System.exit(0);                               // don't omit this!
  }
}
    