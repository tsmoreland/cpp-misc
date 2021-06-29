// Animal.h : Declaration of the CAnimal

#pragma once
#include "resource.h"       // main symbols



#include "OopAnimals_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CAnimal

class ATL_NO_VTABLE CAnimal :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAnimal, &CLSID_Animal>,
	public IDispatchImpl<IAnimal2, &IID_IAnimal2, &LIBID_OopAnimalsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	LONG numberOfLegs_{ 0 };
	VARIANT_BOOL canSpeak_{ FALSE };
public:
	explicit CAnimal() = default;

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CAnimal)
	COM_INTERFACE_ENTRY(IAnimal)
	COM_INTERFACE_ENTRY(IAnimal2)
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


	STDMETHOD(GetNumberOfLegs)(LONG* cout) noexcept override;

	STDMETHOD(SetNumberOfLegs)(LONG count) noexcept override;

	STDMETHOD(SetCanSpeak)(VARIANT_BOOL canSpeak) noexcept override;

	STDMETHOD(CanSpeak)(VARIANT_BOOL* result) noexcept override;

};

OBJECT_ENTRY_AUTO(__uuidof(Animal), CAnimal)
