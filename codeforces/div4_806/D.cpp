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
		string a[n];
		set<string>st;
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		bool res[n];
		fore(i,0,n){
			res[i]=0;
			fore(j,0,SZ(a[i])-1){
				string l,r;
				fore(h,0,j+1)l.pb(a[i][h]);
				fore(h,j+1,SZ(a[i]))r.pb(a[i][h]);
				if(st.count(l)&&st.count(r)){
					res[i]=1;
					break;
				}
			}
		}
		fore(i,0,n)cout<<res[i];
		cout<<"\n";
	}
	return 0;
}
