struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn sum(node: &Node) -> i32 {
    let mut acc = node.value;
    if let Some(left) = &node.left {
        acc += sum(left);
    }
    if let Some(right) = &node.right {
        acc += sum(right);
    }
    acc
}

fn main() {
    let mut tree = Node {
        value: 1,
        left: Some(Box::new(Node {
            value: 2,
            left: None,
            right: None,
        })),
        right: Some(Box::new(Node {
            value: 3,
            left: None,
            right: None,
        })),
    };
    let total = sum(&tree); // 6
    tree.right = None; // tree is now Node { value: 1, left: Some(...), right: None }
    let left = tree.left;
    let unwrapped = left.unwrap();
    tree = *unwrapped; // tree is now Node { value: 2, left: None, right: None }
}
