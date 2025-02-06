#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m; cin>>m>>n;
	vector<ii>a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].fst--;
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){
		ii c=a[i]; c.snd=-c.snd;
		ii d=a[j]; d.snd=-d.snd;
		return c<d;
	});
	if(a[per[0]]==ii({0,m})){
		cout<<"1\n";
		vv res(n);
		res[per[0]]=1;
		imp(res)
		cerr<<"caso 1\n";
		return 0;
	}
	vector<ii> b;
	ll r=-1;
	fore(i,0,n){
		auto p=a[per[i]];
		if(r>=p.snd){
			cout<<"2\n";
			vv res(n);
			res[per[i-1]]=1;
			res[per[i]]=2;
			imp(res)
			cerr<<"caso 2\n";
			return 0;
		}
		r=p.snd;
		b.pb(p);
	}
	if(b.back().fst>=b[0].snd||(b.back().snd==m&&b[0].fst==0)){
		cout<<"2\n";
		ll fg=(b.back().snd==m&&b[0].fst==0);
		vv res(n);
		res[per[0]]=2-fg;
		res[per.back()]=2-fg;
		imp(res)
		cerr<<"caso 3 "<<fg<<"\n";
		return 0;
	}
	if(SZ(b)<3)cout<<"-1\n";
	else {
		cout<<"3\n";
		vv res(n);
		res[per[0]]=1;
		res[per[1]]=2;
		res[per[2]]=1;
		imp(res)
		cerr<<"caso 4\n";
	}
	return 0;
}
