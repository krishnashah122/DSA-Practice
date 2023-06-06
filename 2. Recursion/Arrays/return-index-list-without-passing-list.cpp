// Return the list that contains all the index of given element without passing the list.
// THIS APPROACH IS NOT RECOMMENDED

#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndex(vector<int> arr, int i, int target){
    vector<int> index;
    if(i == arr.size()){
        return index;
    }
    if(arr[i] == target){
        index.push_back(i);
    }
    vector<int> prevAns = findAllIndex(arr, i + 1, target);
    for(int j = 0; j < prevAns.size(); j++){
        index.push_back(prevAns[j]);
    }
    return index;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 4, 5};
    vector<int> index = findAllIndex(arr, 0, 4);
    if(index.size() > 0){
        cout << "All indexes are: ";
        for(int i = 0; i < index.size(); i++){
            cout << index[i] << " ";
        }
    }else{
        cout << "The element do not found.";
    }
    return 0;
}