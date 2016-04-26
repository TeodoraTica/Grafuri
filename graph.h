#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class Graph{

private:

    unordered_map<T, vector<T> > nodesNeighLists; // Graful se retine prin liste de vecini

public:

    void addEdge(const T& firstNode, const T& secondNode)
    {
        nodesNeighLists[firstNode].push_back(secondNode);
        nodesNeighLists[secondNode].push_back(firstNode);
    }

    typename vector<T>::iterator findNeighbour(typename vector<T>::iterator first, typename vector<T>::iterator last, const T& node)
    {
        while(first != last)
        {
            if(*first == node)
            {
                return first;
            }
            ++first;
        }

        return last;
    }

    void removeEdge(const T& firstNode, const T& secondNode)
    {
        typename vector<int>::iterator it = findNeighbour(nodesNeighLists[firstNode].begin(), nodesNeighLists[firstNode].end(),  secondNode);

        if(it == nodesNeighLists[firstNode].end())
        {
            cout<<"Edge does not exist."<<endl;
            return ;

        }
        else
        {
            nodesNeighLists[firstNode].erase(it);
        }

        it = findNeighbour(nodesNeighLists[secondNode].begin(), nodesNeighLists[secondNode].end(), firstNode);

        if(it == nodesNeighLists[secondNode].end())
        {
            cout<<"Edge does not exist."<<endl;
            return ;

        }
        else
        {
            nodesNeighLists[secondNode].erase(it);
        }
    }

    void removeVertex(const T& node)
    {
        typename unordered_map<T, vector<T> >::iterator itG = nodesNeighLists.find(node);

        if(itG == nodesNeighLists.end())
        {
            cout<<"Vertex does not exist.";
        }
        else
        {
            nodesNeighLists.erase(node);

            if(!nodesNeighLists.empty())
            {
                for(itG = nodesNeighLists.begin(); itG != nodesNeighLists.end(); ++itG)
                {
                    typename vector<T>::iterator it = findNeighbour(itG->second.begin(), itG->second.end(), node);
                    if(it != itG->second.end())
                    {
                        itG->second.erase(it);
                    }
                }
            }
        }
    }

    void bfs(const T& startNode)
    {

        T currentNode, node;
        unordered_map<T, bool> visited;
        typename unordered_map<T, vector<T> >::iterator itG;
        typename vector<T>::iterator it;
        queue<T> q;

        for (itG = nodesNeighLists.begin(); itG != nodesNeighLists.end(); ++itG)
        {
            visited[itG->first] = false;
        }

        q.push(startNode);

        while (!q.empty())
        {
            currentNode = q.front();
            q.pop();
            cout<<currentNode<<" ";

            for (it = nodesNeighLists[currentNode].begin(); it != nodesNeighLists[currentNode].end(); ++it)
            {
                node = *it;
                if (!visited[node])
                {
                    visited[node] = true;
                    q.push(node);
                }
            }
            visited[currentNode] = true;
        }
        cout<<endl;
    }

    void dfs(const T& startNode)
    {
        T node;
        unordered_map<T, bool> visited;
        typename unordered_map<T, vector<T> >::iterator itG;
        typename vector<T>::iterator it;
        stack<T> s;

        for (itG = nodesNeighLists.begin(); itG != nodesNeighLists.end(); ++itG)
        {
            visited[itG->first] = false;
        }

        s.push(startNode);

        while(!s.empty())
        {

            node = s.top();
            s.pop();

            if(!visited[node])
            {
                cout<<node<<' ';

                visited[node] = true;

                for(it = nodesNeighLists[node].begin(); it !=  nodesNeighLists[node].end(); ++it)
                {
                    s.push(*it);
                }
            }
        }

        cout<<endl;

    }

    void printNeighLists()
    {
        typename unordered_map<T, vector<T> >::iterator itG;
        typename vector<T>::iterator it;

        for(itG = nodesNeighLists.begin(); itG != nodesNeighLists.end(); ++itG)
        {
            cout<<itG->first<<": ";

            for(it = itG->second.begin(); it != itG->second.end(); ++it)
            {
                cout<<*it<<' ';
            }

            cout<<endl;

        }
    }

};



#endif // GRAF_H

