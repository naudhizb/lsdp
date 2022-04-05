#pragma once

#define MAKE_SINGLETON(classname )					\
private:											\
	classname() {}									\
	classname(const classname&) = delete;			\
	void operator=(const classname&) = delete;		\
public:												\
	static classname& getInstance()					\
	{												\
		static classname instance;					\
		return instance;							\
	}												\
private: