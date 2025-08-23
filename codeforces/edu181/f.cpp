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

string s;
string doc="docker";
ll tam=SZ(doc);
ll diff(ll l){
	ll res=0;
	fore(i,0,tam)res+=doc[i]!=s[l+i];
	return res;
}

ii aliens(ll lam){
	ll n=SZ(s);
	vector<ii> dp(n+3);
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i];
		res=dp[i+1];
		if(i+tam<=n){
			ii go=dp[i+tam];
			go.fst+=diff(i)-lam;
			go.snd++;
			res=min(res,go);
		}
	}
	return dp[0];
}

const ll INF=1e7;

ll getmin(ll k, ll hv){
	if(k<=hv){
		return hv-k;
	}
	// cerr<<"getmin "<<k<<"\n";
	ll l=-INF,r=INF;
	while(r-l>1){
		ll m=(l+r)/2;
		if(aliens(m).snd<=k)l=m;
		else r=m;
	}
	ll lam=l;
	auto [res,c]=aliens(lam);
	// cout<<lam<<": "<<res<<","<<c<<"\n";
	res+=c*lam;
	res+=(k-c)*lam;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>s;
		ll c=0;
		fore(i,0,SZ(s)-tam+1)c+=diff(i)==0;
		ll mxc=SZ(s)/tam+1;
		vector<ii>all;
		vector<ii>ev;
		ll n; cin>>n;
		fore(i,0,n){
			ll l,r; cin>>l>>r; r++;
			ev.pb({l,+1});
			ev.pb({r,-1});
		}
		ev.pb({0,0});
		ev.pb({mxc,0});
		sort(ALL(ev));
		map<ll,vector<ii>> mp;
		// mp[0]={{0,mxc+1}};
		ll q=0;
		fore(i,0,SZ(ev)){
			q+=ev[i].snd;
			if(ev[i].fst<mxc&&i<SZ(ev)-1&&ev[i].fst!=ev[i+1].fst){
				assert(ev[i+1].fst<=mxc);
				mp[q].pb({ev[i].fst,ev[i+1].fst});
			}
		}
		// while(mp.rbegin()->fst>mxc)mp.erase(prev(mp.end()));
		all=mp.rbegin()->snd;
		
		ll p=upper_bound(ALL(all),(ii){c,INF})-all.begin();
		
		// cerr<<mxc<<" "<<c<<": ";
		// for(auto i:all)cout<<i.fst<<","<<i.snd<<" ";;cout<<": "<<p<<"\n";
		
		if(p&&c<all[p-1].snd){
			cout<<"0\n";
			continue;
		}
		
		ll res0=INF;
		if(p)res0=getmin(all[p-1].snd-1,c);
		
		ll res1=INF;
		if(p<SZ(all))res1=getmin(all[p].fst,c);
		
		ll res=min(res0,res1);
		cout<<res<<"\n";
		// cerr<<"\n\n";
	}
	return 0;
}
