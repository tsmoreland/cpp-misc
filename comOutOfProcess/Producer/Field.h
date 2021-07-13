// Field.h : Declaration of the CField

#pragma once
#include "resource.h"       // main symbols
#include "Producer_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CField

class ATL_NO_VTABLE CField :  // NOLINT(clang-diagnostic-non-virtual-dtor)
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CField, &CLSID_Field>,
	public IDispatchImpl<IGroup, &IID_IGroup, &LIBID_ProducerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
    const int zero_ = 0;
    const int one_ = 1;
public:
    STDMETHOD(GetZero)(LONG* value) noexcept override;


    CField() = default;

DECLARE_REGISTRY_RESOURCEID(106)

DECLARE_NOT_AGGREGATABLE(CField)

BEGIN_COM_MAP(CField)
	COM_INTERFACE_ENTRY(IGroup)
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


};

OBJECT_ENTRY_AUTO(__uuidof(Field), CField)
