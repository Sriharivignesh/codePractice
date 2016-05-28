/*This program accepts size of input array and the array elements. Then prints out the fraction of elements that are
positive, negative and zero*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    float size = (float)n;
    float zeroes = 0;
    float positives = 0;
    float negatives = 0;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       if(arr[arr_i] == 0)
       {
           zeroes++;
       }
       else if(arr[arr_i] < 0)
       {
           negatives++;
       }
       else
       {
           positives++;
       }
    }
    cout<<positives/size<<endl;
    cout<<negatives/size<<endl;
    cout<<zeroes/size<<endl;
    return 0;
}