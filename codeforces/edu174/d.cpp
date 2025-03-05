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

ll solve(string s){
	vv l(26),l_(26),r(26);
	// cout<<"solve "<<s<<": ";
	for(auto i:s)l_[i-'a']++;
	ll n=SZ(s);
	ll lp=(n-1)/2,rp=n/2;
	while(lp>=0&&s[lp]==s[rp])lp--,rp++;
	
	
	fore(i,0,n){
		l[s[i]-'a']++;
		l_[s[i]-'a']--;
		r[s[n-1-i]-'a']++;
		ll fg=1;
		if(i<n-1-i){ // no interseca
			fg=l==r;
		}
		else {
			fore(i,0,26)fg&=l[i]>=l_[i];
		}
		fg&=i>=lp;
		if(fg){/*cout<<i+1<<"\n";*/return (i+1);}
	}
	// cout<<"-1\n";
	return -1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll l=0,r=SZ(s)-1;
		while(l<=r&&s[l]==s[r])l++,r--;
		if(l>r){cout<<"0\n";continue;}
		s=s.substr(l,r-l+1);
		ll res=solve(s);
		reverse(ALL(s));
		res=min(res,solve(s));
		cout<<res<<"\n";
	}
	return 0;
}
