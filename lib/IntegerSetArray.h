namespace ece309{
class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}  
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};


class IntegerSetArray : public IntegerSet{
public:
	int *array;
	IntegerSetArray(int s = 1):IntegerSet(s) {
		array = new int[size];
		for(int i = 0; i<size; i++){
			array[i] = -1; //only pos numbers are allowed so a neg number lets us know the space is empty
		}
	}
	
	bool insert(int x){
		for(int i = 0; i<size; i++){
			if(array[i] < 0){
				array[i] = x;
				return true;
			}
		}
		return false;
	}
	
	bool search(int x) const {
		for(int i = 0; i<size; i++){
			if(array[i] == x){
				return true;
			}
		}
		return false;
	}
	
	void remove(int x){
		for(int i = 0; i<size; i++){
			if(array[i] == x){
				array[i] = -1;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
};
}
