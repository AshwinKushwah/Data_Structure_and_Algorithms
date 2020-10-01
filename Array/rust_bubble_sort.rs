fn bubble_sort(arr: &mut Vec<impl Ord + Clone>) {
    loop {
        let mut swapped = false;
        for (i, e) in arr.clone().iter().take(arr.len() - 1).enumerate() {
            if e > arr.get(i + 1).unwrap() {
                arr.swap(i, i + 1);
                swapped = true;
            }
        }
        if !swapped {
            break;
        }
    }
}

fn main() {
    let mut vec = vec![1, 4, 2, 5, 8, 3, 2];
    bubble_sort(&mut vec);
    println!("{:?}", vec);
}