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

ll h = 0;
const int MAXH = 2e3+5;
ll vis[MAXH][MAXH];

bool put(int he, int w, int x, int y){
	// cout<<"arranco a poner algo nuevo\n";
	fore(i,x,x+he)fore(j,y,y+w){
		// cout<<"pongo en "<<i<<" "<<j<<"\n";
		// cout<<(i>=h || j>=h)<<" "<<h<<"   "<<vis[i][j]<<"\n";
		if(i>=h || j>=h) return false;
		if(vis[i][j]) return false;
		vis[i][j] = 1;
	}	
	return true;
}

bool can(vector<ii> &v){
	mset(vis,0);
	ll k = 0;
	fore(i,0,h)fore(j,0,h)if(!vis[i][j]){
		if(!put(v[k].fst,v[k].snd,i,j)) return false;
		k++;
	}
	return true;
}


int main(){
	JET
	vector<ii> v(4);
	ll ar = 0;
	fore(i,0,4){
		cin>>v[i].fst>>v[i].snd;
		ar+=v[i].fst*v[i].snd;
	}
	while(h*h<ar)h++;
	if(h*h!=ar){
		cout<<0<<"\n";
		return 0;
	}
	// cout<<"asndoasndo "<<h<<"\n";
	fore(mk,0,1<<4){
		fore(i,0,4)if((1<<i)&mk)swap(v[i].fst,v[i].snd);
		vector<ii> v2 = v; sort(ALL(v2));
		do{
			if(can(v2)){
				cout<<1<<"\n";
				return 0;
			}
			// return 0; //sacar lpm;
		}while(next_permutation(ALL(v2)));		
		fore(i,0,4)if((1<<i)&mk)swap(v[i].fst,v[i].snd);	
	}	
	cout<<0<<"\n";
	return 0;
}