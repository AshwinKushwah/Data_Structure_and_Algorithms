fn main() {
    let mut vec = vec![5, 2, 7, 3, 1, 4, 9, 1, 9, 5];
    insertion_sort(&mut vec);
    println!("{:?}", vec);
}

fn insertion_sort(arr: &mut Vec<impl Ord + Copy>) {
    let mut lower_bound = 0;
    loop {
        let mut curr_index = lower_bound;
        let mut curr_smallest = arr[curr_index]; 
        for (i, e) in arr.iter().enumerate() {
            if *e < curr_smallest && i >= lower_bound {
                curr_smallest = *e;
                curr_index = i;
            }
        }
        arr.swap(lower_bound, curr_index);
        lower_bound += 1;
        if lower_bound == arr.len() {
            break
        }

    }
}
