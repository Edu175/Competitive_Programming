#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ii a,b; cin>>a.fst>>a.snd>>b.fst>>b.snd;
	ii C={0,0};
	if(a.fst<0)C.fst=(abs(a.fst)/4+5)*4;
	if(a.snd<0)C.snd=(abs(a.snd)/2+5)*2;
	a.fst+=C.fst;
	a.snd+=C.snd;
	b.fst+=C.fst;
	b.snd+=C.snd;
	
	ii s,e;
	s.fst=((a.fst+3)/4*4);
	s.snd=(a.snd+1)/2*2;
	e.fst=((b.fst)/4*4);
	e.snd=(b.snd)/2*2;
	ii l,r;
	l.fst=(a.fst%4+4)%4;
	l.snd=(a.snd%2+2)%2;
	if(!l.fst)l.fst=4;
	if(!l.snd)l.snd=2;
	r.fst=(b.fst%4+4)%4;
	r.snd=(b.snd%2+2)%2;
	ll res=0;
	ii c;
	c.fst=max(0ll,(e.fst-s.fst)/4);
	c.snd=max(0ll,(e.snd-s.snd)/2);
	res+=8*(c.fst*c.snd);
	vector<vector<ll>>val={{2,1},
						   {1,2},
						   {0,1},
						   {1,0}};
	auto get=[&](ll i0, ll i1, ll j0, ll j1){
		ll sum=0;
		fore(i,i0,i1)fore(j,j0,j1)sum+=val[i][j];
		return sum;
	};
	if(s.fst<=e.fst){
		res+=get(l.fst,4,0,2)*c.snd;
		res+=get(0,r.fst,0,2)*c.snd;
	}
	else {
		res+=get(l.fst,r.fst,0,2)*c.snd;
	}
	
	if(s.snd<=e.snd){
		res+=get(0,4,l.snd,2)*c.fst;
		res+=get(0,4,0,r.snd)*c.fst;
	}
	else {
		res+=get(0,4,l.snd,r.snd)*c.fst;
	}
	
	res+=get(l.fst,4,l.snd,2);
	res+=get(0,r.fst,l.snd,2);
	res+=get(0,r.fst,0,r.snd);
	res+=get(l.fst,4,0,r.snd);
	
	cout<<res<<"\n";
	return 0;
}
