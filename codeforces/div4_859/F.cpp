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

vector<ii>dir={{-1,-1},{-1,1},{1,-1},{1,1}};
ii operator+(ii p1,ii p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd;
		s=s+dir[0],e=e+dir[0];
		string c; cin>>c;
		ll d=(2*(c[0]=='D')+(c[1]=='R'));
		set<pair<ii,ll>>st;
		ii p=s;
		ll res=0;
		while(1){
			//cout<<p.fst<<","<<p.snd<<" "<<d<<"\n";
			if(p==e)break;
			if(st.count({p,d}))break;
			st.insert({p,d});
			ll q=0;
			if(p.fst==0&&((d&2)==0))d+=2,q=1;
			if(p.fst==n-1&&((d&2)==2))d-=2,q=1;
			if(p.snd==0&&((d&1)==0))d+=1,q=1;
			if(p.snd==m-1&&((d&1)==1))d-=1,q=1;
			res+=q;
			//if(q)cout<<".\n";
			p=p+dir[d];
		} 
		if(p==e)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
