// Binary Heap Operations (GFG)
// GFG Link : https://shorturl.at/wKpEM

// Time Complexity : O(Q * Logn) where, n is the heap size.
// Space Complexity : O(1)

/* The structure of the class is
struct MinHeap
{
    int *harr; // Pointer to array of elements in heap
    int capacity; // Maximum possible size of the min heap
    int heap_size; // Current number of elements in min heap
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];} // Constructor

    int extractMin(); // Method to remove minimum element (or root) from min heap
    void deleteKey(int i); // Method to delete a key at given index i
    void insertKey(int k); // Method to insert a new key 'k'
    int parent(int i); // Method to get the parent index of a given index i
    int left(int i); // Method to get the left child index of a given index i
    int right(int i); // Method to get the right child index of a given index i
}; */

// Function to extract minimum value in heap and then to store 
// next minimum value at first index.
int MinHeap::extractMin() 
{
    // Your code here
    if(heap_size <= 0) return -1;
    if(heap_size == 1){
        heap_size--; // Decrease heap size
        return harr[0]; // Return the only element
    }
    
    int root = harr[0]; // Store the minimum value
    harr[0] = harr[heap_size - 1]; // Move the last element to root
    heap_size--; // Decrease heap size
    MinHeapify(0); // Call MinHeapify on the root
    
    return root;
}

// Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    if(i < heap_size){
        decreaseKey(i, INT_MIN); // Decrease the key to minimum value
        extractMin(); // Extract the minimum value
    }
}

// Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    // Your code here
    if(heap_size >= capacity) return;
    
    harr[heap_size] = k; // Insert the new key at the end
    int i = heap_size; // Initialize index of new key
    heap_size++; // Increase heap size
    
    // Fix the min heap property if it is violated
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]); // Swap if parent is greater than child
        i = parent(i); // Move to parent index
    }
}

// Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val; // Update the value at index i
    while (i != 0 && harr[parent(i)] > harr[i]) { // Fix the min heap property if it is violated
        swap(harr[i], harr[parent(i)]); // Swap if parent is greater than child
        i = parent(i); // Move to parent index
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i); // Get the left child index
    int r = right(i); // Get the right child index
    int smallest = i; // Initialize smallest as root
    if (l < heap_size && harr[l] < harr[i]) smallest = l; // If left child is smaller than root
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r; // If right child is smaller than smallest
    if (smallest != i) { // If smallest is not root
        swap(harr[i], harr[smallest]); // Swap root with smallest
        MinHeapify(smallest); // Recursively heapify the affected sub-tree
    }
}