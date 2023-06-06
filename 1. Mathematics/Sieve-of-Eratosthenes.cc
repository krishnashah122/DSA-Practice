// Prime numbers upto N.

// Time Complexity : O(nLogLogn)

#include <iostream>
#include <vector>
using namespace std;

// void SieveOfEratosthenes(int n){
//     vector<bool> isPrime(n+1, true);
//     isPrime[0] = false;
//     isPrime[1] = false;

//     for(int i = 2; i*i <= n; i++){
//         if(isPrime[i]){
//             for(int j = 2*i; j <= n; j = j + i){ //It will mark all the multiple of i to false
//                 isPrime[j] = false;
//             }
//         }
//     }

//     //Displaying the Prime numbers
//     for(int i = 2; i <= n; i++){
//         if(isPrime[i]){
//             cout << i << " ";
//         }
//     }
// }

//Shorter code having same Time Complexity
void SieveOfEratosthenes(int n){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i*1 <= n; i++){
        if(isPrime[i]){
            cout << i << " ";
            for(int j = i*i; j <= n; j = j + i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    int num;
    cout << "Enter number upto which you want prime number: ";
    cin >> num;
    SieveOfEratosthenes(num);
}