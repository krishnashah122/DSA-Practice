// Count Primes (Leetcode)
// Leetcode Link : https://leetcode.com/problems/count-primes/description/

// Time Complexity : O(sqrt(n))
// Space Complexity : O(1)

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<int> isPrime(n, 1);
        isPrime[0] = isPrime[1] = 0;
        int primes = 0;

        // Mark the multiple of prime number as 0
        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = 0;
                }
            }
        }

        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                primes++;
            }
        }

        return primes;
    }
};