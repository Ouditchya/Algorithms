// ALGO : Topological Sort ; SOURCE : Coreman ;

// 0 is assumed as source vertex ; for n nodes & m edges

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include <cstdio>
#include <vector>

#define MAX 10100

using namespace std ;

struct node
{
  int color , pre , d , f ;
} ;

vector< node > vec( MAX ) ;
vector< int > adj[MAX] ;
vector< int > ans ;

int n , time = 0 ;

void dfs( ) ;
void dfs_visit( int u ) ;

int main( )
{
	int i , m , u , v ;

	scanf("%d %d",&n,&m) ;

	for( i = 0 ; i < m ; i++ )
	{
		scanf("%d %d",&u,&v) ;
		adj[v].push_back( u ) ;
	}

	dfs( ) ;
	m = ans.end( ) - ans.begin( ) ;
	for( i = 0 ; i < m ; i++ )
		printf("%d ",ans[i]) ;
		
	ans.clear( ) ;
	vec.clear( ) ;
	for( i = 1 ; i <= n ; i++ )
		adj[i].clear( ) ;

	return 0 ;
}

inline void dfs( )
{
	int i ;

	for( i = 1 ; i <= n ; i++ )
		vec[i].color = vec[i].pre = 0 ;

	for( i = 1 ; i <= n ; i++ )
	{
		if( !vec[i].color )
			dfs_visit( i ) ;
	}
}

inline void dfs_visit( int u )
{
	int i , v , last = adj[u].end( ) - adj[u].begin( ) ;

	vec[u].d = ++time ;
	vec[u].color = 1 ;

	for( i = 0 ; i < last ; i++ )
	{
		v = adj[u][i] ;

		if( !vec[v].color )
		{
			vec[v].pre = u ;
			dfs_visit( v ) ;
		}
	}

	vec[u].color = 2 ;
	vec[u].f = ++time ;
	ans.push_back( u ) ;
}
