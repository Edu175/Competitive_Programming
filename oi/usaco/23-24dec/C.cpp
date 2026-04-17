#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll eval(ll x, ii a){
	return x*a.fst+a.snd;
}

ii in(ii a, ii b){ // piso,techo de coordenada x de interseccion
	if(a>b)swap(a,b);
	ll l=0,r=1e9+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(eval(m,a)>eval(m,b))l=m+1;
		else r=m-1;
	}
	if(eval(r,a)==eval(r,b))l=r;
	return {l,r};
}

bool bet(ii a, ii b){
	return (a.fst>=b.fst&&a.snd>=b.snd);
}

int main(){FIN;
	ll __; cin>>__;
	while(__--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		vector<ll>p(n),ap(n);
		fore(i,0,n)cin>>p[i],ap[p[i]]=i;
		ll l=0,r=1e9+5;
		set<ii>st;
		for(auto i:ap){
			ii x=a[i];
			if(p[0]==i){
				st.insert(x);
				continue;
			}
			auto it=st.upper_bound(x);
			auto k=it;
			ll flag=0;
			while(k!=st.begin()){
				if(bet(x,*prev(k))){
					flag=1;
					st.erase(prev(k));
					continue;
				}
				if(bet(*prev(k),x))break;
				if(k!=next(st.begin())){
					
				}
				else break;
			}
			if(k==st.begin()||flag)st.insert(x);
		}
	}
	return 0;
}
