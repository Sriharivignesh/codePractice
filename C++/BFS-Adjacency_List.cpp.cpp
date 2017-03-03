//
// Created by Sri Hari Vignesh on 23/02/17.
//


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
#include <sstream>
#include <list>


void do_bfs(char starting, std::vector<bool> node_done, std::queue<char> bfs_queue, std::vector<std::list<char>> &sgraph)
{
    bfs_queue.push(starting);
    while(!bfs_queue.empty())
    {
        auto head = bfs_queue.front();
        node_done[head - 'a'] = 1;
        bfs_queue.pop();
        std::cout << head << ",";
        for(auto i = sgraph[head - 'a'].begin(); i != sgraph[head - 'a'].end(); i++)
        {
            if(!node_done[*i - 'a'])
            {
                bfs_queue.push(*i);
                node_done[*i - 'a'] = 1;
            }
        }
    }
    int counter = -1;
    for(auto i : sgraph)
    {
        counter++;
        if(!i.empty())
        {
            if(!node_done[counter])
            {
                node_done[(char)(counter + 97)] = 1;
                do_bfs((char)(counter + 97), node_done, bfs_queue, sgraph);
            }
        }
    }
    return;
}


void populate_graph(char node1, char node2, std::vector<std::list<char>> &sgraph)
{
    sgraph[node1 - 'a'].push_back(node2);
    sgraph[node2 - 'a'].push_back(node1);
    return;
}

void print_graph(std::vector<std::list<char>> &sgraph)
{
    std::cout << "*******Printing the graph**********" << "\n";
    int counter = -1;
    for(auto i : sgraph)
    {
        counter++;
        if(!i.size())
        {
            continue;
        }
        std::cout << (char)(counter + 97) << ": ";
        for(auto k : i)
        {
            std::cout << k << ",";
        }
        std::cout << "\n";
    }
    std::cout << "*******************************" << "\n";
}


int main()
{
    std::vector<std::list<char>> graph(26);
    std::vector<bool> node_done(26, 0);
    char starting_node = 'a';
    populate_graph('a', 'b', graph);
    populate_graph('b', 'c', graph);
    populate_graph('c', 'd', graph);
    populate_graph('c', 'f', graph);
    populate_graph('g', 'f', graph);
    populate_graph('d', 'f', graph);
    print_graph(graph);
    //populate_graph('a', 'b', graph);
    std::queue<char> bfs_queue;
    do_bfs(starting_node, node_done, bfs_queue, graph);
    return 0;
}

