package Algorithms;

public class Subset {
	
	public static void main(String[] args){
		System.out.println(next(new StringBuffer("10110")));
	}
	
	public static StringBuffer next(StringBuffer current){
		int counter = 0;
		int length = current.length();
		boolean shift = false;
		for(int x = length-1;x>-1;x--){
			if(current.charAt(x)=='1'){
				shift = true;
				counter++;
			}
			else if(shift){
				counter--;
				current.setCharAt(x, '1');
				current.delete(x+1, length+1);
				while(current.length()<length-counter) current.append('0');
				while(current.length()<length) current.append('1');
				break;
			}
		}
		return current;
	}
}
