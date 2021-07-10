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
}
