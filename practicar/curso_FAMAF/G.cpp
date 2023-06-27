#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=500*500+5;
ll n,m;
vector<ll>dir;
char a[MAXN];
ll vis[MAXN];
ll s,k,c;
bool allowed(ll x, ll d){
	if(x%m==0&&d==1)return 0;
	if(x%m==m-1&&d==3)return 0;
	x+=dir[d];
	if(x<0||x>=n*m)return 0;
	if(a[x]=='#')return 0;
	if(vis[x])return 0;
	if(c>=s-k)return 0;
	return 1;
}
void dfs(ll x){
	vis[x]=1,c++,a[x]='.';
	fore(d,0,4)if(allowed(x,d))dfs(x+dir[d]);
}
int main(){FIN;
	cin>>n>>m>>k;
	dir={-m,-1,m,1};
	fore(i,0,n)fore(j,0,m){
		cin>>a[i*m+j];
		if(a[i*m+j]=='.')s++,a[i*m+j]='X';
	}
	fore(i,0,n*m)if(a[i]=='X'){
		dfs(i);
		break;
	}
	fore(i,0,n){
		fore(j,0,m)cout<<a[i*m+j];
		cout<<"\n";
	}
	return 0;
}
