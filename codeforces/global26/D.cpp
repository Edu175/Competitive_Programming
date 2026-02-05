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
const ll INF=1e18;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		vv oc(300);
		ll p=-1;
		ll n=SZ(s);
		fore(i,0,n){
			oc[s[i]]++;
			if(p==-1&&s[i]!='a')p=i;
		}
		if(p==-1){
			cout<<n-1<<"\n";
			continue;
		}
		ll res=0;
		fore(d,1,n+1){
			ll fg=1;
			vv dst(300);
			fore(i,'b','z'+1){
				fg&=oc[i]%d==0;
				dst[i]=oc[i]/d;
			}
			if(!fg)continue;
			ll cant=0,r=-1; // cant of positive
			fore(i,'b','z'+1)cant+=dst[i]>0;
			fore(i,0,n)if(s[i]!='a'){
				cant-=!(--dst[s[i]]);
				if(dst[s[i]]<0){fg=0;break;}
				if(cant==0){r=i+1;break;}
			}
			if(!fg)continue;
			assert(r!=-1&&s[r-1]!='a');
			string t=s.substr(p,r-p);
			ll lg=p,rg=-1,mng=INF;
			for(ll x=r;fg;){
				ll pp=-1;
				fore(i,x,n)if(s[i]!='a'){pp=i;break;}
				if(pp==-1){
					rg=n-x;
					break;
				}
				fg&=s.substr(pp,SZ(t))==t;
				mng=min(mng,pp-x);
				x=pp+SZ(t);
			}
			if(!fg)continue;
			ll cur=0;
			fore(l,0,lg+1){
				ll R=min(rg,mng-l);
				cur+=max(R+1,0ll);
			}
			res+=cur;
		}
		cout<<res<<"\n";
	}
	return 0;
}
