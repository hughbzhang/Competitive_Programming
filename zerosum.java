package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: zerosum
*/
import java.io.*;
import java.util.*;

class zerosum {
	
	static int length;
	static ArrayList<StringBuffer> sol = new ArrayList<StringBuffer>();

	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("zerosum.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("zerosum.out")));
	
	    length = Integer.parseInt(f.readLine());
	    int max3 = (int)Math.pow(3, length-1);
	  
	    StringBuffer temp;
	    
	    for(int x = 1;x<max3;x++){
	    	
	    	temp = new StringBuffer (Integer.toString(x, 3));
	    	while(temp.length()<(length-1)) temp.insert(0, "0");
	    	//System.out.println(temp);
	    	check(temp);
	    }
	    
	    
	    
	    /*for(int x = 1; x<max;x++){
	    	sum = 1;
	    	for(int a = 1; a<length;a++){
	    		
	    		if(((1<<a-1)&x)==0){
	    			sum-=(a+1);
	    			path[a-1] = 0;
	    		
	    		}
	    		else{
	    			sum+=(a+1);
	    			path[a-1] = 1;
	    		}
	    	}
	    	if(sum==0){
	    		print(path);
	    		counter++;
	    	}
	    	
	    	//System.out.println(sum);
	    }
	    */
	   
	   String[] almost = new String[sol.size()];
	   
	   for(int x = 0;x<almost.length;x++){
		   almost[x] = sol.get(x).toString();
	   }
	   
	   boolean go = true;
	  String holder;
	   
	   	while(go){
	   		go = false;
	   		for(int x = 1;x<almost.length;x++){
	   			if(almost[x].compareTo(almost[x-1])<0){
	   				holder = almost[x];
	   				almost[x]=almost[x-1];
	   				almost[x-1]=holder;
	   				go = true;
	   			}
	   		}
	   	}
	   
	   
	   
	   for(int x = 0;x<almost.length;x++){
		   out.println(almost[x]);
	   }
	   
	   
	   
	    
	    
	    out.close();
	    System.exit(0);                          
	  
	  }
	
	static void check(StringBuffer temp){
		
		StringBuffer ans = new StringBuffer("+");
		StringBuffer done = new StringBuffer("");
		
		for(int x = 0; x<temp.length();x++){
			char key = temp.charAt(x);
			if(key=='0'){
				ans.append((x+1)+"-");
				done.append((x+1)+"-");
			}
			else if(key=='1'){
				ans.append((x+1)+"+");
				done.append((x+1)+"+");
			}
			else{
				ans.append(x+1);
				done.append((x+1)+" ");
			}
		}
		ans.append(length+"+");
		done.append(length);
		//System.out.print(ans);
		int start = -1;
		int sum = 0;
		boolean sign = true;
		for(int a = 0;a<ans.length();a++){
			if(ans.charAt(a)=='+'){
				
				if(start==-1) start = a+1;
				else{
					if(sign)  sum+=Integer.parseInt(ans.substring(start,a));
					else sum-=Integer.parseInt(ans.substring(start,a));
					start = a+1;
				}
				sign = true;
			}
			if(ans.charAt(a)=='-'){
				
				if(start==-1) start = a+1;
				else{
					if(sign)  sum+=Integer.parseInt(ans.substring(start,a));
					else sum-=Integer.parseInt(ans.substring(start,a));
					start = a+1;
				}
				sign = false;
			}
		}
		//System.out.println("="+sum);
		
		
		
		
		if(sum==0){
			sol.add(done);
		}
		return;
		
	}
	static void print(int[] printer){
		
		
		for(int x = 1; x<(printer.length+1);x++){
			if(printer[x-1]==0) System.out.print(x+"-");
			else if(printer[x-1]==1) System.out.print(x+"+");
			else System.out.print(x+" ");
		}
		System.out.print(7);
		System.out.println();
	}
}