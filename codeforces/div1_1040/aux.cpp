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

bool isrbs(string s){
	ll c=0;
	for(auto i:s){
		if(i==')')c--;
		else c++;
		if(c<0)return 0;
	}
	return c==0;
}

ll cont(string s){
	ll n=SZ(s);
	ll res=0;
	fore(l,0,n)fore(r,l+1,n+1){
		string t;
		fore(i,l,r)t.pb(s[i]);
		res+=isrbs(t);
	}
	return res;
}
mt19937 rng(175);
int main(){FIN;
	// string s; cin>>s;
	// cout<<cont(s)<<"\n";
	
	ll k=11;
	ii cur={2,2};
	vector<ii>a;
	ll sum=0;
	while(SZ(a)<k){
		if(cur.fst*cur.snd<=sum){
			if(cur.fst<cur.snd*2)cur.fst++;
			else cur.snd++;
		}
		else a.pb(cur),sum+=cur.fst*cur.snd;
	}
	
	ll cost=0;
	for(auto i:a){
		cout<<i.fst<<","<<i.snd<<" ";
		cost+=(cur.fst+2*cur.snd-2)+5;
	}
	cout<<"\n";
	cout<<"cost "<<cost<<"\n";
	exit(0);
	map<ll,vector<string>>mp;
	vv per(k); iota(ALL(per),0);
	shuffle(ALL(per),rng);
	string par="()";
	fore(mk,0,1ll<<k){
		string s="";
		fore(i,1,2*k+1)s+=string(i,'(');
		fore(i,0,k){
			char c=par[mk>>i&1];
			s+=string(per[i]+1,c);
		}
		mp[cont(s)].pb(s);
	}
	
	ll fg=1;
	for(auto i:mp){
		cout<<i.fst<<": ";
		imp(i.snd);
		fg&=SZ(i.snd)==1;
	}
	if(fg)cout<<"good\n";
	else cout<<"bad\n";
	return 0;
}
