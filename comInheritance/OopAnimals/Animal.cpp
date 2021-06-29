// Animal.cpp : Implementation of CAnimal

#include "pch.h"
#include "Animal.h"

STDMETHODIMP CAnimal::GetNumberOfLegs(LONG* count) noexcept
{
    if (count == nullptr) {
        return E_INVALIDARG;
    }

    *count = numberOfLegs_;
    return S_OK;
}

STDMETHODIMP CAnimal::SetNumberOfLegs(LONG count) noexcept 
{
    numberOfLegs_ = count;
    return S_OK;
}

STDMETHODIMP CAnimal::SetCanSpeak(VARIANT_BOOL canSpeak) noexcept 
{
    canSpeak_ = canSpeak;
    return S_OK;
}

STDMETHODIMP CAnimal::CanSpeak(VARIANT_BOOL* result) noexcept
{
    if (result == nullptr)
    {
        return E_INVALIDARG;
    }

    *result = canSpeak_;

    return S_OK;
}


// CAnimal

