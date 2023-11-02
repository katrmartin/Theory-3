#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

//c++ code

struct Edge
{
    int v, w;
    Edge(int v = -1, int w = -1) : v(v), w(w) { }
};

//adjacency lists graph ADT

class SparseMultiGRAPH
{
    int Vcnt, Ecnt; bool digraph;
    struct node
    {
        int v; node* next;
        node(int x, node* t) { v = x; next = t; }
    };
    typedef node* link;
    vector <link> adj;
    public:
        SparseMultiGRAPH(int V, bool digraph = false) :
            adj(V), Vcnt(V), Ecnt(0), digraph(digraph)
            { adj.assign(V, 0); }
        int V() const { return Vcnt; }
        int E() const { return Ecnt; }
        bool directed() const { return digraph; }
        void insert (Edge e)
        {
            int v = e.v, w = e.w;
            adj[v] = new node(v, adj[v]);
            if (!digraph) adj[v] = new node (v, adj[w]);
            Ecnt++;
        }
        void remove(Edge e);
        bool edge(int v, int w) const;
        class adjIterator;
        friend class adjIterator;

//graph generator (randon edges)

//generates random pairs of integers between 0 and V-1
//to add random edges to a graph


    static void graphGenerator(SparseMultiGRAPH &G, int E)
{
    double p = 2.0*E/G.V()/G.V()-1;
    for (int i = 0; i < G.V(); i++)
    {
        for (int j = 0; j < i; j++)
            if (rand() < p*RAND_MAX)
                G.insert(Edge(i, j));
    }
}

//graph generator (random graph) 

static void randG(SparseMultiGRAPH &G, int E)
{
    double p = 2.0*E/G.V()/(G.V()-1);
    for (int i = 0; i < G.V(); i++)
        for (int j = 0; j < i; j++)
            if (rand() < p*RAND_MAX)
                G.insert(Edge(i, j));
}


};

//iterator for adj lists

class SparseMultiGRAPH::adjIterator
{
    const SparseMultiGRAPH &G;
    int v;
    link t;
public:
    adjIterator(const SparseMultiGRAPH &G, int v) :
        G(G), v(v) {t=0;}
    int beg()
    {
        t = G.adj[v]; return t ? t->v : -1; 
    }
    int nxt()
    {
        if (t) t = t->next; return t ? t->v : -1;
    }
    bool end() { return t == 0; }
};

//adjacency matrix graph ADT

/*
class adjGRAPH
{
    int Vcnt, Ecnt; bool digraph;
    vector <vector <bool> > adj;

public:
    adjGRAPH(int V, bool digraph = false) :
        adj(V), Vcnt(V), Ecnt(0), digraph(digraph)
        {
            for (int i = 0; i < V; i++) {
                adj[i].assign(V, false);
            }
        }

    int V() const { return Vcnt; }

    int E() const { return Ecnt; }

    bool directed() const { return digraph; }

    void insert (Edge e)
    {
        int v = e.v;
        int w = e.w;
        if (adj[v][w] == false) Ecnt++;
            adj[v][w] = true;
        if (!digraph) adj[v][w] = true;
    }
    void remove (Edge e)
    {
        int v = e.v;
        int w = e.w;
        if (adj[v][w] == true) Ecnt--;
            adj[v][w] = false;
        if (!digraph) adj[v][w] = false;
    }
    bool edge(int v, int w) const { return adj[v][w]; }
};
*/

// C code:

// Graph ADT interface

typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);
typedef struct graph *Graph;
Graph GRAPHinit (int);
void GRAPHinsertE (Graph, Edge);
void GRAPHremoveE (Graph, Edge);
int GRAPHedges (Edge [], Graph G);
Graph GRAPHcopy (Graph);
void GRAPHdestroy (Graph);

typedef struct node *link;
struct node { int v; link next; };
struct graph (int V; int E; link *adj; );
link NEW (int v, link next)
    {
        link x = malloc (sizeof *x);
        x->v = v;
        x->next = next;
        return x;
    }
Graph GRAPHinit (int V)
{
    int v;
    Graph G = malloc (sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = malloc (V*sizeof (link));
    for (v=0; v<V; v++) G->adj[v] = NULL;
    return G;
}
void GRAPHinsertE (Graph G, Edge e)
{
    int v = e.v;
    int w = e.w;
    G->adj[v] = NEW (w, G->adj[v]);
    G->adj[w] = NEW (v, G->adj[w]);
    G->E++;
}
//void GRAPHremoveE (Graph, Edge);
int GRAPHedges (Edge a[], Graph G)
{
    int v, E=0;
    link t;
    for (v = 0; v < G->V; v++)
        for (t = G->adj[v]; t != NULL; t = t->next)
            if (v < t->v) a[E++] = EDGE (v, t->v);
    return E;
}
Graph GRAPHcopy (Graph);
void GRAPHdestroy (Graph);



int main() {
    return 0;
}