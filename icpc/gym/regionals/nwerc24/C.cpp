#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;




int main(){
	JET
	vector<ii> ps(5);
	vv h(5);
	fore(i,0,5){
		cin>>ps[i].fst>>ps[i].snd;
		h[i] = ps[i].snd;
	}
	sort(ALL(ps));sort(ALL(h));
	ll l = ps[0].snd, r = ps[0].snd, acc = ps[0].fst;
	ll rta = 0;
	fore(i,1,5){
		if(acc == ps[i].fst){
			if(l>ps[i].snd){
				rta+=l-ps[i].snd;
				l = ps[i].snd;
			}
			if(r<ps[i].snd){
				rta+=ps[i].snd - r;
				r = ps[i].snd;
			}
		}
		else{
			rta+=ps[i].fst -acc;
			if(ps[i].snd<l){
				rta += l-ps[i].snd;
				r = l;
				l = ps[i].snd;
			}
			else if(ps[i].snd > r){
				rta+=ps[i].snd -r;
				l = r;
				r = ps[i].snd;
			}
			else{
				l = ps[i].snd;
				r = ps[i].snd;
			}
		}
	}
	cout<<rta<<"\n";

	return 0;
}