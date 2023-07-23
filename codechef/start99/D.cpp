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
//Yet Another Bitwise Problem
const ll MAXN=2e5+5;

set<ll>cmp;
int uf[MAXN];
void uf_init(ll n){
	cmp.clear();
	fore(i,0,n)uf[i]=-1,cmp.insert(i);
}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	//cout<<"join "<<x<<" "<<y<<"\n";
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	cmp.erase(y);
	return true;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		vector<ll>h[32];
		uf_init(n);
		//cout<<"scan and h"<<endl;
		fore(i,0,n){
			cin>>a[i];
			fore(j,0,32)if(a[i]&(1ll<<j))h[j].pb(i);
		}
		ll res=0;
		//cout<<"calc res"<<endl;
		for(ll b=31;b>=0;b--){
			//cout<<"b "<<b<<endl;
			if(!SZ(h[b]))continue;
			set<ll>st;
			for(auto i:h[b])st.insert(uf_find(i));
			if(SZ(st)==SZ(cmp))continue;
			res|=(1ll<<b);
			fore(i,1,SZ(h[b]))uf_join(h[b][i],h[b][i-1]);
		}
		//imp(cmp);
		cout<<res<<"\n";
	}
	return 0;
}
