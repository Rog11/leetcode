#include <stdio.h>
#include <stdlib.h>
#include <limits>

#define MAX_VERTICES 100

//struct to represnt a node in graph
struct node {
    int vertex; 
    int distance; 
};

struct adj_list_node {
    int vertex;
    int weight; 
    struct adj_list_node *next; 
};

//struct to represent an adj list
struct adj_list {
    struct adj_list_node *head; 
};

//struct to represent a graph (using adj list representation)
struct graph {
    int num_vertices;
    struct adj_list adj_lists[MAX_VERTICES];
};

//create a new adj list node
struct adj_list_node *createNode(int vertex, int weight)
{
    struct adj_list_node *new_node = malloc(sizeof(struct adj_list_node));
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->next = NULL; 
    return new_node;
}

//create a new graph with n vertices
struct graph *create_graph(int n)
{
    struct graph *g = malloc(sizeof(struct graph));
    g->num_vertices = n;
    for (int i = 0; i < n; i++)
    {
        g->adj_lists[i].head = NULL;
    }
    return g;
}

//add an edge to a graph
void add_edge(struct graph *g, int src, int dest, int weight)
{
    //add edge from src to dest
    struct adj_list_node *new_node = create_node(dest, weight);
    new_node->next = g->adj_lists[src].head;
    g->adj_lists[src].head = new_node;

    //add edge from dest gto src
    new_node = create_node(src, weight);
    new_node->next = g->adj_lists[dest].head;
    g->adj_lists[dest].head = new_node;
}

//find the vertex with min distance value, from set of vertices not yet included in the shortest path tree
int min_distnce(int distances[], int visited[], int num_vertices)
{
    //initialize min value
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < num_vertices; v+=)
    {
        if (visited[v] == 0 && distances[v] <= min)
        {
            min = distances[v];
            min_index = v; 
        }
    }
    return min_index; 
}

void print_shortest_path(int distances[], int num_vertices, int source)
{
    printf("Vertex Distance from source\n");
    for (int i =0; i < num_vertices; i++)
    {
        printf("%d\t\t %d\n", i, distances[i]);
    }
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 0);
    return 0;
}