#pragma once

class Deleter
{
public:
	template <class T>
	void operator()(const T* obj);
};

template<class T>
inline void Deleter::operator()(const T* obj)
{
	if (obj)
		delete obj;
}

class SingletonDeleter
{
public:
	template <class T>
	void operator()(T* obj);
};

template<class T>
inline void SingletonDeleter::operator()(T* obj)
{
	if (obj)
	{
		obj->clear();
		obj = nullptr;
	}
}