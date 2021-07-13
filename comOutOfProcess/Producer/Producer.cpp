// Producer.cpp : Implementation of WinMain


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Producer_i.h"


using namespace ATL;


class CProducerModule : public ATL::CAtlExeModuleT< CProducerModule >
{
public :
	DECLARE_LIBID(LIBID_ProducerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_PRODUCER, "{a61e324a-02da-4ae8-b7e6-168a9cb1c7af}")
};

CProducerModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

