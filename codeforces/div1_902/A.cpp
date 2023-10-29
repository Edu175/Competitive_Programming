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

struct pa{
	ll fst,snd;
};
bool operator<(pa a, pa b){
	return a.snd*b.fst<b.snd*a.fst;
}
bool operator!=(pa a, pa b){return a.fst!=b.fst||a.snd!=b.snd;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p; cin>>n>>p;
		ii a[n];
		fore(i,0,n)cin>>a[i].fst;
		fore(i,0,n)cin>>a[i].snd;
		sort(a,a+n);
		reverse(a,a+n);
		ll mn=1e10;
		multiset<pa>st={{1,p}};
		ll c=n-1,res=p;
		fore(i,0,n)st.insert({a[i].fst,a[i].snd});
		ll w=0;
		ll ans=1e10;
		vector<ll>vis(n);
		for(auto i:a){
			cout<<i.fst<<","<<i.snd<<" ";
		}
		cout<<endl;
		while(c>0){
			cout<<c<<" "<<res<<endl;
			
			while(w<n&&a[w].fst>=c){
				if(vis[w]){
					w++;
					continue;
				}
				mn=min(a[w].snd,mn);
				cout<<"w "<<w<<endl;
				st.erase(st.lower_bound({a[w].fst,a[w].snd}));
				vis[w]=1,w++;
			}
			for(auto i:st){
				cout<<i.fst<<","<<i.snd<<" ";
			}
			cout<<endl;
			ans=min(ans,res+mn);
			auto f=*prev(st.end());
			res+=f.snd;
			c-=f.fst;
			//cout<<f.fst<<","<<f.snd<<endl;
			if(f!=pa({1,p}))st.erase(st.lower_bound(f)),vis[];
		}
		cout<<min(ans,res)<<"\n";
		cout<<"\n";
	}
	return 0;
}
