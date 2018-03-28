#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton
{
private:
	static Singleton* pInstance;
	Singleton();
public:
	static Singleton* Instance();
	static void Destroy();
};

#endif
