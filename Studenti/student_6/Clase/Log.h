#pragma once
class Log
{
private:
	static Log *instance;

	Log();
	Log(const Log&);
	~Log();

public:
	static Log &get_instance();
	static void destroy_instance();
	void logevent(const char*);
};

