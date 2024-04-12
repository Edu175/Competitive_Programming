#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<ll> kmppre(string t){ // r[i]: longest border of t[0,i)
	vector<ll> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	//cout<<t<<": "; imp(r);
	return r;
}
int main(){FIN;
	string s; cin>>s;
	ll n=SZ(s);
	ll m; cin>>m;
	vector<string>a(m);
	fore(i,0,m)cin>>a[i];
	ll res=0;
	for(auto t:a){
		if(SZ(t)==1)continue;
		auto l=kmppre(t+"$"+s);
		auto w=s+"$"+t;
		reverse(ALL(w));
		auto r=kmppre(w);
		reverse(ALL(r));
		//imp(l);
		//imp(r);
		assert(l[SZ(t)+1]<=0);
		
		vector<ll>ml(n),mr(n+1);
		fore(i,1,n)ml[i]=max(ml[i-1],l[SZ(t)+1+i]);
		for(ll i=n-1;i>=0;i--)mr[i]=max(mr[i+1],r[i]);
		ll flag=0;
		fore(i,0,n)flag|=ml[i]+mr[i]>=SZ(t);
		res+=flag;
	}
	cout<<res<<"\n";
	return 0;
}

