#include <iostream>
#include <thread> 
#include <mutex>

using namespace std;

std::mutex mtx;



//normal lazy
class SingletonLazy {
private:
	static SingletonLazy* instance;
	SingletonLazy();
	SingletonLazy(SingletonLazy& other);
	SingletonLazy& operator=(SingletonLazy& other);
public:
	static SingletonLazy* GetInstance() {
		if (instance == nullptr) {
			instance = new SingletonLazy();
		}
		return instance;
	}
};
SingletonLazy* SingletonLazy::instance = nullptr;


//hungary
class SingletonHungary
{
public:
	static SingletonHungary* GetInstance() {
		if (instance == nullptr) {
			instance = new SingletonHungary();
		}

		return instance;
	}

private:
	SingletonHungary();
	static SingletonHungary* instance;
};

SingletonHungary* SingletonHungary::instance = new SingletonHungary();


// thread safe
class SingletonThread {
private:
	static SingletonThread* instance;
	SingletonThread();
	SingletonThread(SingletonThread& other);
	SingletonThread& operator=(SingletonThread& other);
public:
	SingletonThread* GetInstance() {
		if (instance == nullptr) {
			mtx.lock();
			if (instance == nullptr) {
				instance = new SingletonThread();
			}
			mtx.unlock();
		}
		return instance;
	}
};
SingletonThread* SingletonThread::instance = nullptr;




// proxy design patterns
class SubjectP {
public:
	virtual void Request() = 0;
};


class Real :public SubjectP {
public:
	void Request() {
		cout << "real give" << endl;
	}
};

class Proxy : public SubjectP {
private:
	Real* r;
public:
	void Request() {
		if (r == nullptr) {
			r = new Real();
		}
		r->Request();
	}
};




// observer
#include<string>
#include<vector>

class Observer {
public:
	virtual void Update(string msg) = 0;
};

class Pub {

public:
	virtual void Attach(Observer* a) = 0;
	virtual void Delete(Observer* a) = 0;
	virtual void Notify(string msg) = 0;
};


class ConcreteObserver:public Observer {
private:
	string name;
public:
	void Update(string msg) {
		cout << name<< "get notify" <<msg<< endl;
	}
};


class ConcretePub :public Pub {
private:
	vector<Observer*> m;

public:
	void Attach(Observer* a) {
		m.push_back(a);
	}
	void Delete(Observer* a) {
		//m.erase(a);
	}

	void Notify(string msg) {
		for (size_t i = 0; i < m.size(); i++)
		{
			m[i]->Update(msg);
		}
	}
};




// strategy design patterns
class Strategy {
public:
	virtual void GetResult() = 0;
};

class ConcreteStrategy :public Strategy {
public:
	void GetResult() {
		cout << "con stra 1" << endl;
	}
};

class Context {
private:
	Strategy* s;
public:
	Context(Strategy* a) {
		s = a;
	}

	void ContextInterface() {
		s->GetResult();
	}
};










// simple factory  

class ModelSimple {
public:
	virtual void SetModel()=0;
};

class ConcreteModel :public ModelSimple {
public:
	void SetModel() {
		cout << "con1" << endl;
	}
};

class SimpleFactory {
public:
	ModelSimple* GetModel(int i) {
		ModelSimple* a = nullptr;
		switch (i)
		{
		case 1:
			a = new ConcreteModel();
			break;
		default:
			break;
		}
		return a;
	}
};



// factory
class Product {
public:
	virtual void wash()=0;
	virtual void buy()=0;
};


class ProductA :public Product {
public:
	void wash() {

	}
	void buy() {

	}
};

class ProductB :public Product {
public:
	void wash() {

	}
	void buy() {

	}
};

class ProductFactory {
public:
	virtual Product* CreateLeiFeng() = 0;
};



class ProductAFactory :public ProductFactory {
public:
	Product* CreateLeiFeng() {
		return new ProductA();
	}
};

class ProductBFactory :public ProductFactory {
public:
	Product* CreateLeiFeng() {
		return new ProductB();
	}
};




// template

class TemplateMethod {
public:
	virtual void FirstOperation() = 0;
	virtual void SecondOperation() = 0;
	void TMethod() {
		FirstOperation();
		SecondOperation();
	}
};

class ConcreteTemplate1 :public TemplateMethod {
public:
	void FirstOperation() {

	}

	void SecondOperation() {

	}
};


void TestTemplateMethod() {
	TemplateMethod* t1 = new ConcreteTemplate1();
	t1->TMethod();
}