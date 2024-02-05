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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b; cin>>a>>b;
		ii ki,q; cin>>ki.fst>>ki.snd>>q.fst>>q.snd;
		set<ii>st[2];
		fore(i,0,2)fore(j,0,2)fore(k,0,2)fore(l,0,2){
			ii p=ki;
			if(l)p=q;
			ii add={a,b};
			if(i)swap(add.fst,add.snd);
			if(j)add.fst*=-1;
			if(k)add.snd*=-1;
			p.fst+=add.fst,p.snd+=add.snd;
			st[l].insert(p);
		}
		ll res=0;
		for(auto i:st[0])res+=st[1].count(i);
		//for(auto i:st[0])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		//for(auto i:st[1])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
