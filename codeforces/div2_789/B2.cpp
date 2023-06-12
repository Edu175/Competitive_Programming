#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s;
		cin>>s;
		ll l=0,o=0;ll res=0;
		vector<pair<ll,ll>>c0;
		vector<pair<ll,ll>>c1;
		ll pos0=-1;
		ll pos1=-1;
		fore(i,0,n){
			if(s[i]=='0'){
				if(o)o++,c0[pos0].fst++;
				else{
					pos0++;
					c0.pb({1,pos0});
					if(l%2==0)o++,l=0;
					else res++,o+=2,l=0;
				}
			}
			if(s[i]=='1'){
				if(l)l++,c1[pos1].fst++;
				else{
					pos1++;
					c1.pb({1,pos1});
					if(o%2==0)l++,o=0;
					else res++,l+=2,o=0;
				}
			}
		}
		cout<<res<<" ";
		ll r0=res;
		ll b0=0;
		fore(i,0,SZ(c0)){
			if(c0[i].fst%2==1)c0[i].fst--,r0--;
		}
		//sort(ALL(c0));
		for(auto i:c0){
			r0-=i.fst;
			if(r0>=0)b0++;
			else break;
		}
		ll r1=res;
		ll b1=0;
		fore(i,0,SZ(c1)){
			if(c1[i].fst%2==1)c1[i].fst--,r1--;
		}
		//sort(ALL(c1));
		for(auto i:c1){
			r1-=i;
			if(r1>=0)b1++;
			else break;
		}
		ll resb=SZ(c0)+SZ(c1)-(max(b0,b1));
		if(resb<1)resb=1;
		cout<<resb<<"\n";
	}
	return 0;
}
