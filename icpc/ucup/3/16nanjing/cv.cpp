
ll cv(ll d, ll v, ll p){
	p&=1;
	if(d==0){
		if(v==2&&p==0)return 1;
		if(v==0&&p==1)return 1;
		if(v==0&&p==0)return -1;
		return 0;
	}
	if(d==1){
		if(v==2&&p==1)return 1;
		if(v==0&&p==0)return 1;
		if(v==0&&p==1)return -1;
		return 0;
	}
	if(d==2){
		if(v==2&&p==0)return 1;
		if(v==1&&p==1)return 1;
		if(v==1&&p==0)return -1;
		return 0;
	}
	if(d==3){
		if(v==2&&p==1)return 1;
		if(v==1&&p==0)return 1;
		if(v==1&&p==1)return -1;
		return 0;
	}
}
