// Occurrence of character in an string using Hashing.

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string s;
    cout << "Enter string: ";
    cin >> s;

    // Precomputing
    int hash[256] = {0}; // max no. of characters exist
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cout << "How many character's occurrence you want to check? ";
    cin >> q;
    while(q--){
        char ch;
        cout << "Enter character you want to check: ";
        cin >> ch;
        // Fetching
        cout << ch << " : " << hash[ch] << endl;
    }

    return 0;
}