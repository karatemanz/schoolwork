
import java.util.*;
public class DLBdict implements DictInterface{

	private Node next;
	private LinkList nextList;
	
	private int levelCount;
	private boolean empty;
	private LinkList root;
	private int size;
	private final char TERMINATOR = '@';  // :) I'll be back!
	
	
	public DLBdict(){
	// default constructor initializes basic variables 	
		
		this.size = 0;
		this.levelCount = 0;
		this.empty = true;
	}
	
	public DLBdict(String s){
	// string based constructor
		
		this.add(s);
		this.size = 1;
		this.levelCount = 0;
		this.empty = true;
		
	}
	
	public int size(){
	// words in the dictionary
		
		return this.size;
		
	}
	
	public int count(){
	// number of lists	
		
		return this.levelCount;
		
	}
	
	public boolean add(String s) {
	
		this.size = size+1;
		
		if(this.empty == false){
		// CASE: the dictionary isn't empty
		// ACTION:
		// 1.) links dictionary start to root node
		
			int found = 0;
			int loc = 0;
			
			Node cur = this.root.start;
			
			for(int i=0; i<=s.length()-1; i++){
				
				//System.out.println(s.charAt(i));
				
				if(cur.val == s.charAt(i) && i == s.length()-1){
				// CASE: hit the last letter to be added
					
					if(cur.child.val == this.TERMINATOR){
					// CASE: terminal character found and word already in dictionary
				
						this.size--;
						return false;
						
						
					}else{
					// CASE: terminal character not found
						
						cur = cur.child;
						
						if(cur.sib == null){
						// CASE: no sibling node connected to current child
						// word is a prefix to a word already
							
							cur.sib = new Node(this.TERMINATOR);
							return true;
							
						}else{
						// CASE: the node has siblings
						// ACTION:
						// 1.) check all siblings for a terminal node
						
							while(cur.sib != null){
							// LOOP: all non-null sibling nodes	
								
								System.out.println(cur.val);
								
								if(cur.val == this.TERMINATOR){
								// CASE: the node has a terminal char and the word is
								// already a part of the dictionary
									
									this.size--;
									return false;
									
								}
								
								cur = cur.sib;
							}
							
							cur.sib = new Node(this.TERMINATOR);
							cur = cur.sib;
							return true;
							
						}
						
						
					}
					
					
				}
				if(cur.val != s.charAt(i)){
				// CASE: current letter doesn't match current value
				// ACTION:
				// 1.) make a new sibling at level
					
					if(cur.sib == null){
					// CASE: the next sibling node is null
					// ACTION:
					// 1.) make new nod for a missing letter
					// 2.) save location and break out of for loop
						
						cur.sib = new Node(s.charAt(i));
						cur = cur.sib;
						loc = i+1;
						break;
						
					}else{
					// CASE: the next sibling node isn't null
					// ACTION:
					// 1.) find legal location to add sibling nodes
						
						while(cur.sib != null){
						// LOOP: through non-null nodes till location is found
							
							cur = cur.sib;
							
							if(cur.val == s.charAt(i)){
							// CASE: found the node with the letter
								
								found = 1;
								break;
								
							}	
						}
						
						if(found == 0){
						// CASE: letter is not found
							
							cur.sib = new Node(s.charAt(i));
							cur = cur.sib;
							loc = i+1;
							break;
							
						}else{
						// CASE: letter is found	
							
							found = 0;
							
						}
						
					}	
				}
				
				cur = cur.child;
			}
			
			if( loc > s.length()-1 ){
			// CASE: stored loc index is greater than the length of the word
			// ACTION:
			// 1.) links child to the terminal node
				
				LinkList end =  new LinkList(this.TERMINATOR);
				cur.child = end.start;
				return true;
				
			}else if( loc == s.length()-1 ){
			// CASE: stored loc index is the end of the word
			// ACTION:
			// 1.) add current node at that location followed by a terminal node
				
				LinkList list = new LinkList(s.charAt(loc));
				cur.child = list.start;
				cur = cur.child;
				
				LinkList end = new LinkList(this.TERMINATOR);
				cur.child = end.start;
				return true;
				
				
			}else{
			// CASE: loc index is at point where more nodes need to be made to
			// complete the word
				
				for(int i=loc; i<=s.length()-1; i++){
				// LOOP: creates the rest of the nodes of the word
					
					LinkList list = new LinkList(s.charAt(i));
					cur.child = list.start;
					cur = cur.child;
						
				}
				
				LinkList end = new LinkList(this.TERMINATOR);
				cur.child = end.start;
				return true;
				
			}

		}else{
		// CASE: the dictionary is empty
		// ACTION:
		// 1.) links dictionary start to root node
		// 2.) create a new list and link all letters in string together
		// 3.) add terminating character to end of the word
			
			LinkList past = new LinkList(s.charAt(0));
			this.root = past;
		
			for(int i=1; i<s.length(); i++){
			// starts at 	
				
				LinkList cur = new LinkList(s.charAt(i));
				past.start.child = cur.start;
				past = cur;
				
			}
			
			LinkList end = new LinkList(TERMINATOR);
			past.start.child = end.start;
			
			// sets the dictionary to not empty
			this.empty = false;
			return true;
			
			
		}
	}	

