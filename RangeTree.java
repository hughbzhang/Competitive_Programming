package Algorithms;

import java.util.Arrays;

/**
 * TODO remove
 * TODO range
 * 
 * 
 * @author hughzhang
 *
 */

public class RangeTree {
	
	//KEY METHODS AT THE TOP
	Node root;//the root of the tree
	
	public RangeTree(int[] in){//construct a range tree from a random input array of integers
		Arrays.sort(in);
		int mid = (int)(in.length/2);
		root = new Node(in[mid]);//middle value is the root
		root.left = construct(in, 0, mid-1);//construct left and right trees recursively
		root.right = construct(in, mid+1, in.length-1);
		
	}
	
	public boolean contains(int value){
		return contains(root, value);
	}
	public void print(){
		printInOrder(root);
	}
	public Node getRoot(){
		return root;
	}
	public boolean add(int value){
		return add(root, value);
	}
	
	
	
	
	//Implementation
	
	class Node{
		Node left;
		Node right;
		int key;
		
		public Node(int in){
			key = in;
			left = null;
			right = null;
		}
	}
	
	private Node construct(int[] in, int start, int end){
		if(end<start) return null;
		if(start==end) return new Node(in[start]);
		if(start==end-1){
			Node top = new Node(in[end]);
			top.left=new Node(in[start]);
			return top;
		}
		//end of base cases
		
		Node root;
		int mid = start + (int)((end-start)/2);
		root = new Node(in[mid]);
		root.left = construct(in, start, mid-1);
		root.right = construct(in, mid+1, end);
		return root;
	}
	
	private boolean contains(Node root, int value){
		if(root==null) return false;
		if(root.key==value) return true;
		if(value<root.key) return contains(root.left, value);
		else return contains(root.right, value);
	}
	
	public void printInOrder(Node root){//prints out the values in order from least to greatest
		if(root.left!=null) printInOrder(root.left);
		System.out.println(root.key);
		if(root.right!=null) printInOrder(root.right);
	}
	private boolean add(Node root, int value){
		if(root.key==value) return false;
		if(root.key>value){
			if(root.left!=null) return add(root.left, value);
			root.left = new Node(value);
			return true;
		}
        if(root.right!=null) return add(root.right, value);
        root.right = new Node(value);
        return true;
	}
	
}
