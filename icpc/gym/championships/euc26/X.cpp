#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll m;

ll fpow(ll b, ll e){
	if(e == 0) return 1;
	ll x = fpow(b,e/2);
	return (e&1) ? (((x*x)%m)*b)%m : (x*x)%m;
}

int main(){
	JET
	ll n,s; cin>>n>>s>>m;
	priority_queue<ll> b;
	fore(i,0,s){
		ll x; cin>>x;
		b.push(x);
	}
	ll g = n-b.top();
	vv a;
	a.pb(b.top());
	b.pop();
	while(SZ(b)){
		ll x = b.top(); b.pop();
		cout<<x<<" "<<a.back()<<endl;
		// cerr<<x<<" "<<SZ(a)<<endl;
		// assert(SZ(a)<3);
		if(x == a.back()) continue;
		if(x*2 - 1 <= a.back()) a.pb(x);
		else if(x>1){
			b.push(2*x - a.back());
			if(a.back()/2+1 < x)b.push(a.back()/2+1);
			// a.pop_back();
			// a.pb((a.back()+1)/2);
			// cout<<x<<" agg "<<2*x-a.back()<<"\n";
		}
	}
	reverse(ALL(a));
	
	show(a);
	ll ant = 0;
	for(auto x:a){
		ll k = x-ant;
		if(k<=ant){
			ant = x;
			continue;
		}
		g+=(k-ant+1)/2;
		ant = x;
	}
	cout<<fpow(2,g)<<"\n";
	return 0;
}
