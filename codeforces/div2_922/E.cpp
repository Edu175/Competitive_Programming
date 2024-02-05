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
const ll MAXN=2005;

ll L[MAXN],R[MAXN];

ll ask(ll i){
	cout<<"? "<<i+1<<endl;
	char c; cin>>c;
	while(c=='-');
	if(c=='>')return 1;
	if(c=='<')return -1;
	return 0;
}

vector<ll>p;

void dfs(vector<ll>a){
	if(!SZ(a))return;
	ll x=a[rand()%SZ(a)];
	vector<ll>l,r;
	while(ask(x));
	for(auto i:a)if(i!=x){
		if(ask(i)==1)r.pb(i);
		else l.pb(i);
		ask(x);
	}
	dfs(l);
	p.pb(x);
	dfs(r);
}

int main(){FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		p.clear();
		ll n; cin>>n;
		vector<ll>a;
		fore(i,0,n)a.pb(i);
		dfs(a);
		vector<ll>res(n);
		fore(i,0,n)res[p[i]]=i;
		cout<<"! ";
		for(auto i:res)cout<<i+1<<" ";
		cout<<endl;
	}
	return 0;
}
