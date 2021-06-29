// OopAnimals.cpp : Implementation of WinMain


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "OopAnimals_i.h"
#include "xdlldata.h"


using namespace ATL;


class COopAnimalsModule : public ATL::CAtlExeModuleT< COopAnimalsModule >
{
public :
	DECLARE_LIBID(LIBID_OopAnimalsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OOPANIMALS, "{66898145-113c-4862-8217-3a4202cb110f}")
};

COopAnimalsModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

