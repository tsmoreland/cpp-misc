// AnimalCrud.cpp : Implementation of CAnimalCrud

#include "pch.h"
#include "AnimalCrud.h"

#include <comip.h>

using animal_com_ptr_t = _com_ptr_t<_com_IIID<IAnimal, &__uuidof(IAnimal)>>;  // NOLINT(clang-diagnostic-language-extension-token)


STDMETHODIMP CAnimalCrud::CreateAnimal(IAnimal** animal) noexcept 
{
    if (animal == nullptr) {
        return E_INVALIDARG;
    }

    return CoCreateInstance(CLSID_Animal, nullptr, CLSCTX_INPROC_SERVER, IID_IAnimal, reinterpret_cast<void**>(animal));
}
