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
	cout<<"in "<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<"\n";
	ll l=-1,r=5e9+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(eval(m,a)>eval(m,b))l=m+1;
		else r=m-1;
	}
	cout<<"= "<<l<<","<<r<<"\n";
	if(eval(r,a)==eval(r,b))r--;
	return {r,l};
}

ll inter(ii a, ii b){ // y
	if(a>b)swap(a,b);
	if(a.fst==-1)return b.snd;
	if(a.snd==-1)return b.fst;
	return eval(in(a,b).snd,b);
}

int main(){FIN;
	ll __; cin>>__;
	while(__--){
		cout<<"\n===================\n";
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		vector<ll>p(n),ap(n);
		fore(i,0,n)cin>>p[i],p[i]=n-1-p[i],ap[p[i]]=i;
		ll l=0,r=5e9+5;
		set<ii>st={{-1,0},{2e10,-1}};
		for(auto i:ap){
			ii x=a[i];
			cout<<i<<": "<<x.fst<<","<<x.snd<<":\n";
			for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
			auto k=st.lower_bound(x);
			ll flag=0;
			while(k!=next(st.begin())){
				auto y=prev(k),z=prev(y);
				if(inter(*z,x)>=inter(*z,*y))st.erase(y),flag=1;
				else break;
			}
			k--;
			while(k!=prev(prev(st.end()))){
				auto y=next(k),z=next(y);
				if(inter(*z,x)>=inter(*z,*y))st.erase(y),flag=1;
				else break;
			}
			ll li=5e9+5,ri=0;
			if(k==st.begin()||k==next(st.begin())||k==prev(prev(st.end()))||flag){
				st.insert(x);
				auto k=st.lower_bound(x);
				if(k!=st.begin()){
					li=in(*prev(k),x).snd;
					cout<<prev(k)->fst<<","<<prev(k)->snd<<"\n";
				}
				ri=in(*next(k),x).fst;
			}
			cout<<li<<","<<ri<<"\n\n";
			l=max(l,li);
			r=min(r,ri);
		}
		for(auto i:st)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		if(l<=r)cout<<l<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
