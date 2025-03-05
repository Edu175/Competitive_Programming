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
	ll t; cin>>t;
	while(t--){
		string s,t; cin>>s>>t;
		deque<ii>a,b;
		ll q=0;
		fore(i,0,SZ(s)){
			q++;
			if(i==SZ(s)-1||s[i]!=s[i+1])a.pb({q,s[i]-'0'}),q=0;
		}
		q=0;
		fore(i,0,SZ(t)){
			q++;
			if(i==SZ(t)-1||t[i]!=t[i+1])b.pb({q,t[i]-'0'}),q=0;
		}
		if(s==t){cout<<"0\n";continue;}
		ll res=0,fg=1;
		auto go0=[&](){
			res++;
			if(SZ(a)<2){fg=0;return;}
			auto p1=a.front(); a.pop_front();
			auto p0=a.front(); a.pop_front();
			if(SZ(a))a.front().fst+=p1.fst;
			else a.push_front(p1);
			a.push_front(p0);
		};
		auto go1=[&](){
			res++;
			if(SZ(a)<3){fg=0;return;}
			auto p0=a.front(); a.pop_front();
			auto p2=a.front(); a.pop_front();
			auto p1=a.front(); a.pop_front();
			if(SZ(a))a.front().fst+=p2.fst;
			else a.push_front(p2);
			p0.fst+=p1.fst;
			a.push_front(p0);
		};
		// if(SZ(a)<=SZ(b))fg=0;
		while(fg&&SZ(a)){
			if(a.front().snd!=b.front().snd)go0();
			else if(a.front().fst<b.front().fst)go1();
			else if(a.front().fst==b.front().fst)a.pop_front(),b.pop_front();
			else fg=0;
		}
		if(!fg)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
