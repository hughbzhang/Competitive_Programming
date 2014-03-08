package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: ariprog
*/
import java.awt.Point;
import java.io.*;
import java.util.*;

public class ariprog {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("ariprog.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));
     double startt = System.currentTimeMillis();    
    int length = Integer.parseInt(f.readLine());
    int max = Integer.parseInt(f.readLine());
    int lengthm = length-1;
    
    boolean [] numbers = new boolean[max*max*2+1];
    ArrayList<Point> sequences = new ArrayList<Point>();
    for(int x = 0; x<=max;x++){
    	for(int y = 0; y<=x;y++){
    		numbers[x*x+y*y]=true;
    	}
    }
    
	
	
	/*for(int dist = 1; dist<(Math.ceil(numbers.get(numbers.size()-1))/length);dist++){
		for(int x = 0; x<numbers.size()-length;x++){
	
			int start = numbers.get(x);
			cont = true;
			top: for(int a = 1;a<length;x++){
				if(numbers.contains(start+a*dist)==false){
					
					cont = false;
					
					break top;
				}
			}
			if(cont){
			System.out.println(start + " " + dist);
			Point temp = new Point(start,dist);
			sequences.add(temp);
			
		
			}
	}
}
	    for(int x = 1; x<numbers.size();x++){
	    	//if((int)numbers.get(x)==(int)numbers.get(x-1)) break;
	    	
	    	System.out.println(numbers.get(x));
	}*/

	

	int size = numbers.length;
	int large = max*max*2;
	
	
	//System.out.println(numbers.get(142)+ " " + numbers.get(143));
	//System.out.println(numbers.size());
	
	//int start;
	//int diff;
	//int second;
	
	

	
	
	
	/*for(int x = 0; x<size-lengthm;x++){//only get part of the sequences.//lengthm = length - 1
		//start = Anumbers[x];
		
		top: for(int y = x+1; y<size-length+2;y++){
			diff = Anumbers[y]-Anumbers[x];
			//if(diff==0) System.out.println("wrong " + x +" "+ y);
				
			if(Anumbers[x]+(lengthm)*diff>large) break;
			
			for(int a = 2; a<length; a++){
				if(numbers.contains(Anumbers[x]+a*diff)==false){
					continue top;
				}
			}
			
			sequences.add(new Point(Anumbers[x], diff));
			

		
		
		}
	}*/
	
	int maxdiff = (int)Math.ceil(large/lengthm);
	int start, diff, index;
	
	//System.out.println(maxdiff);
	
for(int x = 0;x<large;x++){
	if(numbers[x]==false) continue;
	
	top: for(diff = 1; diff<=(large-x)/lengthm;diff++){
		if(x+lengthm*diff>large) break;
		for(int a = 1;a<length;a++){
			if(numbers[x+a*diff]==false) continue top;
		}
		
		sequences.add(new Point(x,diff));
		
		
		
		
	}
	
	
}
	
	
	double endt =  System.currentTimeMillis();
	System.out.println((endt-startt)/1000);
	
	/*for(int x = 0; x<sequences.size();x++){
		Point point = sequences.get(x);
		int X = point.x;
		int Y = point.y;
		System.out.println(X + " " + Y);
	}*/
	
	
	
	
	if(sequences.size()==0){
		out.println("NONE");
		out.close();
		System.exit(0);
	}
	

	boolean next = true;
	

	Point holder = new Point(-1,-1);
	Point holder2 = new Point(-1,-1);
	Point storage2 = new Point(-1,-1);
	
	while(next){
	  	   next = false;
	  	   for(int x = 1;x<sequences.size();x++){
	  		   
	  			holder = sequences.get(x);
	  			holder2 = sequences.get(x-1);
	  			
	  		   if(holder.y<holder2.y){
	  			   storage2 = holder;
	  			   sequences.set(x, holder2);
	  			   sequences.set(x-1, storage2);
	  			   next = true;
	  		   }
	  	   }
	     }
	next = true;
	while(next){
	  	   next = false;
	  	   for(int x = 1;x<sequences.size();x++){
	  		   
	  			holder = sequences.get(x);
	  			holder2 = sequences.get(x-1);
	  			
	  		   if(holder.x<holder2.x&&holder.y==holder2.y){
	  			   storage2 = holder;
	  			   sequences.set(x, holder2);
	  			   sequences.set(x-1, storage2);
	  			   next = true;
	  		   }
	  	   }
	     }

	
	

	/*
    for(int x = 0; x<size;x++){
	System.out.println(numbers.get(x));
}*/

	Point last = sequences.get(0);
	
	
    out.println(last.x+" " + last.y);
	
	for(int x = 1; x<sequences.size();x++){
		//Point prior = sequences.get(x-1);
		last = sequences.get(x);
		//if(prior.x==last.x&&prior.y==last.y) continue;
		
		out.println(last.x+" " + last.y);
	}

     
                           
    out.close();                             
    System.exit(0);                            
  }
}