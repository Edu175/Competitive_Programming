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
		ll sum=0;
		fore(i,0,n){
			ll v=s[i]-'0';
			a.pb(v);
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
		vv b={a[0]},oc(10);
		fore(i,1,n-2)if(oc[a[i]]<2){
			oc[a[i]]++;
			b.pb(a[i]);
		}
		fore(i,max(n-2,1ll),n)b.pb(a[i]);
		n=SZ(b);
		ii res={0,0};
		fore(i,0,n)fore(j,0,n)fore(bo,0,2){
			vv c=b;
			
			ll u=n-1,v=n-2;
			if(bo)swap(u,v);
			
			ll cost=(i!=u)+(j!=v);
			swap(c[i],c[u]);
			swap(c[j],c[v]);
			if(!c[0])continue;
			ll nu=c[n-2]*10+c[n-1];
			ll rew=(nu%4==0)+(nu%5==0);
			ii cur={rew,-cost};
			res=max(res,cur);
		}
		cout<<res.fst+1<<" "<<-res.snd<<"\n";
	}
	return 0;
}