#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

//node in adj list
struct adj_list_node {
    int vertex; 
    struct adj_list_node *next;
};

struct adj_list {
    struct adj_list_node *head; 
};

//definition of graph
struct graph {
    int num_vertices;
    struct adj_list adj_lists[MAX_VERTICES];
};

//create new node in adj list
struct adj_list_node *create_node(int v)
{
    struct adj_list_node *new_node = malloc(sizeof(struct adj_list_node));
    new_node-> vertex = v;
    new_node->next = NULL;
    return new_node; 
}

//function to create a new graph with n vertices
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

//function to ad an edge to a graph
void add_edge(struct graph *g, int src, int dest)
{
    struct adj_list_node *new_node = create_node(dest);
    new_node->next = g->adj_lists[src].head;
    g->adj_lists[src].head = new_node; 

    //add an edge from dest to src graph(for undirected graph)
    new_node = create_node(src);
    new_node->next = g->adj_lists[dest].head;
    g->adj_lists[dest].head = new_node;
}

void enqueue(int queue[], int vertex, int *rear)
{
    queue[*rear] = vertex;
    (*rear)++;
}

int dequeue(int queue[], int *front)
{
    (*front)++;
    return queue[*front-1];
}

int is_empty(int *front, int *rear)
{
    return *front == *rear;
}

//function to perform BFS
//function to perform BFS
void bfs(struct graph *g, int start_vertex)
{
    //create a queue to store vertices that need to be visted 
    int queue[MAX_VERTICES];
    int front = 0; 
    int rear = 0;

    //create an array to store vistied
    int visited[MAX_VERTICES];
    for (int i = 0; i < g->num_vertices; i++)
    {
        visited[i] = 0;
    }

    //mark the start vertex as visited and enqueue it
    visited[start_vertex] = 1; 
    enqueue(queue, start_vertex, &rear);

    //perform bread first search
    while (front < rear)
    {
        //dequeue front vertex
        int current_vertex = dequeue(queue, &front);

        //print vertex
        printf("%d", current_vertex);

        //iterate through the adj list of current vertex
        struct adj_list_node *current_node = g->adj_lists[current_vertex].head;
        while (current_node != NULL)
        {
            //if vertex has not been visited, mark it as visited and enqueue it
            if (!visited[current_node->vertex])
            {
                enqueue(queue, current_node->vertex, &rear);
                visited[current_node->vertex] = 1; 
            }
            current_node = current_node->next;
        }
    }
}

// void bfs(struct graph *g, int start_vertex)
// {
//     //create a queue to store vertices that need to be visted 
//     int queue[MAX_VERTICES];
//     int front = 0; 
//     int rear = 0;

//     //create an array to store vistied
//     int visited[MAX_VERTICES];
//     for (int i = 0; i < g->num_vertices; i++)
//     {
//         visited[i] = 0;
//     }

//     //mark the start vertex as visited and enqueue it
//     visited[start_vertex] = 1; 
//     enqueue(queue, start_vertex, &rear);

//     //perform bread first search
//     while (front < rear)
//     {
//         //dequeue front vertex
//         int current_vertex = dequeue(queue, &front);

//         //print vertex
//         printf("%d", current_vertex);

//         //enqueue unvisited of the vertex
//         struct adj_list_node *node = g->adj_lists[current_vertex].head;
//         while (node != NULL)
//         {
//             //add current node to queue
//             enqueue(queue, node->vertex);
//             visited[node->vertex] = 1;

//             node = node->next;
//         }

//         //iterate through the adj list of current
//         while(!is_empty(queue))
//         {
//             int current_vertex = dequeue(queue);

//             printf("Visited %d\n", current_vertex);

//             //iterate through the adj list of current vertex
//             struct adj_list_node *current_node = g->adj_lists[current_vertex].head;
//             while (current_node != NULL)
//             {
//                 //if vertex has not been visited, mark it as visited
//                 if (!visited[current_node->vertex])
//                 {
//                     enqueue(queue, current_node->vertex);
//                     visited[current_node->vertex] = 1; 
//                 }

//                 current_node = current_node->next;
//             }
//         }

//     }
// }