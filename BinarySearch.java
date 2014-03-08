package Algorithms;

public class BinarySearch {
	public static void main(String[] args){
	
		System.out.println(search(new int[]{0,1}, 1));
		
	}
	
	static int search(int[] list, int target){
		
		int start = 0;
		int end = list.length;
		int index = end/2;
		
		while(start<=end){
			if(list[index]==target) return index;
			else if(list[index]<target) start = index+1;
			else end = index-1;
			
			index = (start+end)/2;
			
		}
		return -1;
		
		
	}
	
}
