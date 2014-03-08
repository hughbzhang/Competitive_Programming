package Algorithms;
import java.io.*;
import java.util.*;
/*
 * Given a string, this program will find all possible anagrams of that string. It will print them out in an String ArrayList.
 * 
 * 
 * 
 * 
 */
public class Anagram {
	
	public static void main(String args[]) throws IOException{
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("anagram.out")));
		
		ArrayList<String> all = new ArrayList<String>();
		
		anagram("", "avastgoogles", all);
		for(int a = 0; a<all.size();a++){
			out.println(a+" "+all.get(a));
		}
		out.close();
	}
	
	
	private static ArrayList<String> anagram(String prefix, String rest, ArrayList<String> all){
		
		if(rest.length() == 1){
			all.add(prefix+rest);
		}
		for(int x = 0; x<rest.length();x++){
			String past = rest.substring(0,x);
			String present = rest.substring(x,x+1);
			String future = rest.substring(x+1);
			anagram(prefix+present,past+future, all);
		}
		
		
		return all;
	}
	
		}