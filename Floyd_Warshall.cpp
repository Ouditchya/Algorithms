// ALGO : Floyd–Warshall algorithm ; SOURCE : Wikipedia , http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm ;

// Distance between vertices is given in the form of 2D Matrix "dist"

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include<cstdio>

using namespace std ;

int main( )
{
  	int t , n , r , i , j , k , cs ;
	
	for( scanf("%d",&t) , cs = 1 ; cs <= t ; cs++ )
	{
		scanf("%d",&n) ;
		
		int dist[n+1][n+1] ;

		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
				scanf("%d",&dist[i][j]) ;
		}
		
		for( k = 1 ; k <= n ; k++ )
		{
			for( i = 1 ; i <= n ; i++ )
			{
				for( j = 1 ; j <= n ; j++ )
				{
					if( dist[i][k] + dist[k][j] < dist[i][j] )
						dist[i][j] = dist[i][k] + dist[k][j] ;
				}
			}
		}
		
		printf("New dist matrix- \n\n") ;
    		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
				printf("%d ",dist[i][j]) ;
			printf("\n") ;
		}
		printf("\n\n") ;
		
		scanf("%d",&r) ;  // No. of Queries
		
		for( k = 1 ; k <= r ; k++ )
		{
			scanf("%d %d",&i,&j) ;
			printf("%d\n",dist[i][j]) ;
		}
	}
	
	return 0 ;
}
