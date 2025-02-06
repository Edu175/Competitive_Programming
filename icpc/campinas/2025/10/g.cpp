#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll uf[MAXN];
ll val[MAXN];
void init(){
	mset(uf,-1);
}
ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
ii uni(ll x, ll y){
	x=find(x), y=find(y);	
	if(val[x]>val[y]) swap(x,y);
	uf[y]=x;
	return {val[y],val[x]};
}
map<ll,ll> m;

int main(){
	TUCUTUCUTUCUTUCU
	ll n; cin>>n; ll t[n]; 
	init();
	fore(i,0,n) {
		cin>>t[i]; 
		if(!m.count(t[i])) {m[t[i]]=i; val[i]=t[i];} 
		else{
			uf[i]=m[t[i]];
			val[i]=t[i];
		}
	}
	vector<ii> ans;
	fore(i,0,(n+1)/2){
		if(find(i)==find(n-1-i)){
			continue;
		}
		else{
			ii a=uni(i,n-i-1);
			
			ans.pb(a);
		}
	}
	cout<<SZ(ans)<<"\n";
	for(auto [i,j]: ans){cout<<i<<" "<<j<<"\n";}
	return 0;
}