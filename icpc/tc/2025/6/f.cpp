#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll v[26];
		mset(v,0);
		for(auto x:s) v[x-'a']++;
		vv aux;
		int idx = -1;
		fore(i,0,26){
			if(v[i]) aux.pb(i);
			if(v[i] == 1) idx = i;
		}
		if(idx!=-1){
			cout<<"YES\n";
			cout<<char('a'+idx);
			v[idx]--;
			fore(i,0,26) fore(j,0,v[i])cout<<char('a'+i);
			cout<<"\n";
			continue;
		}
		if(SZ(aux) <= 2){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		cout<<char('a' + aux[0]);
		cout<<char('a' + aux[1]);
		cout<<char('a' + aux[2]);
		v[aux[0]]--;
		v[aux[1]]--;
		v[aux[2]]--;
		fore(i,0,26) fore(j,0,v[i])cout<<char('a'+i);
		cout<<"\n";
	}
	return 0;
}