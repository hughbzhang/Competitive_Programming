package Algorithms;

public class Cipher {
	public static void main(String[] args){
		
		String input = "avastgoogles";
		input = input.toLowerCase();
		StringBuffer next = new StringBuffer("");
		for(int x = 0;x<26;x++){
			next.delete(0, next.length());
			for(int a =0;a<input.length();a++){
				int index = input.charAt(a)-97+x;
				index%=26;
				index+=97;
				next.append((char)index);
			}
			System.out.println(next);
		}
		
		
	}
}
