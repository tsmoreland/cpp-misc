// Dog.h : Declaration of the CDog

#pragma once
#include "resource.h"       // main symbols



#include "OopAnimals_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CDog

class ATL_NO_VTABLE CDog :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDog, &CLSID_Dog>,
	public IDispatchImpl<IDog, &IID_IDog, &LIBID_OopAnimalsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	explicit CDog() = default;

DECLARE_REGISTRY_RESOURCEID(108)

DECLARE_NOT_AGGREGATABLE(CDog)

BEGIN_COM_MAP(CDog)
	COM_INTERFACE_ENTRY(IDog)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	void FinalRelease()
	{
	}

	STDMETHOD(Rollover)() noexcept override;


};

OBJECT_ENTRY_AUTO(__uuidof(Dog), CDog)
