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
string rev(string s){
	reverse(ALL(s));
	return s;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n; vector<string> a(n);
		map<string,pair<ll,ll>> m;
		ll res=0;
		fore(i,0,n){
			cin>>a[i];
			if(rev(a[i])==a[i])res=1;
			if(!m.count(a[i]))m[a[i]].fst=i;
			m[a[i]].snd=i;
		}
		/*cout<<"return";
		return 0;*/
		if(res){
			cout<<"YES\n";
			continue;
		}
		for(auto i:a){
			//cout<<rev(i)<<" ";
			if(m.count(rev(i))){
				res=1;
				//cout<<"true";
				break;
			}
		}
		//cout<<"\n";
		if(res){
			cout<<"YES\n";
			continue;
		}
		fore(i,0,SZ(a)){
			if(SZ(a[i])==3){
				string r0=a[i];
				string r1=rev(a[i]);
				r0.pop_back();
				reverse(ALL(r0));
				r1.pop_back();
				if(m.count(r1)&&m[r1].fst<i){
					res=1;
					break;
				}
				if(m.count(r0)&&m[r0].snd>i){
					res=1;
					break;
				}
			}
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	 return 0;
}

