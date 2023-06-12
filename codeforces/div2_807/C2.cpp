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
		ll n,c,q; cin>>n>>c>>q;
		string s; cin>>s;
		ll l[c+1], r[c+1];
		l[0]=0;
		r[0]=n-1;
		ll pos[c+1];
		pos[0]=0;
		ll sumpos=n;
		fore(i,1,c+1){
			cin>>l[i]>>r[i];
			l[i]--;
			r[i]--;
			pos[i]=sumpos;
			sumpos+=r[i]-l[i]+1;
		}
		//imp(pos);
		while(q--){
			ll k; cin>>k;
			k--;
			while(k>=n){
				//cout<<k<<" ";
				ll it=upper_bound(pos,pos+(c+1),k)-pos-1;
				k-=pos[it];
				k+=l[it];
			}
			//cout<<k<<"\n";
			cout<<s[k]<<"\n";
		}
	}
	return 0;
}
