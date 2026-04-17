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
	if(b==0)return -1;
	return a/b+1;
}

ii in(ii a, ii b){
	ll x=tech(b.snd-a.snd,a.fst-b.fst);
	return {x,eval(x,b)};
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
		ll flag=1;
		fore(e,0,n){
			vector<ii>b;
			fore(i,0,e+1)b.pb(a[ap[i]]);
			sort(ALL(b));
			vector<ii>h={{-1,0}};
			for(auto x:b){
				while(SZ(h)>1){
					auto z=h[SZ(h)-2],y=h.back();
					if(in(z,x).snd>in(z,y).snd)h.pop_back();
					else break;
				}
				h.pb(x);
			}
			ll w=-1;
			auto u=a[ap[e]];
			cout<<e<<" "<<p[e]<<" "<<u.fst<<","<<u.snd<<": ";
			for(auto i:h)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
			fore(i,0,SZ(h))if(h[i]==u)w=i;
			if(w==-1)flag=0;
			else {
				l=max(l,in(h[w-1],u).fst);
				if(w<SZ(h)-1)r=min(r,in(u,h[w+1]).fst);
			}
		}
		if(l<r&&flag)cout<<l<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
