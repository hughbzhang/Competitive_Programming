package Contest;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;

public class poker {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("poker.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("poker.out")));
     int total = Integer.parseInt(f.readLine())+1;
     int[] number = new int[total];
     long count = 0;
     
     number[0] = 0;
     for(int x = 1;x<total;x++){
    	 number[x] = Integer.parseInt(f.readLine());
    	 //System.out.println(number[x]);
     }
     for(int x = 1;x<total;x++){
    	 if(number[x]>number[x-1]){
    		 count+=(number[x]-number[x-1]);
    	 }
     }
     
     out.println(count);
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
}