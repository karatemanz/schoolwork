
public class Node {

	public Node sib = null;
	public Node child = null;
	public char val;
	public LinkList list;
	
	public Node(){
	// default null node constructor	
		
		this.val = '0'; // '0' will signify a null pointer for char values
		
	}
	
	public Node(char v){
	// standard node constructor
		
		this.val = v;
		
	}
	
}
	
