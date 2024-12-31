// Disjoint set (Union-Find) (GFG)
// GFG Link : https://shorturl.at/EPxBh

// Time Complexity : O(n)
// Space Complexity : O(1)

int find(int A[],int X)
{
    //add code here
    // Step 1: Check if X is its own parent, if yes, return X
    if (A[X] == X) return X;

    // Step 2: Recursively find the parent and apply path compression
    return A[X] = find(A, A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	// Step 1: Find the parent of X
    int parentX = find(A, X);

    // Step 2: Find the parent of Z
    int parentZ = find(A, Z);

    // Step 3: Make the parent of X point to the parent of Z
    A[parentX] = parentZ;

    return;
}