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

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	ll a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	ll mov=(n+m-2);
	ll C=mov/2;
	//cout<<mov<<": "<<C<<" "<<mov-C<<endl;
	map<ll,ll> xp[n][m];
	fore(mk,0,1ll<<C){
		ii p={0,0};
		ll x=a[p.fst][p.snd],flag=1;
		fore(i,0,C){
			if((mk>>i)&1)p.snd++;
			else p.fst++;
			if(p.fst>=n||p.snd>=m){
				flag=0;
				break;
			}
			x^=a[p.fst][p.snd];
		}
		if(flag){
			xp[p.fst][p.snd][x]++;
			//cout<<p<<" "<<x<<endl;
		}
	}
	ll res=0;
	fore(mk,0,1ll<<(mov-C)){
		ii p={n-1,m-1};
		ll x=a[p.fst][p.snd],flag=1;
		fore(i,0,mov-C){
			if((mk>>i)&1)p.snd--;
			else p.fst--;
			if(p.fst<0||p.snd<0){
				flag=0;
				break;
			}
			x^=a[p.fst][p.snd];
		}
		if(flag){
			x^=a[p.fst][p.snd];
			//cout<<p<<" "<<x<<endl;
			res+=xp[p.fst][p.snd][x^k];
		}
	}
	cout<<res<<"\n";
	return 0;
}
