struct Queue<T> {
    stack: Vec<T>, 
    size: usize
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue{
            stack: vec![],
            size: 0
        }
    }

    fn size(&self) -> usize {
        self.size
    }

    fn enqueue(&mut self, item: T) {
        self.stack.insert(0, item);
        self.size += 1;
    }

    fn dequeue(&mut self) -> Option<T> {
        self.stack.pop()
    }
}