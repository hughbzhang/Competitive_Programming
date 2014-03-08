package Algorithms;


public class tester{
	
	public static void main(String[] args){
		int[] insert = new int[]{1, 3, 5, 6, 7, 8, 10};
		RangeTree test = new RangeTree(insert);
		test.add(245);
		test.add(42);
		test.add(-1);
		test.print();
		
	}
}