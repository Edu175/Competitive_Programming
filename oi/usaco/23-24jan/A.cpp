#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skjdhf:v)cout<<skjdhf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		//cout<<"\n";
		ll n,q,m; cin>>n>>q>>m;
		vector<ll>a(n),is(n);
		fore(i,0,n){
			cin>>a[i];
			if(a[i]==0)a[i]=is[i]=1;
		}
		vector<ii>b(q);
		fore(i,0,q)cin>>b[i].snd>>b[i].fst,b[i].fst--;
		sort(ALL(b));
		vector<ii>c;
		for(auto i:b)if(!SZ(c)||c.back().fst!=i.fst)c.pb(i);
		ll flag=1;
		//for(auto i:c)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		fore(i,0,SZ(c)){
			if(i&&c[i].snd<=c[i-1].fst)flag=0;
		}
		if(!flag){cout<<"-1\n";continue;}
		ll mx=0;
		fore(i,0,SZ(c)){
			ll z=-1;
			fore(j,(!i?0:c[i-1].fst),c[i].snd){
				mx=max(mx,a[j]);
				if(is[j])z=j;
			}
			ll mxi=0;
			fore(j,c[i].snd,c[i].fst)mxi=max(mxi,a[j]);
			if(mx<mxi){
				if(z==-1)flag=0;
				else {
					a[z]=max(a[z],mxi);
				}
			}
			//cout<<i<<": "<<c[i].fst<<" "<<c[i].snd<<": "<<mx<<" "<<mxi<<" "<<z<<"\n";
			//imp(a);
			mx=max(mx,mxi);
			if(is[c[i].fst])a[c[i].fst]=mx+1;
			else flag&=(a[c[i].fst]>mx);
		}
		fore(i,0,n)flag&=a[i]<=m;
		if(!flag)cout<<"-1\n";
		else {
			fore(i,0,n){
				if(i)cout<<" ";
				cout<<a[i];
			}
			cout<<"\n";
		}
	}
	return 0;
}
