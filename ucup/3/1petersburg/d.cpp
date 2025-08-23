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
typedef pair<ii,ll> nd;
const ll maxn=200;
bool b[maxn],t[maxn]; ll p[maxn];
ii a[maxn], rta[maxn];
ii operator +(ii c, ii d){
	c.fst+=d.fst;
	c.snd+=d.snd;
	if(c.snd>=60){
		c.snd-=60;
		c.fst++;
	}
	return c;
}
void tx(ii h){
	if(h.fst<10) cout<<'0';
	cout<<h.fst<<':';
	if(h.snd<10) cout<<'0';
	cout<<h.snd;
}
bool quer(ii h,ll i){
	assert(h<=ii({23,59}));
	assert(h.snd<=60);
	cout<<"at ";tx(h);cout<<" check "<<i+1<<endl;
	string s;cin>>s;
	return (s.back()=='e')^b[i];	
}
void neg(ii &h){
	h.fst=-h.fst,h.snd=-h.snd;
}
ii tr(ii h, bool bi){
	if(bi){
		h.fst-=12;
		if(h.fst<0) h.fst+=24;
	}
	assert(h<=ii({23,59}));
	assert(h.snd<=60);
	assert(h>=ii({0,0}));
	return h;
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		b[i]=0;
		b[i]=quer({0,0},i); p[i]=2; a[i]={0,0};
	}
	priority_queue <nd> pq;
	fore(i,0,n) pq.push((nd){(ii){0,-48},i});
	while(SZ(pq)){
		auto [h,i]=pq.top(); pq.pop(); neg(h); 
		assert((p[i]++)<=50);
		// cerr<<i<<" "<<b[i]<<" i,b\n";
		bool aux=quer(h,i);
		if(t[i]){
			if(!aux){rta[i]=h; continue;}
			h=h+(ii){0,1};
			if(h==(ii){24,0}){
				rta[i]=(ii){0,0};
				continue;
			}
			// cerr<<"avantif\n";
		}
		else {
			if(aux){
				t[i]=1;
				h=a[i]+(ii){12,1};
				// cerr<<"salto\n"; 
			}
			else{
				a[i]=h;
				h=h+(ii){0,50-p[i]};
				// cerr<<"avantic\n";	
			}
		}
		neg(h);
		pq.push((nd){h,i});
	}
	cout<<"answer"<<endl;
	fore(i,0,n){tx(tr(rta[i],b[i])); cout<<endl;}
		
	return 0;
}
