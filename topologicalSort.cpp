//  Topological Sort
// only in a DAG (Directed Acyclic Graph)

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

void topological(vector<list<int> >graph,vector<bool>&visited,stack<int>&st,int v) {
    visited[v] = true;

    for(auto x: graph[v]) {
        if(!visited[x]) {
            topological(graph,visited,st,x);
        }
    }

    st.push(v);
}

void topologicalSort(vector<list<int> > graph) {
    stack<int> st;
    vector<bool>visited(graph.size(),false);

    for(int i=0 ; i<graph.size() ; i++) {
        if(!visited[i]) {
            topological(graph,visited,st,i);
        }
    }

    while(!st.empty()) {
        cout<<st.top()<<"  ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    vector<list<int> > graph;
    int V = 6;
    graph.resize(V);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    topologicalSort(graph);

    return 0;
}