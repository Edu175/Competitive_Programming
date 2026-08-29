#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool formar(int h, int w, vector<ii> v){
	if(SZ(v) == 1)return v[0] == (ii){h,w} || v[0] == (ii){w,h};
	auto it = v.begin();
	while(it!=v.end()){
		fore(k,0,2){	
			fore(j,0,2){
				if((*it).fst == w){
					ii aux = *it;
					v.erase(it);
					return formar(h-aux.snd,w,v);
				}
				swap((*it).fst,(*it).snd);
			}
			swap(h,w);
		}
		it++;
	}
	if(SZ(v) < 4) return false;
	sort(ALL(v)); ll i = 1;
	// cout<<"asdnoasdnoad"<<endl;
	do{
		fore(j,0,5){
			if(j == 4 && i == 1) return true;
			ii nxt =v[(j+1)%4];
			ll act = (i ? v[j].fst:v[j].snd);
			if(act + nxt.fst == h) i = 1;
			else if(act + nxt.snd == h) i = 0;
			else break;
		}
	}while(next_permutation(ALL(v)));
	return false;
}

int main(){
	JET
	vector<ii> v(4);
	ll ar = 0;
	fore(i,0,4){
		cin>>v[i].fst>>v[i].snd;
		ar+=v[i].fst*v[i].snd;
	}
	ll sq = 0;
	while(sq*sq<ar)sq++;
	
	if(sq*sq!=ar){
		cout<<0<<"\n";
		return 0;
	}
	
	cout<<(formar(sq,sq,v) ? "1":"0")<<"\n";	
	
	return 0;
}