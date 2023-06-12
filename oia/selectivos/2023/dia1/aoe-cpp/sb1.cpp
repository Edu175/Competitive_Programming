#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
set<ll>st;
void inicializar(int N) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

vector<int> tiempo(int t) {
	//cout<<"tiempo\n";
	vector<int> a,res;
	for(auto i:st)a.pb(i);
	ll n=SZ(a);
	priority_queue<pair<ll,pair<ll,ll>>>pq;
	vector<pair<ll,ll>>dif;
	fore(i,1,SZ(a))pq.push({-(a[i]-a[i-1]),{i-1,i}});
	set<ll>av;
	fore(i,0,n)av.insert(i);
	//imp(av);
	//cout<<t<<"\n";
	while(SZ(pq)){
		auto i=pq.top(); pq.pop();
		ll s=i.snd.fst,e=i.snd.snd;
		//cout<<-i.fst<<" "<<s<<" "<<e<<": "<<(!av.count(s)||!av.count(e))<<" "<<(-i.fst<=t)<<"\n";
		if(!av.count(s)||!av.count(e))continue;
		if(-i.fst<=t){
			res.pb(a[s]),res.pb(a[e]);
			//cout<<"puse "<<a[s]<<" "<<a[e]<<"\n";
			av.erase(s),av.erase(e);
			//imp(av);
			auto lwb=av.lower_bound(s);
			//cout<<*lwb<<"\n";
			if(lwb!=av.begin()&&lwb!=av.end()){
				ll r=*lwb;
				lwb--;
				ll l=*lwb;
				//cout<<l<<" "<<r<<"\n";
				pq.push({-(a[r]-a[l]),{l,r}});
			}
		}
	}
	return res;
}

vector<int> jugador(int e) {
	vector<int>res;
	if(st.count(e))res.pb(e),res.pb(e),st.erase(e);
	else st.insert(e);
	return res;
}
