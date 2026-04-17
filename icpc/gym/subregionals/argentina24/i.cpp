#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2005;
struct edge{
    int y;
    list<edge>::iterator rev;
    edge(int y):y(y){}
};
list<edge> g[MAXN];
void add_edge(int a, int b){
    // cout<<"add_edge "<<a<<" "<<b<<"\n"; 
    g[a].push_front(edge(b)); auto ia=g[a].begin();
    g[b].push_front(edge(a)); auto ib=g[b].begin();
    ia->rev=ib; ib->rev=ia; 
}
vector<int> p;
void go(int x){
    while(g[x].size()){
        int y=g[x].front().y;
        g[y].erase(g[x].front().rev);
        g[x].pop_front();
        go(y);
    }
    p.push_back(x);
}
vector<int> get_path(int x){
    p.clear();go(x);reverse(p.begin(),p.end());
    return p;
}

int main(){
    JET
    ll n,m; cin>>n>>m;
    vector<ll>deg(n+m),hay(n+m);
    char a[n][m];
    fore(i,0,n)fore(j,0,m){
        char c; cin>>c;
        a[i][j]=c;
        if(c=='.')add_edge(i,j+n),deg[i]^=1,deg[j+n]^=1,hay[i]=hay[j+n]=1;
    }
    ll q=0;
    fore(i,0,n+m)q+=deg[i];
    if(!(q==0||q==2)){
        cout<<"*\n";
        // cout<<"primero\n";
        return 0;
    }
    ll s=0;
    fore(i,0,n+m){
        if(q==2){
            if(deg[i])s=i;
        }
        else {
            if(hay[i])s=i;
        }
    }
    auto p=get_path(s);
    // cout<<s<<": ";
    // for(auto i:p)cout<<i<<" ";;cout<<endl;
    vector<ll>vis(n+m);
    for(auto i:p)vis[i]=1;
    ll flag=1;
    fore(i,0,n+m)if(hay[i])flag&=vis[i];
    if(!flag){
        cout<<"*\n";
        return 0;
    }
    vector<vv>res(n,vv(m));
    auto get_idx=[&](ll x, ll y)->ii{
        if(x>y)swap(x,y);
        return {x,y-n};
    };
    fore(i,0,SZ(p)-1){
        auto [x,y]=get_idx(p[i],p[i+1]);
        res[x][y]=i+1; //gdb
    }
    fore(i,0,n){
        fore(j,0,m)cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*

3 2
0 .
0 0
. .
4: 4 0 2 3 
/usr/include/c++/11/debug/vector:438:
In function:
    std::debug::vector<_Tp, _Allocator>::reference std::debug::vector<_Tp, 
    _Allocator>::operator[](std::debug::vector<_Tp, _Allocator>::size_type) 
    [with _Tp = long long int; _Allocator = std::allocator<long long int>; 
    std::debug::vector<_Tp, _Allocator>::reference = long long int&; std::
    debug::vector<_Tp, _Allocator>::size_type = long unsigned int]

Error: attempt to subscript container with out-of-bounds index -1, but 
container only holds 2 elements.

Objects involved in the operation:
    sequence "this" @ 0x599e3488e1e0 {
      type = std::debug::vector<long long, std::allocator<long long> >;
    }
Abortado (`core' generado)





otro: 



3 3
. 0 0
0 . .
. 0 .
5: 5 1 4 2 3 0 
5 0 0 
0 2 1 
4 3 0



*/