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

ll cost(string s){
	ll res=0;
	ll c=0;
	fore(i,0,SZ(s)){
		if(s[i]=='(')c++;
		else {
			if(c>0)res+=2,c--;
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<vv> pos(2);
		fore(i,0,n)pos[s[i]-'('].pb(i);
		reverse(ALL(pos[1]));
		ll res=cost(s);
		vv ans(n);
		fore(r,0,k+1){
			vv ban(n);
			fore(i,0,min(r,(ll)SZ(pos[0])))ban[pos[0][i]]=1;
			fore(i,0,min(k-r,(ll)SZ(pos[1])))ban[pos[1][i]]=1;
			string t;
			fore(i,0,n)if(!ban[i])t.pb(s[i]);
			ll cur=cost(t);
			res=min(res,cur);
			if(res==cur)ans=ban;
		}
		// cout<<res<<"\n";
		for(auto i:ans)cout<<i;;cout<<"\n";
	}
	return 0;
}
