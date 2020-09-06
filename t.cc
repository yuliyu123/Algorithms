#include<iostream>
#include<thread>
using namespace std;



void f() 
{
	std::thread::id tid = std::this_thread::get_id();
	cout << "f id=" << tid << endl;
}


int main(int argc, char * argv[])
{
	thread t(f);
	t.join();
	std::thread::id tid = std::this_thread::get_id();
	cout << "main id=" << tid << endl;

	system("pause");
}

