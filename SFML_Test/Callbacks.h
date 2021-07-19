#pragma once

class CallbackBase
{
public:
	virtual void Invoke() {};
	~CallbackBase() { }
};

class Action
{
public:
	vector<CallbackBase*>* callbackss;

	Action()
	{
		callbackss = new vector<CallbackBase*>();
	}

	void AddCallback(CallbackBase* callback)
	{
		callbackss->push_back(callback);
	}

	void Invoke()
	{
		for (auto it = callbackss->begin(); it != callbackss->end(); ++it) {
			(*it)->Invoke();
		}
	}
};

template<typename T>
class Callback : public CallbackBase
{
public:
	typedef void (T::* F)();

	Callback(T* t, F f) 
	{
		t_ = t;
		callback = f;
	}

	void Invoke() 
	{
		(t_->*callback)();
	}

private:
	T* t_;
	F callback;
};


template<typename T >
Callback<T>* make_callback(T* t, void (T::* f) ())
{
	return new Callback<T>(t, f);
}