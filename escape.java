package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: escape
*/
import java.io.*;
import java.util.*;

public class escape {

	public static int greatest = 0;
	public static int total = 0;
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("escape.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("escape.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
   // StringTokenizer st = new StringTokenizer(f.readLine());
 // close the output file
    int number = Integer.parseInt(f.readLine());
    ArrayList<Integer> rest = new ArrayList<Integer>();
    for(int x = 0;x<number;x++){
    	String temp = f.readLine();
    	if(temp!=null){
    	rest.add(Integer.parseInt(temp));
    	//System.out.println(rest.get(x));
    }
    }
    /*for(int x = number;x<20;x++){
    	rest.add(0);
   //most(0, rest, 0);
    for(int a = 0; a<20;a++){
    	
    }*/
    most(0,rest,0, -1);
    
    out.println(greatest);
    out.close();
    System.exit(0);                               // don't omit this!
  }
  

	private static void most(int sum, ArrayList<Integer> rest, int record, int a){
		
		
		for(int x = 0; x<rest.size();x++){
			if(x>a){
			//if(sum==527) System.out.println("GO");
			if(carryfinder(sum, rest.get(x))){
			
				record++;
				//System.out.println(record + " " + sum);
			a=x;
				most(sum+rest.get(x),rest, record, a);
			}
			
			
				if(record>greatest){
					greatest = record;
					total = sum;
					//System.out.println(greatest + " " + total);
				}
				else record--;
					//System.out.println(greatest);
				
			}
		}
		
		
		//return greatest;
	}
  private static boolean carryfinder(int sum, int next){
	  
	  if(sum<next){
		  int temp = next;
		  next = sum;
		  sum = temp;
	  }
	  
	  String second = Integer.toString(next);
	  String SUM = Integer.toString(sum);
	 
	  String newsum = SUM.substring(SUM.length()-second.length());
	  
	  for(int x = 0; x<newsum.length()-1;x++){
		  
		  int a = Integer.parseInt(newsum.substring(x, x+1));
		  int b = Integer.parseInt(second.substring(x, x+1));
		 // System.out.println("false");
		  if(a+b>9) return false;
	  }
	  if(Integer.parseInt(second.substring(newsum.length()-1))+Integer.parseInt(newsum.substring(newsum.length()-1))>9){
		  //System.out.println("false");
		  return false;
	  }
	  //System.out.println("true");
	  return true;
  }
  
}