package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: friday
*/
import java.io.*;


class friday {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("friday.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    
    String length = f.readLine();
    int LENGTH = Integer.parseInt(length);
    int[] days = new int[] {0, 0, 0, 0, 0, 0, 0};
    int[] dist = new int[] {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    //int year = 0;
    int day = 2;
    int disti = 12;
    
    day = (day+disti-dist[0])%7;
    //days[day]++;
    for(int year = 1900; year<1900+LENGTH;year++){
    	if(year%4!=0||year ==1900||year==2100||year==2200||year==2300){
    	
    		dist[2] = 28;
    	}
    	else dist[2]=29;
    	
    	for(int x = 0; x<dist.length;x++){
    		day=(day+dist[x])%7;
    		days[day]++;
    	}
    	
    	
    }
    
    
    out.print(days[0]);
    
    for(int x =1; x<days.length-1;x++){
    
    
    out.print(" " + days[x]);
    }
    out.println(" " + days[days.length-1]);
    out.close();
    System.exit(0);                               // don't omit this!
  }
}