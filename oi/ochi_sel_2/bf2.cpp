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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main(){FIN;
	ll n,b[2]; cin>>n>>b[0]>>b[1];
	//assert(n>10&&b[0]>2&&b[1]>2);
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll c[2]={0,0};
	ii p[2]={{0,1},{n-1,-1}};
	ll sz=n;
	vector<ll>is(n,1);
	set<ll>st;
	fore(i,0,n)st.insert(i);
	while(sz){
		//imp(is);
		//imp(st);
		fore(w,0,2){
			//cout<<w<<"\n";
			ll &pos=p[w].fst;
			ll &dir=p[w].snd;
			ll mod=2*sz-2;
			ll v=(sz>1?b[w]%mod+mod:0);
			if(sz==1)v=0;
			while(!is[pos]||v>0){
				//cout<<pos<<" "<<dir<<"  "<<v<<endl;;
				if(pos==0||pos==*st.begin())dir=1;
				if(pos==n-1||pos==*prev(st.end()))dir=-1;
				pos+=dir;
				v-=is[pos];
			}
			c[w]+=a[pos];
		}
		//cout<<"Mario "<<p[0].fst<<" "<<p[0].snd<<endl;
		//cout<<"Bowser "<<p[1].fst<<" "<<p[1].snd<<endl;
		fore(w,0,2)if(is[p[w].fst])sz--,is[p[w].fst]=0,st.erase(p[w].fst);
	}
	//cout<<c[0]<<" "<<c[1]<<"\n";
	if(c[0]>=c[1])cout<<"Mario\n";
	else cout<<"Bowser\n";
	return 0;
}
