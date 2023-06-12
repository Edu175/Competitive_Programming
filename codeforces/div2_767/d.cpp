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
ll pali(string s){
	fore(i,0,SZ(s)/2){
		if(s[i]!=s[SZ(s)-i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n; string a[n];
		unordered_map<string,ll>m;
		ll res=0;
		fore(i,0,n){
			cin>>a[i];
			if(pali(a[i]))res=1;
		}
		for(ll i=n-1;i>=0;i--)m[a[i]]=i;
		if(res){
			cout<<"YES\n";
			continue;
		}
		unordered_map<string,ll>mr;
		for(auto i:m){
			string edu=i.fst;
			reverse(ALL(edu));
			mr[edu]=i.snd;
		}
		for(auto i:m){
			for(auto j:mr){
				string ifst=i.fst;
				string jfst=j.fst;
				//cout<<i.snd<<" "<<j.snd<<"\n";
				if(j.snd>i.snd){
					//cout<<ifst<<" "<<jfst<<"\n";
					if(SZ(ifst)==3&&SZ(jfst)!=3)(ifst).pop_back();
					if(SZ(jfst)==3&&SZ(ifst)!=3)(jfst).pop_back();
					//cout<<ifst<<" "<<jfst<<"\n";
					if(ifst==jfst)res=1;
					if(res){
						break;
					}
				}
			}
			if(res){
				break;
			}
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	 return 0;
}

