#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto skjdgh:v)cout<<skjdgh<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
string cartas="A23456789DQJK";
map<char,ll>trad;

int main(){JET;
	ll n,k; cin>>n>>k; k--;
	fore(i,0,SZ(cartas))trad[cartas[i]]=i;
	vector<vector<ll>>a(n);
	fore(i,0,n){
		string s; cin>>s;
		for(auto j:s)a[i].pb(trad[j]);
	}
	a[k].pb(15);
	auto tiene=[&](vector<ll>&a){
		return SZ(a)==4&&count(ALL(a),a[0])==4;
	};
	ll res=n+5;
	fore(i,0,n){
		if(tiene(a[i]))res=min(res,i);
	}
	if(res<n){
		cout<<res+1<<"\n";
		return 0;
	}
	auto saco=[&](ll x, vector<ll>&a){
		vector<ll>b;
		for(auto i:a){
			if(i==x)x=-1;
			else b.pb(i);
		}
		a=b;
	};
	auto get=[&](vector<ll>&a, ll us=0){
		if(!us&&count(ALL(a),15))return 15ll;
		vector<ii>c;
		for(auto i:a)c.pb({count(ALL(a),i),i});
		sort(ALL(c));
		return c[0].snd==15?c[1].snd:c[0].snd;
	};
	// fore(i,0,n)imp(a[i]);
	for(ll i=k;;){
		// cout<<i<<": ";
		// imp(a[i]);
		ll i_=(i+1)%n;
		ll x=get(a[i],k==i);
		if(k==i)k=-1;
		if(x==15)k=i_;
		saco(x,a[i]);
		// cout<<"saque "<<x<<" ("<<i<<")\n";
		// imp(a[i]);
		// cout<<"\n";
		a[i_].pb(x);
		if(tiene(a[i])){res=i;break;}
		i=i_;
	}
	cout<<res+1<<"\n";
	return 0;
} 