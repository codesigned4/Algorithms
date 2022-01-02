#include <stdio.h>
#include <stdbool.h>

#define V 40
 
//My algorithm determines whether the directed graph contains a simple cycle of odd length or not.We can think that it controls graph is bipartite or not.The 
//running time of your algorithm should be O(n+m) where n is the number of vertices and m 
//is the number of edges contained in the graph. 
bool MyGraph(int Graph[][V],int color[],int p, int c,int len){
     
    if(color[p] != -1 && color[p] !=c)
        return false;
         
    
    // color this pos as c and all its neighbours and 1-c
    color[p] = c;
    bool ans = true;
    
    for(int i=0;i<len;i++){
    
        if(Graph[p][i]){
    
            if(color[i] == -1)
                ans &= MyGraph(Graph,color,i,1-c,len);
                 
            if(color[i] !=-1 && color[i] != 1-c)
                return false;
        }
        if (!ans)
            return false;
    }
     
    return true;
}
 
bool chechkBipartite(int G[][V],int size){
    
    int color[size];
    
    for(int i=0;i<size;i++)
        color[i] = -1;
         
    //start is vertex 0;
    int pos = 0;
    
    // two colors 1 and 0
    return MyGraph(G,color,pos,1,size);
     
}
 
int main()
{
      int size=0,i=0,j=0,element=0;
	   
	   scanf("%d",&size);
	   int G[size][size]; 
	   
	   
	   for(i=0;i<size;i++){
	   	for(j=0;j<size;j++){
	   		scanf("%d",&element);
	   		G[i][j]=element;
	   		
	   	}
	   }
	   
	   
    chechkBipartite(G,size) ? printf("true") : printf("false");
    
    return 0;
}
