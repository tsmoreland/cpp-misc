// AnimalCrud.h : Declaration of the CAnimalCrud

#pragma once
#include "resource.h"       // main symbols



#include "AnimalProducer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CAnimalCrud

class ATL_NO_VTABLE CAnimalCrud :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAnimalCrud, &CLSID_AnimalCrud>,
	public IDispatchImpl<IAnimalCrud, &IID_IAnimalCrud, &LIBID_AnimalProducerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	explicit CAnimalCrud() = default;

DECLARE_REGISTRY_RESOURCEID(107)

DECLARE_NOT_AGGREGATABLE(CAnimalCrud)

BEGIN_COM_MAP(CAnimalCrud)
	COM_INTERFACE_ENTRY(IAnimalCrud)
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

	STDMETHOD(CreateAnimal)(IAnimal** animal) noexcept override;



};

OBJECT_ENTRY_AUTO(__uuidof(AnimalCrud), CAnimalCrud)
