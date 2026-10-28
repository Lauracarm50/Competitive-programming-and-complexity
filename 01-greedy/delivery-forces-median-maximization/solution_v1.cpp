#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

//Adaptability
#define N 3 


using namespace std;

int main(){

    //Read number of elements 
    int n_elems; 
    cin >> n_elems;

    //Read numbers as a string and create stringstream to later read in array
    cin.ignore();
    string nums; 
    getline(cin, nums);


    //From string to array 
    stringstream ss(nums);
    vector<int> array_nums(n_elems);
    for(int i = 0; i < n_elems; i++){
        ss >> array_nums[i];
        //CHECKPOINT
        // cout << "Pos " << i << ": " << array_nums[i] << endl; 
    }

    //1.Sort function (O(n log n))
    sort(array_nums.begin(), array_nums.end());

       for(int i = 0; i < n_elems; i++){
        //CHECKPOINT
        // cout << " ORDENADO Pos " << i << ": " << array_nums[i] << endl; 
    }

    //2. Algorythm: groups of three with the smallest available and the two bigger available

    //pointers of availability 
    int small_pos = 0;
    int big_pos = n_elems - 1 ;

    //For the corresponding number of iterations, update pointers and selects big_pos-1 
    //as the median, and update the current sum
    long long current_sum = 0; 
    while(small_pos < big_pos){
        current_sum += array_nums[big_pos - 1];

         //CHECKPOINT:
        // cout << "small pos: " << small_pos << "\n Element small pos: " << array_nums[small_pos]
        // << "\n Big pos: "  << big_pos << "\n Element big pos: "<< array_nums[big_pos] 
        // << "\n Element big pos - 1: "<< array_nums[big_pos - 1]
        // << "\n current sum: "<< current_sum << endl; 


        small_pos += 1;
        big_pos -= 2; 

    }

    //Final print: 
    cout << current_sum << endl;




}