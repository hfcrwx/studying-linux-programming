#include "Thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;

class TestThread : public Thread
{
public:
	TestThread(int count) : count_(count)
	{
		cout<<"TestThread ..."<<endl;
	}

	~TestThread()
	{
		cout<<"~TestThread ..."<<endl;
	}

private:
	void Run()
	{
		while (count_--)
		{
			cout<<"this is a test ..."<<endl;
			sleep(1);
		}
	}

	int count_;
};

int main(void)
{
	/*
	TestThread t(5);
	t.Start();
    // t.Run() // 是错的，这是在主线程中运行，不应该直接调用，做成private
	t.Join();
	*/

	TestThread* t2 = new TestThread(5);
	t2->SetAutoDelete(true);
	t2->Start();
    t2->Join(); //t2可能已经被销毁了

	for (; ; )
		pause();

	return 0;
}
