// Allocate Books (Code Studio & GFG)
// Code Studio Link : https://bit.ly/3MZQOct
// GFG Link : https://bit.ly/3QMrMxP

// Time Complexity : O(nLogm)
// Space Complexity : O(1)

// function to count the no. of students to whom the book can be alloted with max pages
int countStudents(vector<int>& arr, int pages){
    int pagesAllocated = 0; // count pages allocated to a particular student
    int student = 1; // count the no. of student required to allocate pages

    // count the number of students that are required to allocate pages
    for(int i = 0; i < arr.size(); i++){ // O(n)
        // if pagesAllocated + arr[i] is less than or equal to the pages that needed to be allocated
        if(pagesAllocated + arr[i] <= pages){
            pagesAllocated += arr[i]; // add current pages to the pagesAllocated
        }
        // if pagesAllocated + arr[i] is more than the pages that needed to be allocated
        else{
            student++; // increament the no. of student by 1
            pagesAllocated = arr[i];
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    // if the no. of students is greater than the no. of books then return -1
    if(m > n) return -1;

    int maxi = 1;
    int sum = 0;
    // find the max element of the array and sum of the array assign it to sum and high respectively
    for(int i = 0; i < n; i++){ // O(n)
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    int low = maxi;
    int high = sum;
    while(low <= high){ // O(Logm)
        int mid = low + (high - low) / 2;

        int studentNum = countStudents(arr, mid);
        // if the students to whom 'mid' pages has been allocated is greater than the given student number
        if(studentNum > m){
            low = mid + 1; // to search in right part
        }
        else{
            high = mid - 1; // to search in left part
        }
    }
    return low;
}