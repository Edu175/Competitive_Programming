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

ll tech(ll a, ll b){
	if(a<0&&b<0)a=-a,b=-b;
	if(b==0)return 5e9;
	return a/b+1;
}

ll in(ii a, ii b){
	ll x=tech(b.snd-a.snd,a.fst-b.fst);
	return x;
}


int main(){FIN;
	ll __; cin>>__;
	while(__--){
		//cout<<"====================\n";
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		vector<ll>p(n),ap(n);
		fore(i,0,n)cin>>p[i],p[i]=n-1-p[i],ap[p[i]]=i;
		set<ii>st;
		fore(i,0,n)st.insert(a[i]);
		if(SZ(st)!=n){
			cout<<"-1\n";
			continue;
		}
		ll l=0,r=5e9;
		fore(i,0,n)fore(j,i+1,n){
			ii x=a[i],y=a[j];
			if(p[i]>p[j])swap(x,y);
			ll d=in(x,y);
			cout<<x.fst<<","<<x.snd<<" "<<y.fst<<","<<y.snd<<": "<<d<<"\n";
			if(eval(-5e9,x)<eval(-5e9,y))r=min(r,d);
			else l=max(l,d);
		}
		cout<<l<<" "<<r<<"\n";
		if(l<=r)cout<<l<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
