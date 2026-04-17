#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll hay[55];
string s;
vv res;
void f(ll i){
	if(i==SZ(s)){
		ll did=1,good=1;
		fore(i,1,55){
			if(did&&!hay[i])did=0;
			good&=hay[i]==did;
		}
		if(!good)return;
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
		exit(0);
	}
	ll a=s[i]-'0';
	if(a==0)return;
	auto goif=[&](ll a, ll len){
		if(a<=50&&!hay[a]){
			hay[a]=1;
			res.pb(a);
			f(i+len);
			res.pop_back();
			hay[a]=0;
		}
	};
	goif(a,1);
	if(i+1==SZ(s))return;
	a=a*10+(s[i+1]-'0');
	goif(a,2);
}


int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("joke.in","r",stdin);     freopen("joke.out","w",stdout);
	#endif

	JET
	cin>>s;
	// hay[0]=1;
	f(0);
	assert(0);
	
	return 0;
	
}