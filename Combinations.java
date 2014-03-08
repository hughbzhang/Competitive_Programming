package Solved;

public class Combinations {
	public static void main(String[] args){
		combtemplate(new StringBuffer(""),new StringBuffer("123456789"), 5);
	}
	private static void combtemplate(StringBuffer prefix, StringBuffer s, int depth) {
        if(prefix.length()>depth) return;
		
		if (s.length() > 0) {
            System.out.println((new StringBuffer(prefix.append(s.charAt(0)).toString())));
            combtemplate(new StringBuffer(prefix.append(s.charAt(0)).toString()), s, depth);
            combtemplate(prefix,              new StringBuffer( s.deleteCharAt(0)), depth);
        }
    }

}
