// ALGO : Breadth First Search ; SOURCE : Coreman ;

// 0 is assumed as source vertex ; for n nodes & m edges enter "n + 1" & "m" & then the egde description

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include<cstdio>
#include<queue>
#include<vector>
#include<climits>

#define MAX 2000

using namespace std ;

/* Attributes of a node of graph
  
	color : visited / non-visted status of a vertex
	dist  : distance of vertex from source vertex
	pre   :	predecessor of a vertex

*/
struct group
{
	int dist , pre , color ;		
} ;

// typedef struct group node ;

vector< int > v[MAX+1] ;
vector< group > v2(MAX+1) ;

int main( )
{
	int n , m , i , a , b , first , last ;
	
	scanf("%d %d",&n,&m) ;
	
	for( i = 0 ; i < m ; i++ )
	{
		scanf("%d %d",&a,&b) ;
		v[a].push_back( b ) ;
		v[b].push_back( a ) ;
	}
	
	for( i = 1 ; i < n ; i++ )		// Assuming 0 as source vertex
	{
		v2[i].color = 0 ;			// 0 : WHITE ; 1 : GREY ; 2 : BLACK
		v2[i].dist = INT_MAX ;
		v2[i].pre = 0 ;
	}
	
	/* 0 : Unvisted , 1 : Discovered but its adjacent vertices are not visited 
	   2 : All of its adjacent vertices are now discovered */

	v2[0].color = 1 ;				// Source vertex is discovered once
	v2[0].dist = 0 ;				// Distance of source vertex '0' from itself = 0
	v2[0].pre = 0 ;					// Source vertex has no predecessor
	
	queue< int > q ;
	
	q.push( 0 ) ;					// Enqueing source vertex in the queue
	
	while( !q.empty( ) )			// Initiating BFS untill queue is non-empty
	{
		a = q.front( ) ;
		q.pop( ) ;
		
		first = 0 ;
		last = v[a].end( ) - v[a].begin( ) ;
		
		printf("%d : ",a) ;			// Processing & Printing vertices
		for( i = 0 ; i < last ; i++ )
		{
			b = v[a][i] ;
			if( v2[b].color == 0 )
			{
				v2[b].color = 1 ;
				v2[b].dist = v2[a].dist + 1 ;
				v2[b].pre = a ;
				q.push( b ) ;
			}
			printf("%d ",b) ;
			v2[a].color = 2 ;
		}
		printf("\n") ;
	}
	
	scanf("%d",&i) ;
	
	return 0 ;
}
