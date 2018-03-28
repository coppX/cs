#include <iostream>
using namespace std;

class HolidayRequest
{
public:
	HolidayRequest(int hour)
		:m_iHour(hour)
	{}
	int GetHour()
	{
		return m_iHour;
	}
private:
	int m_iHour;
};

class Manager
{
public:
	virtual bool HandleRequest(HolidayRequest* request) = 0;
};

class PM:public Manager
{
public:
	PM(Manager* handler)
	:m_Handler(handler)
	{}
	bool HandleRequest(HolidayRequest* request)
	{
		if(request->GetHour() <= 2 || m_Handler == NULL)
		{
			cout<<"PM said : OK"<<endl;
			return true;
		}
		return m_Handler->HandleRequest(request);
	}
private:
	Manager* m_Handler;
};

class DM:public Manager
{
public:
	DM(Manager* handler)
	:m_handler(handler)
	{}
	bool HandleRequest(HolidayRequest* request)
	{
		cout<<"DM said : OK"<<endl;
		return true;
	}
	bool IsIn()
	{
		return true;
	}
private:
	Manager *m_handler;
};

class PS:public Manager
{
public:
	PS(Manager* handler)
	:m_handler(handler)
	{}
	bool HandleRequest(HolidayRequest* request)
	{
		DM* pDM = dynamic_cast<DM* >(m_handler);
		if(pDM != NULL)
		{
			if(pDM->IsIn())
				return pDM->HandleRequest(request);
		}
		cout<<"PS said : OK"<<endl;
		return true;
	}
private:
	Manager* m_handler;
};
