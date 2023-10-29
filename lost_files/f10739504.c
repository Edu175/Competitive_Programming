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
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll bit[35];
		vector<ll> pos[35];
		fore(i,0,35)bit[i]=0;
		ll res;
		bool flag=0;
		fore(i,0,n){
			cin>>a[i];
			fore(j,0,31){
				if(((1ll<<j)&a[i])==(1ll<<j))bit[j]++,pos[j].pb(i);
				if(bit[j]>=2)flag=1;
			}
		}
		if(!flag)cout<<"NO\n";
		else{
			cout<<"YES\n";
			fore(i,0,35){
				if(bit[i]>=2)res=i;
				break;
			}
			bool flag2=1;
			ll k=SZ(pos[res]);
			fore(i,0,SZ(pos[res])){
				ll l,r;
				l=pos[res][i]+1;
				r=pos[res][i+1];
				if(pos[res][SZ(pos[res])-1]!=n-1)r=n;
				else flag2=0,k--;
				if(i==0){
					if(pos[res][0]!=0)cout<<k+1<<"\n"<<1<<l-1<<"\n";
					else cout<<k<<"\n";
				}
				if(i!=pos[res][SZ(pos[res])-1]||flag2)cout<<l<<" "<<r<<"\n";
			}
		}
	}
	return 0;
}
