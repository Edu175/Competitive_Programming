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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p; cin>>n>>p;
		ll a[n];
		set<ll>st;
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		ll e=1;
		for(int i=n-2;i>=0;i--){
			if(a[i]!=p-1){
				e=a[i]+1;
				break;
			}
		}
		ll j=0,m=0,s=a[n-1];
		for(auto i:st){
			if(j==s)break;
			if(i!=j)m=1;
			j++;
		}
		ll res=0;
		if(m){
			res=p-s;
			st.insert(e);
			st.insert(0);
			vector<ll>v;
			ll w=0;
			for(auto i:st)v.pb(i);
			fore(i,0,SZ(v))if(v[i]==s)w=i;
			j=s-1;
			ll nt=0;
			//imp(v);
			for(int i=w-1;i>=0;i--){
				//cout<<v[i]<<" "<<j<<"\n";
				if(v[i]!=j){
					nt=j;
					break;
				}
				j--;
			}
			res+=nt;
		}
		else{
			vector<ll>v;
			for(auto i:st)v.pb(i);
			j=p-1;
			ll nt=s;
			for(int i=SZ(v)-1;i>=0;i--){
				if(j==s)break;
				if(v[i]!=j){
					nt=j;
					break;
				}
				j--;
			}
			res=nt-s;
		}
		cout<<res<<"\n";//" "<<m<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
