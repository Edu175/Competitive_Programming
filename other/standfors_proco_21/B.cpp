#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef pair<ii,ii> Seg;
Seg norm(Seg a){
	if(a.fst>a.snd)swap(a.fst,a.snd);
	return a;
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll cant(set<Seg> st, ll n){ // los Seg de st estan normalizados
	ll res=0;
	fore(i,0,n-1)fore(j,0,n-1){
		ll fg=1;
		ii piv={i,j};
		fore(dir,0,2)fore(off,0,2){
			ii me={0,off};
			ii he={1,off};
			if(dir)swap(me.fst,me.snd),swap(he.fst,he.snd);
			me=piv+me;
			he=piv+he;
			fg&=st.count(norm({me,he}));
		}
		res+=fg;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	
	return 0;
}
