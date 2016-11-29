#include<iostream>
#include<iomanip>
using namespace std;
#define max 200
#define inf 65535

int visited[max]; 
class Graph{
	public:
		int vertex_num;
		int edge_num;
		int vertexlabel[max];
		int matrix[max][max];
};
Graph*graph_create(int n) {
	Graph *graph = NULL; 
	if (graph == NULL)
	{
		graph = new Graph;
		graph->vertex_num =n;
	  for(int i=0;i<graph->vertex_num;i++){
		graph->vertexlabel[i]=i;
	  }
	  for(int i=0;i<=graph->vertex_num;i++){
		for(int j=0;j<=graph->vertex_num;j++){
			graph->matrix[i][j]=inf;
		}	
	  }
		return graph;
	}
}
void addEdge(Graph *graph,int v1, int v2,int weight){
	if (graph->matrix[v1][v2] == inf){
		graph->matrix[v1][v2] = weight; 
		graph->matrix[v2][v1] =weight;
    }
}

Graph* addVertex(Graph *graph,int L1){
        	graph->vertex_num++;
        	graph->vertexlabel[graph->vertex_num-1]=L1;
        	for(int i=0;i<graph->vertex_num;i++){
        	graph->matrix[L1][i]=inf;
			}
			return graph;
        }
        
int Djisktra(Graph*graph,int *previous, int start){
	int min,k,i,j,r;
	int distance[max];
	//initialize
	for(i=0;i<graph->vertex_num;i++){
		distance[i]=graph->matrix[start][i];
		previous[i]=-1;
		visited[i]=0;
		}
	distance[start]=0;
	visited[start]=1;
	for(j=0;j<graph->vertex_num;j++){//to all the nodes in the graph
        min=inf;  
        for(r=0;r<graph->vertex_num;r++){//find the shortest adjent node of start
           if(distance[r]<min && visited[r]==0)  
            {  
                min=distance[r];  
                k=r;  
            }  
        }
        if(min!=inf)visited[k]=true;//mark k has been visited;
        for(i=0;i<graph->vertex_num;i++){
		   if(visited[i]==false&&graph->matrix[k][i]!=inf){
               if(distance[i]>min+graph->matrix[k][i])//update when distance is smaller
               {  
                distance[i]=min+graph->matrix[k][i];  
                previous[i]=k;  
               }  
           }
        }  
    }  
    cout<<"display the shortest distance"<<endl;//display distance 
    
    for ( i = 0; i < graph->vertex_num; i++){
        cout << " shortest(" << graph->vertexlabel[start] << ", " << graph->vertexlabel[i] << ")=" << distance[i] << endl;
	}
    return *previous;
}

void display(Graph*graph){
	cout<<"matrix_graph"<<endl;
	cout<<"  ";
	cout<<endl;
	for(int i=0;i<graph->vertex_num;i++){
          for(int j=0;j<=graph->vertex_num;j++){
          	if(j == 0)
				cout << graph->vertexlabel[i]<<" " ;
			else
                cout<<graph->matrix[i][j-1]<<" ";
		  }
		  cout<<endl;
	}
}
int main(){
	int n,p;
	cout<<"input vertex number"<<endl;
	cin>>n;
	int start;
	cout<<"please enter start point"<<endl;
	cin>>start;
	int previous[max];
	Graph*g = graph_create(n);
	addEdge(g,0,1,1);
	addEdge(g,2,3,2);
	addEdge(g,2,4,3);
	addEdge(g,2,5,4);
	addEdge(g,2,8,5);
	addEdge(g,6,8,6);
	addEdge(g,6,7,7);
	addEdge(g,5,6,8);
	addEdge(g,4,7,9);
	addEdge(g,0,8,10);
	display(g);
	Djisktra(g,previous,start);
    cout<<"display the shortest path in reserve order"<<endl;//display the order 
    for(int i=0;i<g->vertex_num;++i) 
    { 
        cout<<start<<"->"<<i<<endl;
        cout<<i<<" ";
        p=i;
        while(previous[p]!=-1)
        {
            cout<<previous[p]<<" ";
            p=previous[p];
        }
        cout<<endl;
    } 

  return 0;                  
} 
