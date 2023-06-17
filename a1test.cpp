#include <iostream>
#include <vector>
using namespace std;

struct node{
    int a;
    vector<int> b;
    node():a(0){};
    node work(const node &x){
        return *this-x;
    }
}c,d;
int main() {
    c.work();
	return 0;
}
