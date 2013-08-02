// ALGO : Knapsack Problem ; SOURCE : Wikipedia , https://en.wikipedia.org/wiki/Knapsack_problem#0.2F1_Knapsack_Problem ;

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include <cstdio>

using namespace std ;

#define get getchar_unlocked
 
inline int inp( )
{
    int n = 0 , s = 1 ;
    char p = get( ) ;
    if( p == '-' )
        s = -1 ;
    while( ( p < '0' || p > '9' ) && p != EOF && p != '-' )
        p = get( ) ;
    if( p == '-' )
        s = -1 , p = get( ) ;
    while( p >= '0' && p <= '9' )
    {
        n = ( n << 3 ) + ( n << 1 ) + ( p - '0' ) ;
        p = get( ) ;
    }
    return n * s ;
}

inline int max( int a , int b ) { return ( a > b )? a : b ; }

int knapSack( int W , int wt[] , int val[] , int n )
{
   int i , w , K[n+1][W+1] ;
   
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if( i == 0 || w == 0 )
                K[i][w] = 0 ;
           else if(wt[i-1] <= w)
                K[i][w] = max( val[i-1] + K[i-1][w-wt[i-1]] , K[i-1][w] ) ;
           else
                K[i][w] = K[i-1][w];
       }
   }
   
   return K[n][W] ;
}

int main( )
{
  	int W , n , i ;
    
  	W = inp() ;
	n = inp() ;
	// scanf("%d%d",&W,&n) ;
	
	int wt[n] , val[n] ;
	
	for( i = 0 ; i < n ; i++ )
	{
		wt[i] = inp() ;
		val[i] = inp() ;
		// scanf("%d%d",&wt[i],&val[i]) ;
	}
	
    printf("%d",knapSack( W , wt , val , n )) ;
	
    return 0 ;
}
