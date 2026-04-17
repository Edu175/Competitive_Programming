#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const ll MAXV=5e4+5,B=224;

int main(){JET;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ii>qu(q);
	ll mem[q][2];
	vector<pair<ii,ll*>> qs[n+1];
	fore(i,0,q){
		ll l,r,x,m; cin>>l>>r>>x>>m; l--;
		qs[l].pb({{x,m},&mem[i][0]});
		qs[r].pb({{x,m},&mem[i][1]});
	}
	vector<ll> hist[B];
	fore(i,1,B)hist[i].resize(i);
	hist[0].resize(MAXV);
	fore(i,0,n+1){
		for(auto [pa,w]:qs[i]){
			auto [x,m]=pa;
			if(m<B)*w=hist[m][x];
			else{
				ll res=0;
				for(ll v=x;v<MAXV;v+=m)res+=hist[0][v];
				*w=res;
			}
		}
		if(i==n)break;
		fore(m,0,B){
			ll v=m?a[i]%m:a[i];
			hist[m][v]++;
		}
	}
	fore(i,0,q){
		cout<<mem[i][1]-mem[i][0]<<"\n";
	}
	return 0;
}