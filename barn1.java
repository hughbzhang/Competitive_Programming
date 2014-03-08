package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: barn1
*/
import java.io.*;
import java.util.*;

public class barn1 {
	
	private static int findHoles(boolean[] map){
		int temp = 0;  
		for(int x = 1;x<map.length;x++){
		    	//right = map[x];
		    	if(map[x]){
		    		temp++;
		    	
			    	if(map[x-1]){
			    		temp--;
			    	}
		    	}
		    }
		return temp;
	}
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("barn1.in"));
                                            // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));                               // close the output file
    //ArrayList<String> file = new ArrayList<String>();
    //f.readLine();
    StringTokenizer st = new StringTokenizer(f.readLine()); 
    int boardsM = Integer.parseInt(st.nextToken());
    int stallsM = Integer.parseInt(st.nextToken());
    int occupied = Integer.parseInt(st.nextToken());
    int total = 0;
    boolean[] map = new boolean[stallsM+1];
    int holder;
    int first = Integer.parseInt(f.readLine());
    map[first] = true;
    //int extra = occupied-boardsM;
    for(int x = 0;x<occupied-1;x++){
    	holder = Integer.parseInt(f.readLine());
    	map[holder] = true;
    	if(holder<first) first = holder;
    }
   
    int length = 0;
    int record = 201;
    int start = 0;
    int temp = findHoles(map);
    //boolean right = true;
    /*for(int x = 1;x<map.length;x++){
    	//right = map[x];
    	if(map[x]){
    		temp++;
    	
	    	if(map[x-1]){
	    		temp--;
	    	}
    	}
    }*/
    //System.out.println(temp);
    int extra = temp-boardsM;
   //System.out.println(findHoles(map));
    
    while(extra>0){
    	length = 0;
    	record = 201;
    	for(int x = first;x<map.length;x++){
    		
    		if(map[x]==false){
    			length++;
    		}
    		else{
    			if(record>length&&length>0){
    				record = length;    			
    				start = x-length;
    			}
    			length = 0;
    		}
    	}
    	//System.out.println(record + "r");
    	//System.out.println(start + "s");
    	for(int y = start;y<start+record;y++){
    		//if(map[y]!=true){
    			map[y] = true;
    			//total++;
    		//}
    		
    	}
    	//System.out.println(start);
    	extra--;
    	//System.out.println(findHoles(map));
   }
    for(int x = 1;x<map.length;x++){
    	if(map[x]==true) total++;
    }
   // for(int x = 1;x<map.length;x++){
    	//System.out.println(map[x]);
   // }
    //temp = findHoles(map);
    
    
    out.println(total);
    //out.println();
    out.close();
    System.exit(0);                               // don't omit this!
  }
}
    