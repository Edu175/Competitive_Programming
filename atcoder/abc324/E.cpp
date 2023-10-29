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

ll pre(string &a, string &b){ //max prefix of a s.t. is subseq of b
	ll p=0;
	fore(i,0,SZ(b)){
		if(p>=SZ(a))break;
		if(a[p]==b[i])p++;
	}
	return p;
}
ll suf(string &a, string &b){
	ll p=SZ(a)-1;
	for(ll i=SZ(b)-1;i>=0;i--){
		if(p<0)break;
		if(a[p]==b[i])p--;
	}
	return p;
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vector<ll>pr,su;
	string a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)pr.pb(pre(s,a[i])),su.pb(suf(s,a[i]));
	sort(ALL(su));
	ll res=0;
	fore(i,0,n){
		ll lwb=lower_bound(ALL(su),pr[i])-su.begin();
		res+=lwb;
	}
	cout<<res<<"\n";
	return 0;
}
