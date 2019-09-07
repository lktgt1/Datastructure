#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline int max(int a,int b){return a > b ? a : b;};

class BigInteger{
private:
	string val;
public:
	BigInteger(){val = "0";};
	BigInteger(string in){val = in;};
	void set(string in){
		this->val = in;
	}
	void add(string in){
		int posval = 0;
		string newval = "";
		int insz = in.size();
		int valsz = this->val.size();
		int sz = max(insz,valsz);
		for(int i=0;i<sz;i++){
			int inval = i < insz ? in[insz-i-1]-'0' : 0;
			int _val = i < valsz ? val[valsz-i-1]-'0' : 0;
			posval += inval+_val;
			newval += to_string(posval%10);
			posval /= 10;
		}
		if(posval) newval += to_string(posval);
		reverse(newval.begin(),newval.end());
		this->val = newval;
	}
	void show(){
		cout << val;
	}
};