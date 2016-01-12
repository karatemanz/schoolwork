
public class LinkList {

	public Node start;
	public LinkList list = this;
	public int size;
	
	
	public LinkList(){
	// default  null list constructor
		
		Node newNode = null;
		this.start = null;
		newNode.list = null;
		this.size = 0;
		
	}
	
	public LinkList(char v){
	// standard list constructor		
		
		Node newNode = new Node(v);
		this.start = newNode;
		newNode.list = this;
		this.size++;
		
	}
}
