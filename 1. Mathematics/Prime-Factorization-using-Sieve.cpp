// Prime Factorization using Sieve (GFG)
// GFG Link : https://shorturl.at/QRTGq

// Time Complexity : O(n * LogLogn)
// Space Complexity : O(n)

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<int> isPrime(N + 1, 1);
        vector<int> primeFactors;
        
        // Store i as the value at ith index in isPrime
        for(int i = 0; i <= N; i++){
            isPrime[i] = i;
        }
        
        // Store the smallest prime factor for every number
        for(int i = 2; i * i <= N; i++){
            // If the number hasn't been visited, mark its multiple with their smallest prime factor
            if(isPrime[i] == i){
                for(int j = i * i; j <= N; j += i){
                    if(isPrime[j] == j){
                        isPrime[j] = i;
                    }
                }
            }
        }
        
        // Finding prime factorization of N
        while(N > 1){
            primeFactors.push_back(isPrime[N]);
            N = N / isPrime[N];
        }
        
        return primeFactors;
    }
};