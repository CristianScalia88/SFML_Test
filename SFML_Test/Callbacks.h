#pragma once

class CallbackBase
{
public:
	virtual void operator()() {};
	~CallbackBase() { }
};

template<typename T>
class Callback : public CallbackBase
{
public:
	typedef void (T::* F)();

	Callback(T* t, F f) : t_(t), f_(f) { }
	void operator()()
	{ 
		(t_->*f_)(); 
	}

private:
	T* t_;
	F  f_;
};


template<typename T >
Callback<T>* make_callback(T* t, void (T::* f) ())
{
	return new Callback<T>(t, f);
}

