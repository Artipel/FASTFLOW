#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

struct Node{
    int distanceFromRoot;
    map<int, int> edges;

    void addEdge(int u, int value){
        edges[u] += value;
    }
};

struct Graph{
    vector<Node> vertices;

    Graph(int size){
        vertices = vector<Node>(size);
    }

    void addEdge(int v, int u, int value){
        if(v == u)
            return;
        vertices[v].addEdge(u, value);
        vertices[u].addEdge(v, value);
    }

    void BFS(int root){
        list<int> *q = new list<int>();
        bool visited[vertices.size()];
        for(int i = 0; i < vertices.size(); ++i)
            visited[i] = false;
        visited[root] = true;
        vertices[root].distanceFromRoot = 0;
        q->push_back(root);
        //recursiveBFS(bfsqueue, visited);
        int v;
        while(!q->empty()) {
            v = q->front();
            q->pop_front();
            for (auto i = vertices[v].edges.begin(); i != vertices[v].edges.end(); ++i) {
                if (visited[i->first] == false) {
                    q->push_back(i->first);
                    vertices[i->first].distanceFromRoot = vertices[v].distanceFromRoot + 1;
                    visited[i->first] = true;
                }
            }
        }
    }

    Graph constructGl(int s, int t, int size){
        BFS(s);
        Graph gl(size);
        for(int i = 0; i < size; ++i){
            for(auto e = vertices[i].edges.begin(); e != vertices[i].edges.end(); ++e){
                if(vertices[e->first].distanceFromRoot == vertices[i].distanceFromRoot + 1) {
                    gl.addEdge(i, e->first, e->second);
                    gl.vertices[e->first].distanceFromRoot = vertices[e->first].distanceFromRoot;
                }
            }
        }
        return gl;
    }
};

struct Path{

    list<Node *> verts;

    long reducePath(){
        long min = LONG_MAX;
        for(auto iter = verts.begin(); iter != (--verts.end()); ++iter){
            iter->edges[]
        }
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int size = 4;
    long long flow = 0;
    Graph graph = Graph(size + 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 1);
    graph.addEdge(1, 4, 2);

    Graph gl = graph.constructGl(1, 3, size+1);
    Path path = findPathIn(gl);
    flow += path.reducePath();
    cout<<1;

    return 0;
}