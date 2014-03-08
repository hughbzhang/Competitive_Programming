package Solved;

public class Four {
	public static void main(String[] args){
		int max = 0;
		
		for(int x = 100;x<1000;x++){
			for(int y = 100;y<1000;y++){
				if(pal(x*y)&&x*y>max) max = x*y;
			}
		}
		System.out.println(max);
	}
	public static boolean pal(int in){
		String check = Integer.toString(in);
		for(int x = 0;x<check.length();x++){
			if(check.charAt(x)!=check.charAt(check.length()-1-x)) return false;
		}
		return true;
	}
}
