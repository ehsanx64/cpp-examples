#include <iostream>

using namespace std;

class Hello {
public:
	void sayIt();
};

void Hello::sayIt() {
	cout << "Hello!!!" << "\n";
}


int main () {
	Hello h;

	h.sayIt();
	return 0;
}
