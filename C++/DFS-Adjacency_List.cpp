//
// Created by Sri Hari Vignesh on 22/02/17.
//

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>

void do_dfs(char starting, std::vector<bool> &node_done, std::vector<std::list<char>> &sgraph)
{
    if(!node_done[starting - 'a'])
    {
        node_done[starting - 'a'] = 1;
        std::cout << starting << "->";
        for(auto i = sgraph[starting - 'a'].begin(); i != sgraph[starting - 'a'].end(); i++)
        {
            if(!node_done[*i - 'a'])
            {
                do_dfs(*i, node_done, sgraph);
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
    do_dfs(starting_node, node_done, graph);
    return 0;
}

