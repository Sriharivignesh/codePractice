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
#include <list>

struct lnode
{
    int val;
    struct lnode *next;
};
struct Graph
{
    //int vertices;
    std::vector<std::vector<char>> neighbours;
    public:
    void graph_set();
    void dfs(char start);
    void addedge(char source, char target);
    void explore();
};

void Graph::graph_set()
{
    //this -> vertices = nodes;
    //this -> neighbours = new std::vector<std::vector<int>>(26);
    this -> neighbours.resize(26);
    for(auto i : this -> neighbours)
    {
        i.reserve(26);
    }
    std::cout << "reserved:" << neighbours.size() << "\n";
}

void Graph::addedge(char source, char target)
{
    this -> neighbours[source - 65].push_back(target);
}

void Graph::explore()
{
    std::cout << "here:" << this -> neighbours.size() << "\n";
    for(auto i : neighbours)
    {
        for(auto k : i)
        {
            std::cout << k << "\n";
        }
    }
}

void Graph::dfs(char start)
{
    bool checked[26];
    for(int i = 0; i < 26; i++)
    {
        checked[i] = 0;
    }
    auto directory = this -> neighbours;
    std::queue<char> pipeline;
    pipeline.push(start);
    checked[start - 65] = 1;
    while(!pipeline.empty())
    {
        auto k = pipeline.front();
        pipeline.pop();
        std::cout << k << "\n----------------\n";
        for(auto i : neighbours[k - 65])
        {
            if(!checked[i - 65])
            {
                pipeline.push(i);
                checked[i - 65] = 1;
            }
        }
    }
    return;
}

int main()
{
    Graph g;
    g.graph_set();
    g.addedge('C', 'A');
    g.addedge('C', 'D');
    g.addedge('C', 'B');
    g.addedge('C', 'E');
    //g.addedge('C', 'F');
    g.addedge('A','D');
    g.addedge('A','B');
    g.addedge('B','A');
    g.addedge('B','E');
    g.addedge('D','A');
    g.addedge('E','B');
    g.addedge('F','C');
    g.addedge('D', 'F');
    g.explore();
    g.dfs('C');

    return 0;
}