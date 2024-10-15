#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> g[100009];
int in[100009];
vector<int> ceros;
set<ii> aristas;
int cnt;
int k;
int n;
set<int> usados;
priority_queue<int> pq;
void mintop(){
	priority_queue<int> pq;
	int inl[n];
	fore(i,0,n){
		inl[i]=0;
	}
	fore(i,0,n) fore(j,0,SZ(g[i])){
		inl[g[i][j]]++;
	}
	fore(i,0,n){
		if(inl[i]==0) pq.push(-i);
	}
	while(!pq.empty()){
		int x=-pq.top();
		pq.pop();
		cout<<x+1;
		fore(i,0,SZ(g[x])){
			inl[g[x][i]]--;
			if(inl[g[x][i]]==0) pq.push(-g[x][i]);
		}	
		if(!pq.empty())cout<<" ";
	}
}

void f(){
	if(SZ(ceros)==0){
		cnt=k;
		return;
	}
	sort(ALL(ceros));
	int i=0;
	//cout<<"#######\n";
	/* fore(j,0,SZ(ceros)){
		cout<<ceros[j]<<" ";
	} */
	//cout<<"\n"
	
	while(i<SZ(ceros)-1 && cnt<k){
		if(cnt==k-1){
			auto it = usados.lower_bound(ceros[i]);
			int aux=*it ;
			it--;
			int aux2=*it;
			aristas.insert({aux,ceros[i]});
			aristas.insert({ceros[i],aux2});
			aristas.erase({aux,aux2});
			cnt++;
			in[ceros[i]]++;
			i++;
			usados.insert(ceros[i]);
		}
		else{
			auto it = usados.lower_bound(ceros[i]);
			int aux=*it ;
			it--;
			int aux2=*it;
			aristas.insert({aux,ceros[i]});
			aristas.insert({ceros[i],aux2});
			aristas.erase({aux,aux2});
			cnt++;
			in[ceros[i]]++;
			i++;
			usados.insert(ceros[i]);
		}
		
		
	}

	if(cnt<k){
		int x=ceros[i];
		ceros.clear();
		fore(i,0,SZ(g[x])){
			in[g[x][i]]--;
			if(in[g[x][i]]==0) ceros.pb(g[x][i]);
		}
	}
	return;
}

int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("graph.in","r",stdin);     freopen("graph.out","w",stdout);
	#endif
	int m;
	cin>>n>>m>>k;
	fore(i,0,m){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		in[b]++;
	}
	fore(i,0,n){
		if (in[i]==0) ceros.pb(i);
	} 
	while(cnt<k){
		f();
	}
	for(auto x : aristas){
		g[x.fst].pb(x.snd);
	}
	mintop();
	cout<<"\n";	
	cout<<SZ(aristas)<<"\n";
	for(auto x : aristas){
		cout<<x.fst<<" "<<x.snd<<"\n";
	}
	
	return 0;
}