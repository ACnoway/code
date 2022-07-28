#include<cstdio>
bool read(void){
	char us=getchar();
	while(us!='0'&&us!='1')us=getchar();
	return us=='1';
}

struct node{
		bool fruit;
		int bh;
		node*thelast;
		node*thefirst;
		bool islast;
		bool isfirst;
		node*lst;
		node*nxt;
		node(void){
			thelast=thefirst=this;
			islast=isfirst=false;
			lst=nxt=nullptr;
			bh=0;
		}
		void init(int i,bool k){
			bh=i;
			fruit=k;
		}
		void add(node*x){
			if(lst)lst->nxt=x;
			x->lst=lst;
			x->nxt=this;
			lst=x;
		}
		void deleted(void){
			lst->nxt=nxt;
			nxt->lst=lst;
			if(islast&&!isfirst){
				thefirst->thelast=lst;
				lst->islast=true;
				lst->thelast=lst;
				lst->thefirst=thefirst;
			}
			if(isfirst&&!islast){
				thelast->thefirst=nxt;
				nxt->isfirst=true;
				nxt->thefirst=nxt;
				nxt->thelast=thelast;
			}
		}
			
};
node* buildnode(void){
	return new node;
}
int main(){
//	freopen("list.txt","w",stdout);
//	freopen("us.txt","r",stdin);
	node*st=new node;
	node*lst=new node;
	lst->add(st);
	int n;
	scanf("%d",&n);
	node*usnode;
	bool usbool;
	for(int i=1;i<=n;++i){
		usbool=read();
		usnode=buildnode();
		usnode->init(i,usbool);
		lst->add(usnode);
	}
	node*last;
	last=lst->lst;
	for(usnode=lst->lst;usnode!=st;usnode=usnode->lst){
		if(usnode->nxt&&usnode->fruit^usnode->nxt->fruit){
			usnode->islast=true;
			last=usnode;
		}
		if(usnode->fruit^usnode->lst->fruit){
			usnode->isfirst=true;
			usnode->thelast=last;
			last->thefirst=usnode;
		}
	}
	st->nxt->thelast=last;
	st->nxt->isfirst=true;
	last->thefirst=st->nxt;
	while(st->nxt!=lst){
		usnode=st->nxt;
		while(usnode!=lst){
			printf("%d ",usnode->bh);
			if(!usnode->islast||!usnode->isfirst){
				usnode->deleted();
				usnode=usnode->thelast->nxt;
			}
			else{
				if(usnode->nxt==lst){
					usnode->deleted();
					break;
				}
				if(usnode->lst->islast&&usnode->nxt->isfirst&&usnode->lst->fruit==usnode->nxt->fruit){
					usnode->lst->thefirst->thelast=usnode->nxt->thelast;
					usnode->lst->islast=false;
					usnode->nxt->isfirst=false;
					usnode->nxt->thelast->thefirst=usnode->lst->thefirst;
				}
				usnode->deleted();
				usnode=usnode->nxt;
			}
		}
		printf("\n");
	}
	return 0;
}