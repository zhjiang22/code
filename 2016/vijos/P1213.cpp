/*
P121380人环游世界 非上下界费用流解法：
首先把每个点拆成两个，分别表示来源跟去向，用wi,ui表示，那么由于每个点会有vi个人经过，那么连边(S,wi,vi,0),(ui,T,vi,0)（(u,v,f,c)表示从u连边到v，流量f，费用c），那么对于每条费用为pi的航线(s,t)就有连边(ws,ut,inf,pi),又由于有些人可以直接在某个城市出发，那么另加一个点k，连边(S,k,m,0),对于每个城市i,连边(k,ui,inf,0)，然后跑一次最小费用最大流，那么mincost就是答案了。。。（这算是经典模型了吧。。。）
zkw费用流写渣了。。。好慢好慢：
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std ;

#define MAXN 210
#define inf 0x7fffffff

struct network {

    int S , T ;

    struct edge {
        edge *next , *pair ;
        int t , f , c ;
    } *head[ MAXN ] ;

    network(  ) {
        memset( head , 0 , sizeof( head ) ) ;
    }

    void Add( int s , int t , int f , int c ) {
        edge *p = new( edge ) ;
        p -> t = t , p -> f = f , p -> c = c , p -> next = head[ s ] ;
        head[ s ] = p ;
    }

    void AddEdge( int s , int t , int f , int c ) {
        Add( s , t , f , c ) , Add( t , s , 0 , - c ) ;
        head[ s ] -> pair = head[ t ] , head[ t ] -> pair = head[ s ] ;
    }

    int dist[ MAXN ] , slack[ MAXN ] , cost ;
    bool f[ MAXN ] ;

    int aug( int v , int flow ) {
        if ( v == T ) {
            cost += flow * dist[ S ] ; 
            return flow ;
        }
        f[ v ] = true ;
        int rec = 0 ;
        for ( edge *p = head[ v ] ; p ; p = p -> next ) if ( p -> f && ! f[ p -> t ] ) {
            if ( dist[ v ] == dist[ p -> t ] + p -> c ) {
                int ret = aug( p -> t , min( flow - rec , p -> f ) ) ;
                p -> f -= ret , p -> pair -> f += ret ;
                if ( ( rec += ret ) == flow ) return flow ;
            } else slack[ p -> t ] = min( slack[ p -> t ] , dist[ p -> t ] + p -> c - dist[ v ]  ) ;
        }
        return rec ;
    }

    bool relabel(  ) {
        int delta = inf ;
        for ( int i = 0 ; i ++ < T ; ) if ( ! f[ i ] ) delta = min( delta , slack[ i ] ) ;
        if ( delta == inf ) return false ;
        for ( int i = 0 ; i ++ < T ; ) if ( f[ i ] ) dist[ i ] += delta ;
        return true ;
    }

    int costflow(  ) {
        cost = 0 ;
        memset( dist , 0 , sizeof( dist ) ) ;
        do {
            for ( int i = 0 ; i ++ < T ; ) slack[ i ] = inf ;
            do {
                memset( f , false , sizeof( f ) ) ;
            } while ( aug( S , inf ) ) ;
        } while ( relabel(  ) ) ;
        return cost ;
    }

} net ;

int n , m , v[ MAXN ][ 2 ] , V = 0 ;

int main(  ) {
    scanf( "%d%d" , &n , &m ) ;
    for ( int i = 0 ; i ++ < n ; ) v[ i ][ 0 ] = ++ V , v[ i ][ 1 ] = ++ V ;
    ++ V ; net.S = ++ V ; net.T = ++ V ;
    net.AddEdge( net.S , V - 2 , m , 0 ) ;
    for ( int i = 0 ; i ++ < n ; ) {
        int x ; scanf( "%d" , &x ) ;
        net.AddEdge( net.S , v[ i ][ 0 ] , x , 0 ) ;
        net.AddEdge( v[ i ][ 1 ] , net.T , x , 0 ) ;
        net.AddEdge( V - 2 , v[ i ][ 1 ] , inf , 0 ) ;
    }
    for ( int i = 0 ; i ++ < n - 1 ; ) {
        for ( int j = i ; j ++ < n ; ) {
            int x ; scanf( "%d" , &x ) ;
            if ( x != -1 ) {
                net.AddEdge( v[ i ][ 0 ] , v[ j ][ 1 ] , inf , x ) ;
            }
        }
    }
    printf( "%d\n" , net.costflow(  ) ) ;
    return 0 ;
}