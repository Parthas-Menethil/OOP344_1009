#include <iostream>
class EventSystem{
private:
	int val;
protected:
public:
	void (*over100)(int&); // Pointer
	void (*under0)(int&);  // Pointer
	void setVal(int i) { val = i; }
	EventSystem() : val(0), over100(0), under0(0){
	
	}
	void process(){
		if (val > 100 && over100){
			over100(val);
		}
		else if (val < 0 && under0){
			under0(val);
		}
	}
};
void safeZero(int& i){
	i = 0;
}
void inform100(int& i){
	std::cout << "The var became " << i << std::endl;
}
int main(){
	bool done = false;
	EventSystem es;
	es.over100 = inform100;
	es.under0 = safeZero;
	while(!done){
		int i = 0;
		std::cin >> i;
		es.setVal(i);
		es.process();
	}
}
void eventChecker(){}