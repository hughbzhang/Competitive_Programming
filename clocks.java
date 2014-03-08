package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: clocks
*/
import java.io.*;
import java.math.BigInteger;
import java.util.*;

//indexes always go
//[y] then [x]
//[0 1 2
//[3 4 5
//[6 7 8




public class clocks {
	
	static ArrayList<StringBuffer> list = new ArrayList<StringBuffer>();
	static int [] origin = new int[9];
	//static boolean solution = false;
	//static int counter = 0;
	
	public static boolean check(int a, int b, int c, int d, int e, int f, int g, int h, int i){
		
		if((origin[0]+a+b+d)%4!=0) return false;
		if((origin[1]+a+b+c+e)%4!=0) return false;
		if((origin[2]+b+c+f)%4!=0) return false;
		if((origin[3]+a+d+e+g)%4!=0) return false;
		if((origin[4]+a+c+e+g+i)%4!=0) return false;
		if((origin[5]+c+e+f+i)%4!=0) return false;
		if((origin[6]+d+g+h)%4!=0) return false;
		if((origin[7]+e+g+h+i)%4!=0) return false;
		if((origin[8]+f+h+i)%4!=0) 	return false;
		
		//System.out.println(a + " "+b + " "+c + " "+d + " "+e + " "+f + " "+g + " "+h + " "+i);
		
	return true;
	}
	
	public static void print(int[] printer){
		for(int y=0;y<9;y++){			
			System.out.print(printer[y]+" ");
		}
		System.out.println();
		System.out.println();
	}
	
	public static void save(int a, int b, int c, int d, int e, int f, int g, int h, int i){

		StringBuffer storage = new StringBuffer("");
		 int x = 0;
		 
		 for(x = 0; x<a;x++){ storage.append(1);}
		 for(x = 0; x<b;x++){ storage.append(2);}
		 for(x = 0; x<c;x++){ storage.append(3);}
		 for(x = 0; x<d;x++){ storage.append(4);}
		 for(x = 0; x<e;x++){ storage.append(5);}
		 for(x = 0; x<f;x++){ storage.append(6);}
		 for(x = 0; x<g;x++){ storage.append(7);}
		 for(x = 0; x<h;x++){ storage.append(8);}
		 for(x = 0; x<i;x++){ storage.append(9);}
			
		
		
		list.add(storage);
		
	}
	
	
  public static void main (String [] args) throws IOException {
    BufferedReader F = new BufferedReader(new FileReader("clocks.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("clocks.out")));
    String temp = F.readLine()+" "+F.readLine()+" "+F.readLine();
    
    
    StringTokenizer st = new StringTokenizer(temp);
    
    
    boolean go = true;
	
	for(int x=0;x<9;x++){
		origin[x]=(int)Integer.parseInt(st.nextToken())/3;
		if(origin[x]==4) origin[x]=0;
	}
	int counter = 1;
    while(go){
		for(int a = 0; a<counter;a++){
			for(int b = 0; b<counter;b++){
				for(int c = 0; c<counter;c++){
					for(int d = 0; d<counter;d++){
						for(int e = 0; e<counter;e++){
							for(int f = 0; f<counter;f++){
								for(int g = 0; g<counter;g++){
									for(int h = 0; h<counter;h++){
										for(int i = 0; i<counter;i++){
											if(check(a, b, c, d, e, f, g, h, i)){
												save(a, b, c, d, e, f, g, h, i);
												go = false;
												//System.out.println("YES");
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		counter++;
    }
	//check(1, 1, 1, 1, 1, 1, 1, 1, 1);
	
	BigInteger smallest = new BigInteger(list.get(0).toString());
	BigInteger holder = new BigInteger("0");
	StringBuffer done = new StringBuffer("");
	
	for(int x = 1; x<list.size();x++){
		//System.out.println(list.get(x));
		holder = new BigInteger(list.get(x).toString());
		smallest = smallest.min(holder);
	}
	String number = smallest.toString();
	
	done.append(number.charAt(0));
	
	for(int x = 1; x<number.length();x++){
		done.append(' ');
		done.append(number.charAt(x));
	}
	
	
	
	//System.out.println(done);
	
    out.println(done);
    out.close();
    System.exit(0);                               // don't omit this!
  }
  

  
  
}