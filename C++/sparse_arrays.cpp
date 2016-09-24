/* SPARSE ARRAY - https://www.hackerrank.com/challenges/sparse-arrays */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int number = 0;
    std::cin>>number;
    string input_string;
    unordered_map <string,int> string_count;
    for(int i = 0;i < number;i++)
    {
        std::cin>>input_string;
        //cout<<string_count.at(input_string);
        //string_count.insert(make_pair(input_string,string_count[input_string]++));
        string_count[input_string]++;
    }
    std::cin>>number;
    for(int i = 0;i < number; i++)
    {
        std::cin>>input_string;
        std::cout<<string_count[input_string]<<endl;
    } 
      
    return 0;
}

