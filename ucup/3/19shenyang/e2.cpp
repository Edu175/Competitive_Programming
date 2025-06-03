#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<=jet;i++)
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

vector<ii> mov = {{1,-1},{2,-1},{4,-1},{8,-1},{3,-1},{12,-1},{5,-1},{10,-1},{15,-1}};
ll m; 
vector<ii> g[1<<20];


int main(){
	JET
	cin>>m;
	ll x,y,z; cin>>x;
	fore(i,0,4) mov[i].snd = x;
	cin>>y;
	if(x*2<y) y=x*2;
	fore(i,4,6) mov[i].snd = y;
	cin>>z;
	if(x*2<z) z=x*2;
	fore(i,6,8) mov[i].snd = z;
	cin>>x;
	if(min(y,z)*2<x) x = min(y,z)*2;
	mov[8].snd = x;
	
	
	return 0;
}