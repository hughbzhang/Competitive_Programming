package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: fracdec
 */
import java.util.*;
import java.io.*;

public class fracdecslow {
    static boolean term = false;
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new FileReader("fracdec.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fracdec.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int numer = Integer.parseInt(st.nextToken());
        int denom = Integer.parseInt(st.nextToken());
        int[] decimal = divide(numer%denom, denom);
        int[][] mark = new int[10000][10];
        int start = 0;
        int end = 0;
       
       

	int line = Integer.toString(numer/denom).length()+1;
        
        for(int y = 0;y<10000;y++){
            for(int x = 0;x<10;x++){
                mark[y][x]=-1;
            }
        }

        if(term == false){
            top: for(int x = 0;x<decimal.length;x++){
                mid:for(int a = 0; a<10000;a++){
                    	int compare = mark[a][decimal[x]];
                    	
                    	if(compare==-1){
                    		mark[a][decimal[x]] = x;
                    		break;
                    	}
                    	if(compare-x>=denom) break;
                    	for(int b = 1; b<x-compare;b++){
                    		if(decimal[compare+b]!=decimal[x+b]) continue mid;
                    	}
                    	if(check(compare, x, decimal)){
                    		start = compare;
                    		end = x;
                    		break top;
                    	}
                    
                }
            }            
            
        }
	
	
        else{
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
	
        System.out.println(start+" "+end);

	
        out.print(numer/denom+".");
        for(int x = 0;x<start;x++){

			if(line==76){
				out.println();
				line = 0;
			}
            out.print(decimal[x]);
            line++;
		
        }
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
   
    static boolean check(int start, int end, int[] decimal){
        if(start<0||end<0) return false;
        int begin = end;
        if(start==end-1){
        	
        	if(decimal[end+1]==decimal[end]&&decimal[end+2]==decimal[end]&&decimal[end+3]==decimal[end]) return true;
        	else return false;
        }
        
        for(int a = 0; a<3;a++){
            for(int x = 0;x<end-start;x++){
                if((begin+x)>=decimal.length) return true;
                if(decimal[begin+x]!=decimal[start+x]) return false;
            }
            begin+=(end-start);
        }
        return true;
    }

    
    
    static int[] divide(int numer, int denom){

        int[] quotient = new int[100000];
        
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
            else div*=10;
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

