#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e4+5;

vector<ll> g[MAXN];
ll ap[MAXN];
bool vis[MAXN];
void dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i]){
			vis[i]=1;
			dfs(i);
		}
	}
}

int main(){
	ifstream cin;
	ofstream cout;
	cin.open("arbol.in", ios::in);
	cout.open("arbol.out", ios::out);
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb(b);
		ap[b]++;
	}
	vector<ll>r1,r2,r3;
	fore(i,0,n){
		if(ap[i]==0)r1.pb(i);
		if(ap[i]>=2)r2.pb(i);
	}
	if(SZ(r1)==1&&SZ(r2)==0)cout<<"Si "<<r1[0]+1<<"\n";
	else{
		cout<<"No\n";
		if(SZ(r1)==0)cout<<"0\n";
		else{
			for(auto i:r1)cout<<i+1<<" ";
			cout<<"\n";
		}
		if(SZ(r2)==0)cout<<"0\n";
		else{
			for(auto i:r2)cout<<i+1<<" ";
			cout<<"\n";
		}
		if(SZ(r1)!=1)cout<<"0\n";
		else{
			vis[r1[0]]=1;
			dfs(r1[0]);
			fore(i,0,n)if(!vis[i])r3.pb(i);
			if(SZ(r3)==0)cout<<"0\n";
			else{
				for(auto i:r3)cout<<i+1<<" ";
				cout<<"\n";
			}
		}
	}
	return 0;
}
