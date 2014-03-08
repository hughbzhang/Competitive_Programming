package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: typo
*/
import java.io.*;

public class typo {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("typo.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("typo.out")));
     StringBuffer line = new StringBuffer(f.readLine());
     int holder = 0;
     
     while(true){
    	 line = new StringBuffer("");
    	 holder++;
     String lol = Integer.toString(holder);
     for(int x = 0;x<lol.length();x++){
    	 if(lol.charAt(x)=='0') line.append('(');
    	 else line.append(')');
     }
     
     int count = 0;
     int answer = 0;
     int dp = 0;
     int check = 0;
     
     for(int x = 0;x<line.length();x++){
    	 if(line.charAt(x)=='(') count++;
    	 else count--;
     }
     
     
     
    
     if(count==2){
    	 for(int x = 0; x<line.length();x++){
    		 if(line.charAt(x)=='('){
    			 dp++;
    			 if(dp>=2) answer++;
    		 }
    		 else dp--;
    		 
    		 if(dp<0) break;
    			 
    	 }
    	 for(int x = 0; x<line.length();x++){
     		if(line.charAt(x)=='('){
     			StringBuffer temp = new StringBuffer(line);
     			temp.setCharAt(x, ')');
     			if(check(temp)) check++;
     		}
     	}
     	if(check!=answer){
     		System.out.println(line+" "+check+" "+answer);
     		break;
     	}
    	 
     }
     else if(count==-2){
    	 for(int x = line.length()-1; x>-1;x--){
    		 if(line.charAt(x)==')'){
    			 dp++;
    			 if(dp>=2) answer++;
    		 }
    		 else dp--;
    		 
    		 if(dp<0) break;
    	}
    	for(int x = 0; x<line.length();x++){
    		if(line.charAt(x)==')'){
    			StringBuffer temp = new StringBuffer(line);
    			temp.setCharAt(x, '(');
    			if(check(temp)) check++;
    		}
    	}
    	if(check!=answer){
    		System.out.println(line+" "+check+" "+answer);
    		break;
    	}
    	 
     }
     
     else{
    	 continue;
    	 //out.println(0);
    	 //out.close();
    	 //System.exit(0);
     }
     }
     
    //out.println(answer); 
     
    out.close();                             
    System.exit(0);                            
  }
  static boolean check(StringBuffer line){
	  int counter = 0;
	  for(int x = 0;x<line.length();x++){
		  if(counter<0) return false;
		  if(line.charAt(x)=='(') counter++;
		  else counter--;
	  }
	  
	  if(counter==0) return true;
	  else return false;
  }
}

//StringBuffer line = new StringBuffer(f.readLine());
/*int lol = 0;
while(true){
	 lol++;
	 String holder = Integer.toBinaryString(lol);
	 StringBuffer line = new StringBuffer();
	 for(int x = 0;x<holder.length();x++){
		 if(holder.charAt(x)=='0') line.append('(');
		 else line.append(')');
	 }


int[] forward = new int[line.length()];
int[] backward = new int[line.length()];
int counter = 0;
int large = 0;
for(int x = 0;x<line.length();x++){
	StringBuffer temp = new StringBuffer(line);
	if(temp.charAt(x)=='('){
		temp.setCharAt(x, ')');
		large++;
	}
	else{
		temp.setCharAt(x,'(');
		large--;
	}
	if(check(temp)) counter++;
	
	
}
char key;
if(large>0){
if(line.charAt(0)=='(') forward[0]=1;
else backward[0]=1;

for(int x = 1;x<line.length();x++){
	 forward[x]=forward[x-1];
	 backward[x]=backward[x-1];
	 if(line.charAt(x)=='(') forward[x]++;
	 else backward[x]++;
}
key = '(';
}
else{
    if(line.charAt(forward.length-1)=='(') forward[forward.length-1]=1;
    else backward[forward.length-1]=1;
    
    for(int x = line.length()-2;x>-1;x--){
   	 forward[x]=forward[x+1];
   	 backward[x]=backward[x+1];
   	 if(line.charAt(x)=='(') forward[x]++;
   	 else backward[x]++;
    }
    key = ')';
}
if(large>2||large<-2||check(line)){
	 continue;
	 //System.out.println("gp");
	 //out.println(0);
	 //out.close();
	 //System.exit(0);
}
int count = 0;
/*for(int x = 0;x<forward.length;x++){
	 System.out.print(backward[x]+" ");
}
System.out.println();
for(int x = 0;x<forward.length;x++){
	 System.out.print(forward[x]+" ");
}
System.out.println();
for(int x = 0;x<forward.length;x++){
	 System.out.print(line.charAt(x)+" ");
}
if(key=='('){
    for(int x = 0;x<line.length();x++){
   	 if(line.charAt(x)==key){ 
   		 if(forward[x]>=backward[x]+2) count++;
   		
   	}
    }
}
else{
	 for(int x = line.length()-1;x>=0;x--){
   	 if(line.charAt(x)==key){ 
   		 //if((forward[forward.length-1]-forward[x]+1)<=(backward[backward.length-1]-backward[x])) count++;
			 if(backward[x]>=forward[x]+2) count++;
			 
   	}
    }  	 
	 
	 
	 
	 
	 
	 
}
if(count!=counter){
	 System.out.println(line+" "+counter+" "+count);
	 break;
}


}
*/