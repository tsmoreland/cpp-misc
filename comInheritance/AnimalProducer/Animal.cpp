// Animal.cpp : Implementation of CAnimal

#include "pch.h"
#include "Animal.h"


// CAnimal

STDMETHODIMP CAnimal::Name(BSTR* name)
{
    if (name == nullptr) {
        return E_INVALIDARG;
    }

    // piggy-backing ATL to do the allocation work
    *name = CComBSTR(L"Dog").Detach();
    return S_OK;
}
STDMETHODIMP CAnimal::TopSpeed(LONG* speed)
{
    if (speed == nullptr) {
        return E_INVALIDARG;
    }

    *speed = 30L;
    return S_OK;
}
STDMETHODIMP CAnimal::CanSwim(VARIANT_BOOL* canSwim)
{
    if (canSwim == nullptr) {
        return E_FAIL;
    }

    *canSwim = VARIANT_TRUE;
    return S_OK;
}
