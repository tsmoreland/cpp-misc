// Producer.cpp : Implementation of WinMain


#include "framework.h"
#include "Resource.h"
#include "Producer_i.h"
#include "xdlldata.h"


using namespace ATL;


class CProducerModule : public ATL::CAtlExeModuleT< CProducerModule >
{
public :
	DECLARE_LIBID(LIBID_ProducerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_PRODUCER, "{b333f46a-866b-4454-a4a8-68cd6fefd564}")
};

CProducerModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

