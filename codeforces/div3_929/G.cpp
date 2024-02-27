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
	ll t; cin>>t;
	while(t--){
		cout<<"8\n";
		ll n,m,q; cin>>n>>m>>q;
		set<ll> a[2][2];
		while(q--){
			ll i,j; cin>>i>>j; i--,j--;
			string s; cin>>s;
			bool w=s[0]=='c';
			fore(r,0,2){
				if(r){
					ll _i=i,_j=j;
					i=m-1-_j,j=_i;
				}
				fore(b,0,2){
					a[r][b].insert(((i+b)/2+j+w)%2);
				}
			}
			ll res=0;
			fore(r,0,2)fore(b,0,2){
				ll sz=SZ(a[r][b]);
				if(sz==0)res+=2;
				if(sz==1)res+=1;
				
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
