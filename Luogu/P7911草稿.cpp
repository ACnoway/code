		if(sscanf(s,"%d.%d.%d.%d:%d",&a,&b,&c,&d,&e)!=5){
			cout<<"ERR"<<endl;
			continue;
		}
		if(a<0||a>255||b<0||b>255||c<0||c>255||d<0||d>255||e<0||e>65535){
			cout<<"ERR"<<endl;
			continue;
		}
		string ad=s,op=opt;
		int x=0;
		bool flag=true;
		for(int i=0;i<ad.size()-1;++i){
			if(ad[i]<'0'||ad[i]>'9'){
				x=0;
				continue;
			}
			x=(x<<1)+(x<<3)+(s[i]^48);
			if(x==0&&ad[i+1]>='0'&&ad[i+1]<='9'){
				flag=false;
				break;
			}
		}
		if(ad[ad.size()-1]<'0'||ad[ad.size()-1]>'9') flag=false;
		if(flag==false){
			cout<<"ERR"<<endl;
			continue;
		}