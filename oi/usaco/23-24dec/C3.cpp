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

ll tech(ll a, ll b){ //piso+1
	if(a<0&&b<0)a=-a,b=-b;
	if(b==0)return 5e9;
	return a/b+1;
}

ll in(ii a, ii b){
	//cout<<"in "<<b.snd-a.snd<<"/"<<a.fst-b.fst<<"\n";
	ll x=tech(b.snd-a.snd,a.fst-b.fst);
	return x;
}


int main(){FIN;
	ll __; cin>>__;
	while(__--){
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd;
		fore(i,0,n)cin>>a[i].fst;
		vector<ll>p(n),ap(n);
		fore(i,0,n)cin>>p[i],p[i]=n-1-p[i],ap[p[i]]=i;
		/*set<ii>st;
		fore(i,0,n)st.insert(a[i]);
		if(SZ(st)!=n){
			cout<<"-1\n";
			continue;
		}*/
		ll l=0,r=5e9;
		fore(i,1,n){
			ii x=a[ap[i]],y=a[ap[i-1]];
			if(x.fst<=y.fst&&x.snd<=y.snd){r=-1;break;}
			if(x.fst>=y.fst&&x.snd>=y.snd)continue;
			ll d=in(x,y);
			//cout<<x.fst<<","<<x.snd<<" "<<y.fst<<","<<y.snd<<": "<<l<<","<<r<<": "<<d<<" --> ";
			if(x.fst>y.fst){
				l=max(l,d);
			}
			else {
				if(eval(d-1,x)==eval(d-1,y))d--;
				r=min(r,d);
			}
			//cout<<d<<": "<<l<<","<<r<<"\n";
		}
		//cout<<l<<","<<r<<"\n";
		if(l<r)cout<<l<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
