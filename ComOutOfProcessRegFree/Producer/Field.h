//
// Copyright © 2021 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// Field.h : Declaration of the CField

#pragma once
#include "framework.h"       // main symbols
#include "Producer_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// CField

class ATL_NO_VTABLE CField :  // NOLINT(clang-diagnostic-non-virtual-dtor)
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CField, &CLSID_Field>,
	public IDispatchImpl<IField, &IID_IField, &LIBID_ProducerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	const LONG zero_ = 0;
	const LONG one_ = 1;

public:
	STDMETHOD(GetZero)(LONG* value) noexcept override;
	STDMETHOD(GetOne)(LONG* value) noexcept override;
	STDMETHOD(Add)(LONG first, LONG second, LONG* value) noexcept override;
	STDMETHOD(Multiply)(LONG first, LONG second, LONG* value) noexcept override;
	STDMETHOD(Divide)(LONG first, LONG second, LONG* value) noexcept override;


	CField() = default;

DECLARE_REGISTRY_RESOURCEID(106)

DECLARE_NOT_AGGREGATABLE(CField)

BEGIN_COM_MAP(CField)
	COM_INTERFACE_ENTRY(IField)
	COM_INTERFACE_ENTRY(IRing)
	COM_INTERFACE_ENTRY(IGroup)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

    // ReSharper disable once CppInconsistentNaming
    // ReSharper disable once CppMemberFunctionMayBeStatic
    // ReSharper disable once CppHidingFunction
    HRESULT FinalConstruct()
	{
		return S_OK;
	}

    // ReSharper disable once CppInconsistentNaming
    // ReSharper disable once CppHidingFunction
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void FinalRelease()
	{
	}


};

OBJECT_ENTRY_AUTO(__uuidof(Field), CField)
