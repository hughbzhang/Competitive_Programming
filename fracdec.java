package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: fracdec
 */
import java.util.*;
import java.io.*;

public class fracdec {
    static boolean term = false;
    static int start;
    static int end;
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new FileReader("fracdec.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fracdec.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int numer = Integer.parseInt(st.nextToken());
        int denom = Integer.parseInt(st.nextToken());
        int[] decimal = divide(numer%denom, denom);
        //int[][] mark = new int[10000][10];
        
       
       

        int line = Integer.toString(numer/denom).length()+1;
        
     
	
	
        if(term){
            out.print(numer/denom+".");
            for(int x = 0;x<decimal.length;x++){
                if(decimal[x]==-1) break;
				if(line==76){
					out.println();
					line = 0;
				}
                out.print(decimal[x]);
                line++;
            }
            out.println();
		  	out.close();
			System.exit(0);
        }
	
        System.out.println(start+" "+end+" "+term);

	
        out.print(numer/denom+".");
        for(int x = 0;x<start;x++){

			if(line==76){
				out.println();
				line = 0;
			}
            out.print(decimal[x]);
            line++;
		
        }
        if(decimal[start]==decimal[end]){
	        out.print('(');
	        line++;
	        
	        for(int x = start;x<end;x++){
	            if(line==76){
	            	out.println();
	            	line = 0;
	            }
	            out.print(decimal[x]);
	            line++;
	        }
	        if(line==76){
	        	out.println();
	        	line = 0;
			}
	        out.println(')');
	        out.close();
	        System.exit(0);
	    }
        else{
        	out.print(decimal[start]);
        	line++;
        	if(line==76){
	            	out.println();
	            	line = 0;
	         }
        	out.print('(');
        	line++;
        	 for(int x = start+1;x<=end;x++){
 	            if(line==76){
 	            	out.println();
 	            	line = 0;
 	            }
 	            out.print(decimal[x]);
 	            line++;
 	        }
 	        if(line==76){
 	        	out.println();
 	        	line = 0;
 			}
 	        out.println(')');
 	        out.close();
 	        System.exit(0);
        }
    }

    
    
    static int[] divide(int numer, int denom){

        int[] quotient = new int[100000];
        boolean[] remain = new boolean[100000];
        int[] index = new int[100000];
        int div = 10*numer;
        int counter = 0;
        while(counter<100000){
            
            quotient[counter] = div/denom;
            div %= denom;
            if(div==0){
                quotient[counter+1]=-1;
                term = true;
                break;
            }
            
            if(remain[div]==false){
            	remain[div]=true;
            	index[div]=counter;
            }
            else if(remain[div]){
            	start = index[div];
            	end = counter;
            	break;
            }
            div*=10;
            counter++;
        }
        return quotient;
    }
    static void print(int[] quotient){
        System.out.print("0.");
        for(int x = 0;x<100000;x++){
            if(quotient[x]==-1) break;
            System.out.print(quotient[x]);
        }
        
        
    }
    
}

