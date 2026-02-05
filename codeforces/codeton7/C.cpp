#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
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
		ll n,k; cin>>n>>k;
		vv a(n);
		vector<ii> sa;
		fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
		vv b(n);
		fore(i,0,n)cin>>b[i];
		sort(ALL(sa));
		sort(ALL(b));
		vv mn(n,-1),mx(n,-1);
		ll L=0,R=0;
		// mx
		ll po=0;
		fore(i,0,n){
			while(po<n&&!(b[i]<sa[po].fst))po++;
			if(po==n){
				po=0;
				fore(j,i,n){
					while(mx[po]!=-1)po++;
					mx[po++]=j;
				}
				break;
			}
			mx[sa[po++].snd]=i;
			R++;
		}
		// mn
		po=n-1;
		forr(i,0,n){
			while(po>=0&&(b[i]<sa[po].fst))po--;
			if(po<0){
				po=0;
				forr(j,0,i+1){
					while(mn[po]!=-1)po++;
					mn[po++]=j;
					L++;
				}
				break;
			}
			mn[sa[po--].snd]=i;
		}
		if(k<L||k>R){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		// mn -> mx, it is continuous
		ll val=0;
		vv per=mn;
		vv pos(n);
		fore(i,0,n)pos[per[i]]=i;
		fore(i,0,n)val+=a[i]>b[per[i]];
		auto sw=[&](ll i, ll j){
			val-=a[i]>b[per[i]];
			val-=a[j]>b[per[j]];
			swap(pos[per[i]],pos[per[j]]);
			swap(per[i],per[j]);
			val+=a[i]>b[per[i]];
			val+=a[j]>b[per[j]];
		};
		fore(i,0,n){
			if(val==k)break;
			ll j=pos[mx[i]];
			sw(i,j);
			assert(per[i]==mx[i]);
		}
		assert(k==val);
		fore(i,0,n)cout<<b[per[i]]<<" ";;cout<<"\n";
	}
	return 0;
}
