// CPPDemo1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "stdio.h"
// C面向过程的方式
void trace(char* s)
{
	printf("%s\n", s);
}
static int noisy = 1;  // 状态信息
void trace2(char* s)
{
	if (noisy)
		printf("%s\n", s);
}
void trace_on()
{
	noisy = 1;
}
void trace_off()
{
	noisy = 0;
}
// C++面向对象方式
class Trace {
public:
	Trace() { noisy = 0; f = stdout; }
	Trace(FILE* ff) { noisy = 0; f = ff; }
	void on() { noisy = 1; }
	void off() { noisy = 0; }
	void print(char* s) { 
		if (noisy)
		{
			fprintf(f, "%s\n", s);
		}
	}
private:
	int noisy;// 状态信息
	FILE* f;
};

int main()
{
	//trace_on();
	//trace2("hi");
	////trace_off();
	//trace2("hi");

	FILE* f;
	fopen_s(&f, "cppdemo1.txt", "w");
	Trace t(f);
	t.on();
	t.print("hi2");
	//t.off();
	t.print("hi2");
	fclose(f);

    return 0;
}

