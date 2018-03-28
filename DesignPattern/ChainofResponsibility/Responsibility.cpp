#include "Responsibility.h"

int test_chain_of_Responsibility_Pattern()
{
	DM* pDM = new DM(NULL);
	PS* pPS = new PS(pDM);
	PM* pPM = new PM(pPS);
	HolidayRequest* Prequest = new HolidayRequest(10);
	pPM->HandleRequest(Prequest);
	delete Prequest;

	Prequest = new HolidayRequest(2);
	pPM->HandleRequest(Prequest);
	delete pDM;
	delete pPS;
	delete pPM;
	delete Prequest;

	return 0;
}
