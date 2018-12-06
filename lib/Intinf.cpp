#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

namespace ece309{
class Intinf{
protected:
	int value;// numerical value of Intinf if it's not infinity, or if it is, its sign
	bool infinity; //true if Intinf is a type of infinity, sign is determined by sign of value
	
	//don't set value to 0 if infinity is 1, the sign gets confused b/c 0 has no sign
	
public:
	Intinf(int x, bool i){
		value = x;
		infinity = i;
	}
	
	void print(){
		if(infinity){
			if(value >= 0){
				printf("+infinity");
			}else{
				printf("-infinity");
			}
		}else{
			printf("%d",value);
		}
	}
	
	Intinf operator=(const int &rhs) {
		//Intinf retIntinf(rhs, 0);
		
		this->value = rhs;
		this->infinity = 0;
		
		return *this;
	}
	
	Intinf operator+(const Intinf &rhs) const {
		Intinf retIntinf(0, 0);
		
		if(rhs.infinity){
			if(rhs.value >=0){
				if(infinity){
					if(value >=0){
						// +inf + +inf
						retIntinf.value = 1;
						retIntinf.infinity = 1;
					}else{
						// +inf + -inf
						retIntinf.value = 0;
						retIntinf.infinity = 0;
					}
				}else{
					// +inf + #
					retIntinf.value = 1;
					retIntinf.infinity = 1;
				}
			}else{
				if(infinity){
					if(value >=0){
						// -inf + +inf
						retIntinf.value = 0;
						retIntinf.infinity = 0;
					}else{
						// -inf + -inf
						retIntinf.value = -1;
						retIntinf.infinity = 1;
					}
				}else{
					// -inf + #
					retIntinf.value = -1;
					retIntinf.infinity = 1;
				}
			}
		}else{
			if(infinity){
				if(value>=0){
					// # + +inf
					retIntinf.value = 1;
					retIntinf.infinity = 1;
				}else{
					//# + -inf
					retIntinf.value = -1;
					retIntinf.infinity = 1;
				}
			}else{
				// # + #
				retIntinf.value = value + rhs.value;
				retIntinf.infinity = 0;
			}
		}
		
		return retIntinf;
	}
	
	Intinf operator-(const Intinf &rhs) const {
		Intinf retIntinf(0, 0);
		
		if(rhs.infinity){
			if(rhs.value >=0){
				if(infinity){
					if(value >=0){
						// +inf - +inf
						retIntinf.value = 1;
						retIntinf.infinity = 1;
					}else{
						// +inf - -inf
						retIntinf.value = 1;
						retIntinf.infinity = 1;
					}
				}else{
					// +inf - #
					retIntinf.value = 1;
					retIntinf.infinity = 1;
				}
			}else{
				if(infinity){
					if(value >=0){
						// -inf - +inf
						retIntinf.value = -1;
						retIntinf.infinity = 1;
					}else{
						// -inf - -inf
						retIntinf.value = -1;
						retIntinf.infinity = 1;
					}
				}else{
					// -inf - #
					retIntinf.value = -1;
					retIntinf.infinity = 1;
				}
			}
		}else{
			if(infinity){
				if(value>=0){
					// # - +inf
					retIntinf.value = -1;
					retIntinf.infinity = 1;
				}else{
					//# - -inf
					retIntinf.value = 1;
					retIntinf.infinity = 1;
				}
			}else{
				// # - #
				retIntinf.value = value - rhs.value;
				retIntinf.infinity = 0;
			}
		}
		
		return retIntinf;
	}
	
	Intinf operator*(const Intinf &rhs) const {
		Intinf retIntinf(0, 0);
		if( ( (!value && !infinity) || (!rhs.value && !rhs.infinity) ) ){// zero times something
			retIntinf.infinity = 0;
			retIntinf.value = 0;
		}else if(rhs.infinity == 1 || infinity){// one operand is infinity
			retIntinf.infinity = 1;
			retIntinf.value = value * rhs.value;
		}else{// no infinities and no zeros in operands
			retIntinf.infinity = 0;
			retIntinf.value = value * rhs.value;
		}
		return retIntinf;
	}
	
	Intinf operator/(const Intinf &rhs) const {
		Intinf retIntinf(0, 0);
		if(infinity){// +-inf / +-something
			retIntinf.infinity = 1;
			retIntinf.value = value / rhs.value;
		}else if(rhs.infinity){// +-something / +-inf
			retIntinf.infinity = 0;
			retIntinf.value = 0;
		}else{// +-something / +-something
			retIntinf.infinity = 0;
			retIntinf.value = value / rhs.value;
		}
		return retIntinf;
	}
	
	bool operator==(const Intinf &rhs) const {
		if(rhs.infinity || infinity){
			return false;
		}else{
			if(value == rhs.value){
				return true;
			}else{
				return false;
			}
		}
	}
	
	bool operator>(const Intinf &rhs) const {
		if(infinity && rhs.infinity){// +-inf > +-inf
			return false;
		}else if(infinity && !rhs.infinity && value>=0){// +inf > +-something
			return true;
		}else if(infinity && !rhs.infinity && value<0){// -inf > +-something
			return false;
		}else if(!infinity && rhs.infinity && rhs.value>=0){// +-something > +inf
			return false;
		}else if(!infinity && rhs.infinity && rhs.value<0){// +-something > -inf
			return true;
		}else{// +-something > +-something
			if(value > rhs.value){
				return true;
			}else{
				return false;
			}
		}
	}
	
	bool operator<(const Intinf &rhs) const {
		if(infinity && rhs.infinity){// +-inf < +-inf
			return false;
		}else if(infinity && !rhs.infinity && value>=0){// +inf < +-something
			return false;
		}else if(infinity && !rhs.infinity && value<0){// -inf < +-something
			return true;
		}else if(!infinity && rhs.infinity && rhs.value>=0){// +-something < +inf
			return true;
		}else if(!infinity && rhs.infinity && rhs.value<0){// +-something < -inf
			return false;
		}else{// +-something < +-something
			if(value < rhs.value){
				return true;
			}else{
				return false;
			}
		}
	}
};
}
	
int main(){
	using namespace ece309;
	
	Intinf x(-1, 1);
	Intinf y(-1, 1);
	
	x = x / y;
	
	printf("\n");
	x.print();
	printf("\n");
	
	return 0;
}
