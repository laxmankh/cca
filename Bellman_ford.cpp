#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Edge{
    int source,destination,weight;
};
void bellman(vector<Edge> &eges,int numVertices,int source )
{
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;
    // Relax all edges repeatedly
    for(int i=0;i<numVertices-1;i++)
    {
        for (const Edge& it : eges) {
            if (distance[it.source] != INT_MAX && distance[it.source] + it.weight < distance[it.destination]) {
                distance[it.destination] = distance[it.source] + it.weight;
            }
    }
    }
    //check for negative cycle
    for(int i=0;i<numVertices-1;i++)
    {
        for(const Edge& it:eges)
        {
            if(distance[it.source]!=INT_MAX && distance[it.source]+it.weight<distance[it.destination])
            {
                cout<<"Graph contains negative weight cycle!";
            }
        }
    }
    // Print the shortest distances
    for (int i = 1; i <= numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }

}
int main()
{
    Edge obj;
    int numvertices,numeges;
    cout<<"enter the vertices and eges:";
    cin>>numvertices>>numeges;

    vector<Edge> eges(numeges);
    cout<<"ENter the source ,destination and weight:";
    for(int i=0;i<numeges;i++)
    {
        cin>>eges[i].source>>eges[i].destination>>eges[i].weight;
    }
    for (const Edge& it : eges) {
        cout<<&it<<"\n";
        cout << "Source: " << it.source << ", Destination: " << it.destination << ", Weight: " << it.weight << std::endl;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    bellman(eges,numvertices,source);
}