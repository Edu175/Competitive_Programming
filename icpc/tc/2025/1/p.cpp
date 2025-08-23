#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int maxn = 2e5+100;
ll a[2][maxn];
ll vis[maxn];
ll h[maxn][2];
vv rta,arr1,arr2;

ll get_pos(int c, int num){
	if(a[0][c]==num) return 0;
	else if(a[1][c] == num) return 1;
	return -1;
}
ll get_otro(int c, int num){
	if(a[0][c] == num) return a[1][c];
	if(a[1][c] == num) return a[0][c];
	return -1;
}
ll otra_col(int num, int c){
	if(h[num][0] == c) return h[num][1];
	if(h[num][1] == c) return h[num][0];
	return -1;
}


void f(int c, int num, int prepos){
	// cout<<"ENTRANDO EN "<<c<<" "<<num<<" "<<prepos<<"\n";
	vis[c] = 1;
	int newnum, newpos, pos;	
	if(num ==-1){
		newnum = a[0][c];
		newpos = 0;
	}
	else{
		pos = get_pos(c,num);
		newpos = 1 ^ pos;
		newnum = get_otro(c,num);
		if(pos == prepos){
			arr1.pb(c);
			newpos^=1;
		}
		else{
			arr2.pb(c);
		}
	}
	ll oc = otra_col(newnum,c);
	// cout<<"SALIENDO A "<<oc<<" "<<newnum<<" "<<newpos<<"\n";
	assert(oc!=-1 && newnum !=-1 && newpos!=-1);
	if(!vis[oc])f(oc,newnum,newpos);
}

void limpiar(int n){
	fore(i,0,n+50){
		
		h[i][0] = -1;
		h[i][1] = -1;
		a[0][i] = 0;
		a[0][i] = 0;
		vis[i] = 0;
	}
	
}

int main(){
	int t; cin>>t;
	fore(i,0,maxn){
		h[i][0] = -1;
		h[i][1] = -1;
	}
	while(t--){
		// limpiar();
		int n; cin>>n;
		fore(i,0,n){
			cin>>a[0][i];
		}
		fore(i,0,n) cin>>a[1][i];
		bool flag = false;
		fore(i,0,n){
			fore(j,0,2){
				if(h[a[j][i]][0] == -1) h[a[j][i]][0] = i;
				else if(h[a[j][i]][1] == -1) h[a[j][i]][1] = i;
				else flag = true;
			}
		}
		// cout<<"a : \n";
		// fore(i,0,n) cout<<a[0][i]<<" ";
		// cout<<"\n";
		// fore(i,0,n) cout<<a[1][i]<<" ";
		// cout<<"\n----------------------------\n";
		// cout<<"h: \n";
		// fore(i,1,n+1){
		// 	cout<<h[i][0]<<" ";
		// }
		// cout<<"\n";
		// fore(i,1,n+1) cout<<h[i][1]<<" ";
		// cout<<"\n-------------------\n";
		if(flag){
			cout<<"-1\n";
			limpiar(n);
			continue;
		}
		fore(i,0,n){
			if(!vis[i]){
				f(i,-1,0);
				arr2.pb(i);
				if(SZ(arr1) < SZ(arr2)) for(auto x:arr1) rta.pb(x);
				else for(auto x:arr2) rta.pb(x);
				arr1.clear();
				arr2.clear();
			}
		}
		cout<<SZ(rta)<<"\n";
		for(auto x:rta) cout<<x+1<<" ";
		cout<<"\n";
		limpiar(n);
		rta.clear();
	}
}


