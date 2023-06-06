// Find all index of given element's in the array.

#include <iostream>
#include <vector>
using namespace std;

bool finder(vector<int> arr, int i, int target){
    if(i == arr.size()-1){
        if(arr[i] == target){
            return true;
        }
        return false;
    }
    return (arr[i] == target) || finder(arr, i+1, target);
}

int findIndex(vector<int> arr, int i, int target){
    if(i == arr.size()){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }else{
        return findIndex(arr, i + 1, target);
    }
}

vector<int> *findAllIndex(vector<int> arr, int i, int target, vector<int> *index){
    if(i == arr.size()){
        return index;
    }
    if(arr[i] == target){
        index->push_back(i);
    }
    return findAllIndex(arr, i + 1, target, index);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 4, 5};
    vector<int> index;

    if(finder(arr, 0, 4)){
        findAllIndex(arr, 0, 4, &index);
        cout << "All indexes are: ";
        for(int i = 0; i < index.size(); i++){
            cout << index[i] << " ";
        }
    }else{
        cout << "The element do not found.";
    }
    return 0;
}