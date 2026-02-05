#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// mult of 3
// 90 120 60
//  4   5  1

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		vv a;
		vv oc(10);
		ll sum=0;
		fore(i,0,n){
			ll v=s[i]-'0';
			a.pb(v);
			oc[v]++;
			sum+=v;
		}
		if(sum%3){
			cout<<"0 0\n";
			continue;
		}
		if(n==1){
			cout<<1+(a[0]%4==0)+(a[0]%5==0)<<" 0\n";
			continue;
		}
		ll res=0,mn=0;
		fore(nu,0,100){
			vv b={nu/10,nu%10};
			ll s=n-2;
			vv bl(2);
			vv occ=oc;
			fore(j,0,2){
				bl[j]=(a[s+j]==b[j]);
				occ[b[j]]-=bl[j];
			}
			ll bad=0,cost=0,rew=(nu%5==0)+(nu%4==0);
			fore(j,0,2)if(!bl[j]){
				ll ten=a[s+j],nec=b[j];
				if(occ[nec]<=0){bad=1;continue;}
				if(ten==0&&nec==a[0]&&occ[nec]==1){bad=1;break;}
				occ[nec]--;
			}
		}
		res++;
	}
	return 0;
}