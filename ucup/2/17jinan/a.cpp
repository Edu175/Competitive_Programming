#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll get(char s){
	if(s=='('||s==')')return 0;
	return 1;
}


int main(){
    JET
	ll t; cin>>t;
	while(t--){
		
		string s; cin>>s;
		stack<ii>st;
		ll n=SZ(s);
		vv fa(n,-2);
		fore(i,0,n){
			ll c=get(s[i]);
			if(!SZ(st)||st.top().fst!=c)st.push({c,i});
			else {
				ll j=st.top().snd; st.pop();
				fa[j]=-1;
				if(SZ(st))fa[j]=st.top().snd;
			}
		}
		vector<vv>oc(n,vv(2));
		vv dep(n,-1);
		auto dame=[&](ll x, auto &&dame){
			if(dep[x]!=-1)return dep[x];
			if(fa[x]==-1)return dep[x]=0;
			return dep[x]=dame(fa[x],dame)+1;
		};
		fore(i,0,n)if(fa[i]!=-2){
			oc[dame(i,dame)][get(s[i])]++;
		}
		ll fg=1;
		fore(i,0,n)fg&=oc[i][0]<2&&oc[i][1]<2;
		if(fg)cout<<"Yes\n";
		else cout<<"No\n";
	}
    return 0;
}


// g++ -Wall -Wextra -std=c++17 -D_GLIBCXX_DEBUG -g tempate.cpp -o a
// for i in {a..z}; do cp tempate.cpp $i.cpp;done