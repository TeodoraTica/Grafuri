#include <iostream>
#include"graph.h"

using namespace std;

int main()
{
    Graph<int> g;
    Graph<char> G;

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);


    g.printNeighLists();

    g.dfs(1);
    g.bfs(1);

    cout<<endl<<"remove (1, 2)"<<endl;
    g.removeEdge(1, 2);
    g.printNeighLists();

    cout<<endl<<"remove 3"<<endl;
    g.removeVertex(3);
    g.printNeighLists();

    /*
    G.addEdge('A', 'B');
    G.addEdge('A', 'C');
    G.addEdge('A', 'D');
    G.addEdge('B', 'E');
    G.addEdge('B', 'F');
    G.addEdge('C', 'D');
    G.addEdge('C', 'G');
    G.addEdge('D', 'H');
    G.addEdge('D', 'G');
    G.addEdge('E', 'F');
    G.addEdge('F', 'G');
    G.addEdge('E', 'I');

    G.printNeighLists();

    G.dfs('I');
    G.bfs('I');
    */


    return 0;
}

