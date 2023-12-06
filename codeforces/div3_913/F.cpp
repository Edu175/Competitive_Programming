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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

ll n;
ii go(ii x, ll d){
	if(!d)return {(x.fst+1)%n,x.snd};
	return {n-1-x.fst,x.snd^1};
}


ll bfs(ii s, ii e){
	ll d[n][2];
	mset(d,-1);
	d[s.fst][s.snd]=0;
	queue<ii>q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(x==e)return d[x.fst][x.snd];
		fore(i,0,2){
			auto y=go(x,i);
			if(d[y.fst][y.snd]==-1){
				d[y.fst][y.snd]=d[x.fst][x.snd]+1;
				q.push(y);
			}
		}
	}
	return d[e.fst][e.snd];
}

bool check(vector<ll>a, ll x, ll w){
	if(w){
		reverse(ALL(a));
		x=n-1-x;
	}
	//cout<<a<<" "<<x<<": "<<b<<"\n";
	vector<ll>b(n);
	fore(i,0,n){
		b[(i-x-1+2*n)%n]=a[i];
	}
	fore(i,1,n)if(b[i-1]>b[i])return 0;
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll flag=1,mx=a[0];
		fore(i,1,n){
			if(a[i]!=a[i-1])flag=0;
			mx=max(mx,a[i]);
		}
		if(flag){
			cout<<"0\n";
			continue;
		}
		ll x0=-1,x1=1;
		fore(i,0,n){
			if(a[i]==mx){
				if(a[(i-1+n)%n]!=mx)x1=i;
				if(a[(i+1)%n]!=mx)x0=i;
			}
		}
		//assert(x1!=-1&&x0!=-1);
		ll res=n+5;
		if(check(a,x0,0))res=min(res,bfs({x0,0},{n-1,0}));
		if(check(a,x1,1))res=min(res,bfs({x1,0},{n-1,1}));
		if(res==n+5)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
