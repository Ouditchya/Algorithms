// ALGO : Knapsack Problem ; SOURCE : Wikipedia , https://en.wikipedia.org/wiki/Knapsack_problem#0.2F1_Knapsack_Problem ;

// Tested, Working. :)

// For any clarifications, contact me at osinha6792@gmail.com

#include <cstdio>
#include <cstring>
 
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
 
inline int max( int a , int b )
{
    return ( a > b ) ? a : b ;
}
 
int dp[2][2100] ;
 
int main( )
{
        int i , j , p , n , K ;
 
        K = inp( ) ;
        n = inp( ) ;
 
        int val[n] , wt[n] ;
 
        for( i = 0 ; i < n ; i++ )
        {
                wt[i] = inp( ) ;
        val[i] = inp( ) ;
        }
 
        memset( dp , 0 , sizeof( dp ) ) ;
 
        for( i = 0 ; i < n ; i++ )
        {
                p = i & 1 ;
 
                for( j = 1 ; j < wt[i] ; j++ )
                        dp[p][j] = dp[1-p][j] ;
 
                for( j = wt[i] ; j <= K ; j++ )
                        dp[p][j] = max( dp[1-p][j] , val[i] + dp[1-p][j-wt[i]] ) ;
        }
 
        printf("%d\n",dp[1-(n&1)][K]) ;
 
        return 0 ;
}
