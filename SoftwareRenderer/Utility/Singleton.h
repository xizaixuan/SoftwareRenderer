#ifndef Singleton_H_
#define Singleton_H_

#define SINGLETON_DEFINE(classname) friend class Singleton<classname>;

template<typename T>
class Singleton
{
public:
	static T* GetSingletonPtr()
	{
		static T m_Singleton;
		return &m_Singleton;
	}

protected:
	Singleton(void){}

	~Singleton(void){}
};

#endif