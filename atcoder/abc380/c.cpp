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
	ll n,k; cin>>n>>k; k--;
	string s; cin>>s;
	ll q=0;
	vector<ii>bs;
	fore(i,0,n){
		q++;
		if(i==n-1||s[i]!=s[i+1]){
			bs.pb({s[i]-'0',q});
			q=0;
		}
	}
	ll cnt=0;
	fore(i,0,SZ(bs)){
		if(cnt==k&&bs[i].fst){
			cnt+=bs[i].fst;
			if(i)swap(bs[i-1],bs[i]);
		}
		else cnt+=bs[i].fst;
	}
	string res;
	for(auto [t,q]:bs)res+=string(q,'0'+t);
	cout<<res<<"\n";
	return 0;
}
