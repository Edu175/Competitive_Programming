#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll c,d,n; cin>>c>>d>>n;
	vector<ll>a(n),b(n);
	vector<ii>v(n);
	fore(i,0,n){
		cin>>a[i]>>b[i];
		v[i]={-a[i]+b[i],i};
	}
	sort(ALL(v));
	priority_queue<ii>us,nus;
	ll sa=0,sb=0,res=0,q=0;
	fore(i,0,n)nus.push({b[i],i});
	vector<ll>is(n);
	fore(i,0,d)sb+=nus.top().fst,is[nus.top().snd]=1,nus.pop(),q++;
	for(auto [k,i]:v){
		if(SZ(us)==c&&q==d)res=max(res,sa+sb);
		if(is[i]){
			sb-=b[i],q--;
			while(SZ(nus)&&is[nus.top().snd]==2)nus.pop();
			if(SZ(nus)){
				sb+=nus.top().fst,is[nus.top().snd]=1,nus.pop(),q++;
			}
		}
		is[i]=2;
		us.push({-a[i],i}); sa+=a[i];
		if(SZ(us)>c)sa-=-us.top().fst,us.pop();
	}
	if(SZ(us)==c&&q==d)res=max(res,sa+sb);
	cout<<res<<"\n";
	return 0;
}
