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


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		set<ll>st;
		vv a(2*n);
		fore(i,0,2*n)cin>>a[i],st.insert(a[i]);
		sort(ALL(a));
		// imp(a) cout<<endl;
		ll sum=0;
		ll m=2*n;
		fore(i,0,m)sum+=(i&1?a[i]:-a[i]);
		vv sig(m,-1);
		fore(i,0,m)if(i&1)sig[i]=1;
		auto get=[&](){
			vv ret(2*n+1);
			ret[0]=sum;
			ll pos=1;
			fore(i,0,m)if(sig[i]==1){ret[pos]=a[i];pos+=2;}
			pos=2;
			fore(i,0,m)if(sig[i]==-1){ret[pos]=a[i];pos+=2;}
			return ret;
		};
		// if(1){
		if(m>=12){
			// cout<<"pinga"<<endl;
			ll p=m-1,q=0;
			while(st.count(sum)){
				if(p==m-1||sig[p+1]==1){q++;p=m-1-2*q;}
				// cout<<sum<<": ";imp(sig)
				// cout<<p<<" "<<q<<endl;
				assert(sig[p]==1&&sig[p+1]==-1);
				sum+=-2*a[p]+2*a[p+1];
				swap(sig[p],sig[p+1]);
				p++;
			}
			auto ret=get();
			imp(ret)
		}
		else {
			ll good=0;
			sort(ALL(sig));
			do{
				sum=0;
				fore(i,0,m)sum+=sig[i]*a[i];
				if(sum>0&&!st.count(sum)){
					auto ret=get();
					imp(ret)
					good=1;
					break;
				}
			}while(next_permutation(ALL(sig)));
			// assert(good);
			if(!good){
				sig[m-1]=-1;
				sort(ALL(sig));
				do{
					sum=0;
					fore(i,0,m)sum+=sig[i]*a[i];
					if(sum<0&&!st.count(-sum)){
						ll p=-1;
						fore(i,0,m)if(sig[i]==-1)p=i;
						sum=-sum;
						swap(sum,a[p]);
						sig[p]=1;
						auto ret=get();
						imp(ret)
						good=1;
						break;
					}
				}while(next_permutation(ALL(sig)));
			}
		}
	}
	return 0;
}