	public int searchPrefix(StringBuilder s) {
		
		nextList = this.root;
		next = this.root.start;
		
		boolean word = false;
		boolean prefix = false;
		
		for(int i=0; i<=s.length()-1; i++){
		// LOOP: through the entire word 	
			
			if( search(s.charAt(i), nextList) && i == s.length()-1 ){
			// CASE: the end of the word and found the letter	
				
				prefix = true;
				
				next = next.child;
				nextList = next.list;
				
				int toTerm = 0;
				while(next.sib != null){
				// LOOP: through non-null nodes c	
					
					toTerm++;
					next = next.sib;
					
				}
			
				if( findTerm(nextList) ){
				// CASE: if the terminal char is found	
					
					word = true;
					
					if(toTerm < 1){
					// CASE: not a prefix	
						
						prefix = false;
						break;
						
					}
					
				}
				
			}else if( search(s.charAt(i), nextList) ){
			// CASE: only found the letter
					
				next = next.child;
				nextList = next.list;
				
			}
		}
		
		if ( prefix && word ) return 3;
		else if ( word ) return 2;
		else if ( prefix ) return 1;
		else return 0;

	}

	public int searchPrefix(StringBuilder s, int start, int end) {
		
		nextList = this.root;
		next = this.root.start;
		
		boolean word = false;
		boolean prefix = false;
		
		for(int i=start; i<=end; i++){
		// LOOP: through the start location to the end location of StringBuilder	
			
			//System.out.println(s.charAt(i));
			
			if( search(s.charAt(i), nextList) && i == end ){
				// CASE: the end of the word and found the letter	
					
					prefix = true;
					
					next = next.child;
					nextList = next.list;
					
					int toTerm = 0;
					while(next.sib != null){
					// LOOP: through non-null nodes c	
						
						toTerm++;
						next = next.sib;
						
					}
					
					if( findTerm(nextList) ){
					// CASE: if the terminal char is found	
						
						word = true;
						
						if(toTerm < 1){
						// CASE: not a prefix	
							
							prefix = false;
							break;
							
						}
						
					}

				}else if( search(s.charAt(i), nextList) ){
				// CASE: only found the letter
					
					next = next.child;
					nextList = next.list;
					
				}
		}
	
		if ( prefix && word ) return 3;
		else if ( word ) return 2;
		else if ( prefix ) return 1;
		return 0;
	}
	
	public boolean search(char v, LinkList l){
		
		if(nextList.start.val == v){
		// CASE: match is found at first node of list
			
			//System.out.println(nextList.start.val);
			
			return true;
			
		}else{
		// CASE: must look for a match
			
			while( next != null ){
			// LOOP: search all non-null nodes
			
				if(next.val == v){
					
					//System.out.println(next.val);
					
					return true;
					
				}
				
				next = next.sib;
			}
			
			return false;
			
		}

	}
	
	public boolean findTerm(LinkList list){
		
		nextList = list;
		next = list.start;
		
		if(search(this.TERMINATOR, list) != true){
			
			return false;
			
		}else{
			
			return true;
			
		}
		
		
	}
}
