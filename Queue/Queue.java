import java.util.ArrayList;

public class Queue<E> {
	private ArrayList<E> elements;

	public Queue() {
		elements = new ArrayList<E>();
	}

	/* Add to queue */
	public void enqueue(E element) {
		elements.add(element);
	}

	/* Get and remove last element */
	public E dequeue() {
		int lastIndex = elements.size() - 1;
		E element = elements.get(lastIndex);
		elements.remove(lastIndex);
		return element;
	}

	/* Get last element without removing */
	public E peek() {
		int lastIndex = elements.size() - 1;
		return elements.get(lastIndex);
	}

	public boolean isEmpty() {
		return elements.isEmpty();
	}
}
