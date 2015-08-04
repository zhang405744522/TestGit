
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class M2MTimerObserver
{
public:
	typedef enum {
		Notdefined,
		Registration,
		NsdlExecution,
		PMinTimer,
		PMaxTimer
	}Type;

};

class M2MTimerImpl
{
public:

	// Prevents the use of assignment operator
	M2MTimerImpl& operator=(const M2MTimerImpl& other);

	// Prevents the use of copy constructor
	M2MTimerImpl(const M2MTimerImpl& other);

	/**
	* Constructor.
	*/
	M2MTimerImpl(int x);

	/**
	* Destructor.
	*/
	virtual ~M2MTimerImpl();
	

private:

	// M2MTimerObserver&   _observer;
	int				sz;
	bool                _single_shot;
	unsigned      _interval;


};

M2MTimerImpl::~M2MTimerImpl()
{
}

M2MTimerImpl& M2MTimerImpl::operator=(const M2MTimerImpl& other)
{
	if (this != &other){
		_single_shot = other._single_shot;
		_interval = other._interval;
		cout << "==";
	}
	return *this;
}

M2MTimerImpl::M2MTimerImpl(int x)
	:sz(x),
	_single_shot(true),
	_interval(0)
{
}

// Prevents the use of copy constructor
M2MTimerImpl::M2MTimerImpl(const M2MTimerImpl& other)
	:sz(9)
{
	*this = other;
}

void print_byte(unsigned char* buf, unsigned length)
{
	unsigned begin = 0;
	while (begin < length)
		printf("%x ", buf[begin++]);
	printf("\r\n");
}

void main()
{
#if 0
	M2MTimerObserver TimerObj;
	M2MTimerImpl obj1(6);
	M2MTimerImpl obj2(obj1);
	cout << &TimerObj << endl;
#endif
	char coap_payload[6 + 1]; //sizeof(/5/0/1+\0) 
	memcpy(coap_payload, "/5/0/6", 6);
	coap_payload[6] = '\0';
#if 1
	if (!strncmp(&coap_payload[0], "/5/0/1", 6))
		printf("=");
	else
		printf("!=");

	char inst_id[10];
	sprintf_s(inst_id, "%d", 14);
#endif
}