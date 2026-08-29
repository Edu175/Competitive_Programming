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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,s; cin>>n>>m>>s;
		string ty; cin>>ty;
		ll a=0,l=0;
		ll res=0;
		ll cot=s*m;
		fore(i,0,n)if(res<cot){
			if(ty[i]=='A'){
				if(l>0)l--,a++;
				else {
					assert(m>0);
					m--;
					l+=s-1;
				}
				res++;
			}
			else if(ty[i]=='I'){
				if(m>0)res++,m--,l+=s-1;
			}
			else {
				if(l>0)l--,res++;
				else {
					assert(m>0);
					if(a>0)res++,a--,m--,l+=s-1;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
