
public class ArrayStack<T> implements StackInterface<T>{

	private int top;
	private T [] storage;
	
	ArrayStack(int capacity) {
		
        if (capacity <= 0) throw new IllegalArgumentException("Stack's capacity must be positive");
        
        storage = (T[])new Object[capacity];
        top = -1;
        
	}
	public void push(T newEntry) {

		if (top == storage.length){
			System.out.println("The stack is full");
		}else{
			
			top++;
			storage[top] = newEntry;
			
		}	

	}
	
	public T pop() {
		
		if (top == -1) return null;
		
			T temp = storage[top];
			storage[top] = null;
		
			top--;
			
		return temp;
	}
	
	public T peek() {

		if (top == -1) return null;
		return storage[top];
		
	}

	public boolean isEmpty() {

		return (top == -1);
		
	}

	public void clear() {

		int i=0;
		
		while(i<storage.length){
			
			storage[i] = null;
			i++;	
		}
		top = -1;
	}
}