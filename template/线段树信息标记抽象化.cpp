template<class T,const int sz>
class SegTree{
    private:
        inline int lc(int x){return x<<1;}
        inline int rc(int x){return (x<<1)+1;}
        class Tag{
            public:
                
                Tag(){
                    
                }
                void clear(){*this=Tag();}
                void apply(const Tag &_x){
                    
                }
        };
        class Info{
            public:
                
                Info(){
                    
                }
                void apply(const Tag &_x,int len){
                    
                }
                Info operator + (const Info &_x)const{
                    return Info(
                        
                    );
                }
        };
        class Node{
            public:
                int l,r;
                Info val=Info();
                Tag tg=Tag();
        }tr[sz<<2];
        void update(int p,Tag k){
            tr[p].val.apply(k,tr[p].r-tr[p].l+1),tr[p].tg.apply(k);
        }
        void push_down(int p){
            update(lc(p),tr[p].tg);
            update(rc(p),tr[p].tg);
            tr[p].tg.clear();
        }
        void push_up(int p){
            tr[p].val=tr[lc(p)].val+tr[rc(p)].val;
        }
    public:
        void build(int p,int l,int r){
            tr[p].l=l,tr[p].r=r;
            if(l==r){
                tr[p].val.apply(Tag(),1);
                return ;
            }
            int mid=(l+r)>>1;
            build(lc(p),l,mid);
            build(rc(p),mid+1,r);
            push_up(p);
        }
        void Modify(int p,int l,int r,Tag k){
            if(l<=tr[p].l && tr[p].r<=r){
                update(p,k);
                return ;
            }
            int mid=(tr[p].l+tr[p].r)>>1;
            push_down(p);
            if(l<=mid)	Modify(lc(p),l,r,k);
            if(r>=mid+1)	Modify(rc(p),l,r,k);
            push_up(p);
        }
        Info Query(int p,int l,int r){
            if(l<=tr[p].l && tr[p].r<=r) return tr[p].val;
            int mid=(tr[p].l+tr[p].r)>>1;
            push_down(p);
            Info ret=Info();
            if(l<=mid)	ret=ret+Query(lc(p),l,r);
            if(r>=mid+1)	ret=ret+Query(rc(p),l,r);
            return ret;
        }
};
