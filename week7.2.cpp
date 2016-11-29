#include<iostream>
#include<stack>
#include<queue>

using namespace std;

#define max 20

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
			graph->matrix[i][j]=0;
		}	
	  }
		return graph;
	}
}

void addEdge(Graph *graph,int v1, int v2){
	if (graph->matrix[v1][v2] == 0){
		graph->matrix[v1][v2] = 1; 
		graph->matrix[v2][v1] =1;
    }
}

Graph* addVertex(Graph *graph,int L1){
        	graph->vertex_num++;
        	graph->vertexlabel[graph->vertex_num-1]=L1;
        	for(int i=0;i<graph->vertex_num;i++){
        	graph->matrix[L1][i]=0;
			}
			return graph;
        }


void BFSTraversal(Graph*graph,int v){
	queue<int> q;
	int q_top;
	for(int i=0;i<max;i++){
		visited[i]=0;
	}
	cout<<"BFS"<<endl;
	cout<<graph->vertexlabel[v]<<" ";
    visited[v]=1;
    for (int i=0;i<graph->vertex_num;i++ ) {
        if(graph->matrix[v][i]==1&&visited[i]==0){
           q.push(i);
           visited[i]= 1;
         }
     }
    while(!q.empty()){
         q_top = q.front();//pointer top
         q.pop();
         cout<<graph->vertexlabel[q_top]<<" ";
         for(int i=0; i<graph->vertex_num;i++){
             if(graph->matrix[q_top][i]==1&&visited[i]==0){
                 visited[i]=1;
				 q.push(i);
                 
             }
         }

     }
	 cout<<endl;     
} 


void DFSTraversal(Graph*graph,int v){
	stack<int> s;
	int s_top;
	for(int i=0;i<max;i++){
		visited[i]=0;
	}
	cout<<"DFS"<<endl;
	cout<<graph->vertexlabel[v]<<" ";
    visited[v]=1;
    for (int i=0;i<graph->vertex_num;i++ ) {
        if(graph->matrix[v][i]==1&&visited[i]==0){
           s.push(i);
         }
     }
    while(!s.empty()){
         s_top = s.top();
		 s.pop();//pointer top
         if(visited[s_top]==0){
           cout<<graph->vertexlabel[s_top]<<" ";
		   visited[s_top]=1;
		 }
         for(int i=0; i<graph->vertex_num;i++){
             if(graph->matrix[s_top][i]==1&&visited[i]==0){
				 s.push(i);  
             }
         }

    }
	cout<<endl;    
} 

void display(Graph*graph){
	cout<<"matrix_graph"<<endl;
	cout<<"  ";
	for(int i=0;i<graph->vertex_num;i++){
		cout<<i<<" ";}
	cout<<endl;
	for(int i=0;i<graph->vertex_num;i++){
          for(int j=0;j<=graph->vertex_num;j++){
          	if(j == 0)
				cout << graph->vertexlabel[i] << " ";
			else
                cout<<graph->matrix[i][j-1]<<" ";
		  }
		  cout<<endl;
	}
}

int main(){
	int n,m;
	cout<<"input vertex number"<<endl;
	cin>>n;
	
	Graph*g = graph_create(n);
	addEdge(g,0,1);
	addEdge(g,2,3);
	addEdge(g,2,4);
	addEdge(g,2,5);
	addEdge(g,2,8);
	addEdge(g,6,8);
	addEdge(g,6,7);
	addEdge(g,5,6);
	addEdge(g,4,7);
	addEdge(g,0,8);
	display(g);
	DFSTraversal(g,0);
    BFSTraversal(g,0);
  return 0;                  
} 
