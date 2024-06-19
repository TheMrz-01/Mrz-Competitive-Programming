use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug)]
struct Node {
    data: i32,
    next: Option<Rc<RefCell<Node>>>,
}

impl Node {
    fn new(data: i32) -> Rc<RefCell<Self>> {
        Rc::new(RefCell::new(Node { data, next: None }))
    }
}

#[derive(Debug)]
struct LinkedList {
    head: Option<Rc<RefCell<Node>>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn append(&mut self, data: i32) {
        let new_node = Node::new(data);
        match self.head {
            Some(ref head) => {
                let mut current = head.clone();
                while let Some(ref next) = current.borrow().next {
                    current = next.clone();
                }
                current.borrow_mut().next = Some(new_node);
            }
            None => {
                self.head = Some(new_node);
            }
        }
    }

    fn display(&self) {
        let mut current = self.head.clone();
        while let Some(ref node) = current {
            print!("{} -> ", node.borrow().data);
            current = node.borrow().next.clone();
        }
        println!("None");
    }
}

fn main() {
    let mut list = LinkedList::new();
    list.append(1);
    list.append(2);
    list.append(3);
    list.display(); // Output: 1 -> 2 -> 3 -> None
}