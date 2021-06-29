// AnimalCrud.cpp : Implementation of CAnimalCrud

#include "pch.h"
#include "AnimalCrud.h"
#include <comip.h>
#include <stdexcept>

// CAnimalCrud


using animal_com_ptr_t = _com_ptr_t<_com_IIID<IAnimal, &__uuidof(IAnimal)>>;

STDMETHODIMP CAnimalCrud::CreateAnimal(LONG type, IAnimal** animal) noexcept
{
    if (animal == nullptr)
    {
        return E_INVALIDARG;
    }

    try
    {
        *animal = animal_com_ptr_t().Detach();
        return S_OK;
    }
    catch (std::exception const&)
    {
        return E_FAIL;
    }


}
