#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <limits>
#include <stack>
#include <iterator>
#include <set>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <cstdint>
#include <random>
#include <valarray>
#include <numeric>


/*This solution is adapted from one of the excellent solutions posted for this problem on Stackoverflow*/
class MinStack {
public:
    std::stack<int> op_stack;
    std::stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack() {
        return;
    }
    
    void push(int x) {
        op_stack.push(x);
        if(min_stack.empty())
        {
            min_stack.push(x);
        }
        else if(x < min_stack.top())
        {
            min_stack.push(x);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        op_stack.pop();
        min_stack.pop();
        return;
    }
    
    int top() {
        return op_stack.top();
        
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    MinStack mins;
    mins.push(4);
    std::cout << mins.getMin() << "\n";
    mins.push(44);
    mins.push(0);
    mins.push(-100);
    mins.pop();
    std::cout << mins.getMin() << "\n";
    return 0;
}