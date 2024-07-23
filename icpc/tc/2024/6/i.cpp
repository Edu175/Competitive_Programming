#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5;
ll uf[MAXN];
ll a[MAXN];
ll find(ll x){ return uf[x]<0?x:uf[x]=find(uf[x]);}
bool uni(ll x, ll b){
	x=find(x); b=find(b);
	if(x==b) return false;
	if(a[x]>a[b]) swap(x,b);
	uf[b]=x;
	return true;
}
int main(){
	JET
	mset(uf,-1);
	ll n,k,m; cin>>n>>k>>m;
	map <string,int> M;
	fore(i,0,n){
		string s; cin>>s;
		M[s]=i;
	}
	fore(i,0,n)cin>>a[i];
	fore(i,0,k){
		int x; cin>>x;
		int p; cin>>p; p--;
		fore(i,0,x-1) {
			int r; cin>>r;r--;
			uni(p,r);
		}
	}
	ll res=0;
	fore(i,0,m){
		string s; cin>>s;
		res+=a[find(M[s])];
		cout<<find(M[s])<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}