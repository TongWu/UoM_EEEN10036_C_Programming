#include <iostream>
#include <thread>
using namespace std;

void fun(int id) {
	for (int i = 0; i < 10; i++) {
		cout << "Thread " << id << ":" << i << endl;
	}
}

int main() {
	std::thread t1(fun, 1); //thread t1 starts,t1包含了fun函数，其中id的输入值为1
	t1.join();				//wait for t1 to finish
	std::cout << "End of program" << endl;
}