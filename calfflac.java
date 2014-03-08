package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: calfflac
*/
import java.io.*;
import java.util.*;


public class calfflac {

	ArrayList<Integer> index = new ArrayList<Integer>();
	int begin;
	int stop;
	int record;
	String modified;
	int temprec;
	
	

		
		
		
	
	
public String remove(String initial/*, ArrayList<Integer> indexs*/){
	
	
	StringBuffer change = new StringBuffer();
	char letter;
int x;
int counter = 0;
	for(x = 0; x<initial.length();x++){
    counter++;
		//int counter = -1;
		    	//go = false;
		    	/*for(int y = 97;y<123;y++){
		    	if((int)initial.charAt(x)==y) {
		    		//go = true;
		    		change+=initial.charAt(x);
		    	}
		    	}*/
			  
			   letter=initial.charAt(x);
				if(letter>='a'&&letter<='z'){
					
				    
					change.append(letter);
					
					index.add(x);
					
				}
				
		    	/*if(go==false){
		    	garbage+=initial.charAt(x);
		    	
		    	}*/
		   
	}
System.out.println(counter);
String last =change.toString(); 

return last;
	
}
	public calfflac() throws IOException{
 /*private static boolean isMatch(int center, int offset, int length, String source) {//center={0, LEN-1}, offset={1, LEN/2-1}	  
	  if(center<offset || (center+offset)>=length) return false;
	  return source.charAt(center-offset)!= source.charAt(center+offset);
  }*/
  
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("calfflac.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("calfflac.out")));                               // close the output file
    //ArrayList<String> file = new ArrayList<String>();
    
    String original = f.readLine()+"\n";
    //file.add(original);
    String temp = f.readLine();
   
    //boolean go = true;
    String printable = "";
    while(temp!=null){//populate string from file
    	original += temp;
    	original += "\n";
    	//modified +=temp;
    	temp = f.readLine();
    }

    String lowercase = original.toLowerCase();
   // String modified ="";
    


    
    modified = remove(lowercase);
   
    final int length = modified.length();
    //char c;
    //int end;
    
 //   int counterBuf=0/*, offset*/;
    /*
    for (int x = 1; x<length; x++) {
    	
    	offset = 1;
    	while(isMatch(x, offset++, length, modified));    	
    	if(offset>counterBuf) counterBuf=offset;
    }
    
    record = counterBuf*2+1;
    
     */
    
     	
 
    
    
   
    
    
    for(int x = 1;x<length-1;x++){
    	if(modified.charAt(x-1)==modified.charAt(x+1)) find(x-2,x+2);
    	if(modified.charAt(x)==modified.charAt(x-1)) find(x-2,x+1);
    	//System.out.println(record);
        
    }
	//System.out.println(record);

    
    printable = original.substring(index.get(begin), index.get(stop)+1);
    
    
    //System.out.println(lowercase.length());
    out.println(record);
    out.println(printable);
    out.close();
    //System.exit(0);                               // don't omit this!

	}
	
	public void find(int a, int b){
		if(a>-1&&b<modified.length()&&modified.charAt(a)==modified.charAt(b)) find(a-1,b+1);
		else{
			
			temprec = b-a-1;
			if(record<temprec){
				record=temprec;
				begin = a+1;
				stop = b-1;
			}
			//record=Math.max(record,temprec);
			//System.out.println(record);
		}
	
	}

	public static void main (String [] args) throws IOException {
		long startTime = System.currentTimeMillis();
		new calfflac();
		long endTime = System.currentTimeMillis();
		System.out.println("Total elapsed time in execution of method callMethod() is :"+ (endTime-startTime));
		System.exit(0);
	
	}
}
    