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

ll k;
char C(char c, ll sig){
	ll p=c-'a';
	p=(p+sig+k)%k;
	c='a'+p;
	return c;
}

char get(char c){
	char ret=min({c,C(c,1),C(c,-1)});
	return ret;
};


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		string a; cin>>a;
		vector<string> cand(2);
		fore(i,0,n){
			vector<vector<string>> prox(2);
			 // ******o...
			char now=a[i],best=get(now);
			string _s=cand[0]; _s.pb(now);
			auto s=_s;
			s.back()=best;
			prox[0].pb(s);
			s=_s;
			prox[1].pb(s);
			if(SZ(s)>=2){
				swap(s.end()[-2],s.end()[-1]);
				prox[0].pb(s);
			}
			 // *****o*...
			_s=cand[1];
			_s.pb(now);
			if(SZ(_s)>=2){
				swap(_s.end()[-2],_s.end()[-1]);
				s=_s;
				s.end()[-2]=best;
				prox[0].pb(s);
				if(SZ(_s)>=3){
					s=_s;
					swap(s.end()[-3],s.end()[-2]);
					prox[0].pb(s);
				}
			}
			
			fore(w,0,2){
				sort(ALL(prox[w]));
				cand[w]=prox[w][0];
			}
		}
		cout<<cand[0]<<"\n";
	}
	return 0;
}
