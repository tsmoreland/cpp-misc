

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for AnimalProducer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AnimalProducer_i_h__
#define __AnimalProducer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAnimal_FWD_DEFINED__
#define __IAnimal_FWD_DEFINED__
typedef interface IAnimal IAnimal;

#endif 	/* __IAnimal_FWD_DEFINED__ */


#ifndef __IAnimal2_FWD_DEFINED__
#define __IAnimal2_FWD_DEFINED__
typedef interface IAnimal2 IAnimal2;

#endif 	/* __IAnimal2_FWD_DEFINED__ */


#ifndef __IAnimal3_FWD_DEFINED__
#define __IAnimal3_FWD_DEFINED__
typedef interface IAnimal3 IAnimal3;

#endif 	/* __IAnimal3_FWD_DEFINED__ */


#ifndef __IAnimalCrud_FWD_DEFINED__
#define __IAnimalCrud_FWD_DEFINED__
typedef interface IAnimalCrud IAnimalCrud;

#endif 	/* __IAnimalCrud_FWD_DEFINED__ */


#ifndef __Animal_FWD_DEFINED__
#define __Animal_FWD_DEFINED__

#ifdef __cplusplus
typedef class Animal Animal;
#else
typedef struct Animal Animal;
#endif /* __cplusplus */

#endif 	/* __Animal_FWD_DEFINED__ */


#ifndef __AnimalCrud_FWD_DEFINED__
#define __AnimalCrud_FWD_DEFINED__

#ifdef __cplusplus
typedef class AnimalCrud AnimalCrud;
#else
typedef struct AnimalCrud AnimalCrud;
#endif /* __cplusplus */

#endif 	/* __AnimalCrud_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAnimal_INTERFACE_DEFINED__
#define __IAnimal_INTERFACE_DEFINED__

/* interface IAnimal */
/* [custom][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnimal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3f195862-cbbd-45d1-bf9a-3a8073185948")
    IAnimal : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Name( 
            /* [retval][out] */ BSTR *name) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAnimalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnimal * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnimal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnimal * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnimal * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnimal * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnimal * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnimal * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Name )( 
            IAnimal * This,
            /* [retval][out] */ BSTR *name);
        
        END_INTERFACE
    } IAnimalVtbl;

    interface IAnimal
    {
        CONST_VTBL struct IAnimalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnimal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnimal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnimal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnimal_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnimal_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnimal_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnimal_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnimal_Name(This,name)	\
    ( (This)->lpVtbl -> Name(This,name) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnimal_INTERFACE_DEFINED__ */


#ifndef __IAnimal2_INTERFACE_DEFINED__
#define __IAnimal2_INTERFACE_DEFINED__

/* interface IAnimal2 */
/* [custom][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnimal2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7941BAA4-FFF8-4A0D-8D79-F4A492567D30")
    IAnimal2 : public IAnimal
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TopSpeed( 
            /* [retval][out] */ LONG *speed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAnimal2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnimal2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnimal2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnimal2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnimal2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnimal2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnimal2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnimal2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Name )( 
            IAnimal2 * This,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TopSpeed )( 
            IAnimal2 * This,
            /* [retval][out] */ LONG *speed);
        
        END_INTERFACE
    } IAnimal2Vtbl;

    interface IAnimal2
    {
        CONST_VTBL struct IAnimal2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnimal2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnimal2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnimal2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnimal2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnimal2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnimal2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnimal2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnimal2_Name(This,name)	\
    ( (This)->lpVtbl -> Name(This,name) ) 


#define IAnimal2_TopSpeed(This,speed)	\
    ( (This)->lpVtbl -> TopSpeed(This,speed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnimal2_INTERFACE_DEFINED__ */


#ifndef __IAnimal3_INTERFACE_DEFINED__
#define __IAnimal3_INTERFACE_DEFINED__

/* interface IAnimal3 */
/* [custom][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnimal3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD13E476-E84B-4411-B8C0-AC04D1574CAA")
    IAnimal3 : public IAnimal2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanSwim( 
            /* [retval][out] */ VARIANT_BOOL *canSwim) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAnimal3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnimal3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnimal3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnimal3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnimal3 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnimal3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnimal3 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnimal3 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Name )( 
            IAnimal3 * This,
            /* [retval][out] */ BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TopSpeed )( 
            IAnimal3 * This,
            /* [retval][out] */ LONG *speed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanSwim )( 
            IAnimal3 * This,
            /* [retval][out] */ VARIANT_BOOL *canSwim);
        
        END_INTERFACE
    } IAnimal3Vtbl;

    interface IAnimal3
    {
        CONST_VTBL struct IAnimal3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnimal3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnimal3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnimal3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnimal3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnimal3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnimal3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnimal3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnimal3_Name(This,name)	\
    ( (This)->lpVtbl -> Name(This,name) ) 


#define IAnimal3_TopSpeed(This,speed)	\
    ( (This)->lpVtbl -> TopSpeed(This,speed) ) 


#define IAnimal3_CanSwim(This,canSwim)	\
    ( (This)->lpVtbl -> CanSwim(This,canSwim) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnimal3_INTERFACE_DEFINED__ */


#ifndef __IAnimalCrud_INTERFACE_DEFINED__
#define __IAnimalCrud_INTERFACE_DEFINED__

/* interface IAnimalCrud */
/* [custom][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnimalCrud;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b5f07ceb-d8ad-4125-8b52-d118a828cf95")
    IAnimalCrud : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateAnimal( 
            /* [retval][out] */ IAnimal **animal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAnimalCrudVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnimalCrud * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnimalCrud * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnimalCrud * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnimalCrud * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnimalCrud * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnimalCrud * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnimalCrud * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateAnimal )( 
            IAnimalCrud * This,
            /* [retval][out] */ IAnimal **animal);
        
        END_INTERFACE
    } IAnimalCrudVtbl;

    interface IAnimalCrud
    {
        CONST_VTBL struct IAnimalCrudVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnimalCrud_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnimalCrud_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnimalCrud_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnimalCrud_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnimalCrud_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnimalCrud_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnimalCrud_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnimalCrud_CreateAnimal(This,animal)	\
    ( (This)->lpVtbl -> CreateAnimal(This,animal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnimalCrud_INTERFACE_DEFINED__ */



#ifndef __AnimalProducerLib_LIBRARY_DEFINED__
#define __AnimalProducerLib_LIBRARY_DEFINED__

/* library AnimalProducerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AnimalProducerLib;

EXTERN_C const CLSID CLSID_Animal;

#ifdef __cplusplus

class DECLSPEC_UUID("90f017cc-e42e-4177-bf97-57d2ae475b13")
Animal;
#endif

EXTERN_C const CLSID CLSID_AnimalCrud;

#ifdef __cplusplus

class DECLSPEC_UUID("aaad5515-49b0-4faf-9fc2-ae1552aaacc1")
AnimalCrud;
#endif
#endif /* __AnimalProducerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


