// Field.cpp : Implementation of CField

#include "pch.h"
#include "Field.h"


// CField

STDMETHODIMP CField::GetZero(LONG* value) noexcept 
{
    if (value == nullptr) {
        return E_POINTER;
    }

    *value = 0;

    return S_OK;
}

STDMETHODIMP CField::GetOne(LONG* value) noexcept
{
    if (value == nullptr) {
        return E_POINTER;
    }

    return S_OK;
}

STDMETHODIMP CField::Add(LONG first, LONG second, LONG* value) noexcept 
{
    if (value == nullptr) {
        return E_POINTER;
    }

    *value = first + second;

    return S_OK;
}

STDMETHODIMP CField::Multiply(LONG first, LONG second, LONG* value) noexcept 
{
    if (value == nullptr) {
        return E_POINTER;
    }

    *value = first * second;


    return S_OK;
}

STDMETHODIMP CField::Divide(LONG first, LONG second, LONG* value) noexcept 
{
    if (value == nullptr) {
        return E_POINTER;
    }

    if (second == 0) {
        return E_INVALIDARG;
    }

    *value = first / second;

    return S_OK;
}
