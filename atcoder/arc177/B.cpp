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
	ll n; cin>>n;
	string s; cin>>s;
	vector<ii>p;
	fore(i,0,n){
		if(i==n-1||s[i]!=s[i+1])p.pb({i+1,s[i]-'0'});
	}
	if(p.back().snd==0)p.pop_back();
	reverse(ALL(p));
	string r;
	fore(i,0,SZ(p)){
		fore(j,0,p[i].fst)r.pb('A'+(p[i].snd^1));
	}
	cout<<SZ(r)<<"\n";
	cout<<r<<"\n";
	return 0;
}
