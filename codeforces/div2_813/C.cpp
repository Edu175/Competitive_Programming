#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n+1];
		a[n]=n+5;
		vector<vector<ll>>pos(n+1);
		fore(i,0,n)cin>>a[i],pos[a[i]].pb(i);
		ll s=0;
		fore(i,0,n){
			if(a[i]>a[i+1]||pos[a[i]][0]<s){
				s=i+1;
			}
		}
		set<ll>st;
		ll res=0;
		fore(i,0,s){
			if(st.count(a[i])==0){
				res++;
				st.insert(a[i]);
			}
		}
		//cout<<s<<" ";
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
