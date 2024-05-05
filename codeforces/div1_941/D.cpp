#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

multiset<ll>st;
void erase(ll x){
	auto it=st.find(x);
	if(it!=st.end())st.erase(it);
}

vector<ll> solve(ll n, vector<ll>a, ll sum){
	//cout<<"\n\nsolve sum "<<sum<<" | "; imp(a);
	st.clear();
	for(auto i:a)st.insert(i);
	erase(sum);
	vector<ll>res(n);
	fore(i,1,n){
		//cout<<i<<": "; imp(st); cout<<endl;
		res[i]=sum-*prev(st.end());
		fore(j,0,i)erase(sum-res[i]-res[j]),erase(sum-res[i]-res[j]);
		erase(sum-2*res[i]);
	}
	//cout<<"res "; imp(res);
	//cout<<"\n\n";
	vector<ll>b;
	fore(i,1,n)b.pb(res[i]-res[i-1]);
	b.pb(sum-res.back());
	return b;
}
vector<ll> solve(ll n, vector<ll>a){ //missing sum
	//cout<<"missing sum\n";
	sort(ALL(a)); reverse(ALL(a));
	ll x=a[0];
	map<ll,ll>mp;
	for(auto i:a)mp[i]++;
	ll y=-1;
	for(auto i:mp)if(i.snd&1)y=i.fst;
	
	/*vector<ll>b;
	fore(i,2,5)b.pb(a[i]);
	ll y=b[1];
	for(auto i:b)if(i!=b[1])y=i;
	imp(b);*/
	//cout<<x<<" "<<y<<"\n";
	ll s1=x-y;
	ll sum=x+s1;
	return solve(n,a,sum);
}
/*void check(ll n, vector<ll>a, vector<ll>b){
	auto rb=b; reverse(ALL(b));
	if(b!=rb){
		cout<<"\nFAIL\n";
		cout<<n<<"\n";
		imp(a);
		imp(b);
		exit(0);
	}
}*/
int main(){FIN;
	vector<vector<ll>>ans;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n*(n+1)/2-1);
		fore(i,0,SZ(a))cin>>a[i];
		sort(ALL(a)); reverse(ALL(a));
		vector<ll>b;
		if(a[0]!=a[1])b=solve(n,a,a[0]);
		else b=solve(n,a);
		//check(n,a,b);
		//ans.pb(b);
		imp(b);
	}
	for(auto i:ans){imp(i);}
	return 0;
}
