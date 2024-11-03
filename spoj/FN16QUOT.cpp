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

int main(){FIN;
	ll n; 
	while(cin>>n){
		vv a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		if(sum&1){
			cout<<"no quotation\n";
			continue;
		}
		auto can=[&](ll k)->bool{
			vv b=a;
			ll l=0,r=n-1;
			while(k>0&&l<=r){
				if(b[l]==0)l++;
				else if(b[r]==0)r--;
				else {
					if(b[l]<k)return 0;
					b[l]-=k;
					if(b[r]<k)return 0;
					b[r]-=k;
					k--;
				}
			}
			return (l<=r);
		};
		ll res=-1;
		for(ll k=105;k;k--){
			if(can(k)){res=k;break;}
		}
		if(res==1&&sum!=2)res=-1;
		if(res==-1){
			cout<<"no quotation\n";
			continue;
		}
		cout<<res<<"\n";
	}
	return 0;
}
