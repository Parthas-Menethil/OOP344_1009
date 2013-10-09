#include <iostream>
class EventSystem{
private:
	int val;
protected:
public:
	void (*over100)(int&); // Pointer
	void (*under0)(int&);  // Pooter
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
void safeZero(){}
int main(){

}
void eventChecker(){}