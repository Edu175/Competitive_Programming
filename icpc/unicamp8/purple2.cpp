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
const ll MAXN=65,M=25,L=6;

ll n,l;
ll a[MAXN];

set<vector<ll>>st;
vector<ll>v;

void f(ll j){
	if(SZ(v)==l&&j<n+1)st.insert(v);
	if(j>=n+1)return;
	fore(nv,(SZ(v)?v.back()+1:1),M){
		v.pb(nv);
		ll nj=n;
		fore(k,j,n)if(a[k]==nv){nj=k+1;break;}
		f(nj);
		v.pop_back();
	}
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cin>>l;
	f(0);
	cout<<SZ(st)<<"\n";
	for(auto i:st){
		imp(i);
	}
	return 0;
}
