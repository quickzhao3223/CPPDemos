// CPPDemo1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "stdio.h"
// C������̵ķ�ʽ
void trace(char* s)
{
	printf("%s\n", s);
}
static int noisy = 1;  // ״̬��Ϣ
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
// C++�������ʽ
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
	int noisy;// ״̬��Ϣ
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

