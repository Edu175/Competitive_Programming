ll pos(ll i, ll v){
	ll p=lower_bound(hay)
}
bool can(ll k){
	fore(l,0,n){
		ll r=(l+k)%n;
		ll idx=l;
		for(auto v:a[idx]){
			ll pos=lower_bound(ALL(hay[v]),ii({l,-1}))
			-hay[v].begin();
			if(pos>=SZ(hay[v])||hay[v][pos].fst!=l)continue;
			
			vv 
			vector<tuple<ll,ll,ll>>cond;
			ll flag=1;
			if(l<r){
				fore(i,l,r){
					ll p=pos(i,v);
					cond.pb({1,p,SZ(a[i])});
					flag&=p!=-1;
				}
			}
			else {
				fore(i,l,n){
					ll p=pos(i,v);
					cond.pb({1,pos(i,v),SZ(a[i])});
					flag&=p!=-1;
				}
				fore(i,0,r){
					ll p=pos(i,v),md=SZ(a[i]);
					cond.pb({1,(pos(i,v)-1+md)%md,md});
					flag&=p!=-1;
				}
			}
			if(flag){
				auto ans=crt(cond);
				if(ans.snd!=-1)return 1;
			}
		}
	}
	return 0;
}