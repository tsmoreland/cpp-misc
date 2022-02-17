#pragma once

#ifdef DYNAMICMODULE_EXPORTS
#define DYNAMICMODULE_EXPORT __declspec(dllexport)
#else
#define DYNAMICMODULE_EXPORT __declspec(dllimport)
#endif
