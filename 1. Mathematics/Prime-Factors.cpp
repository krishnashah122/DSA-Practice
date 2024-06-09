// Prime Factors (GFG)
// GFG Link : https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> primeFactors;
	    vector<int> isPrime(N + 1, 1);
	    isPrime[0] = isPrime[1] = 0;
	    
	    // Mark the multiple of prime number as 0
	    for(int i = 2; i * i <= N; i++){
	        if(isPrime[i]){
	            for(int j = i * i; j <= N; j += i){
	                isPrime[j] = 0;
	            }
	        }
	    }
	    
	    for(int i = 2; i <= N; i++){
	        if(isPrime[i] && N % i == 0){
	            primeFactors.push_back(i);
	        }
	    }
	    
	    return primeFactors;
	}
};