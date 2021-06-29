// dllmain.h : Declaration of module class.

class CAnimalProducerModule : public ATL::CAtlDllModuleT< CAnimalProducerModule >
{
public :
	DECLARE_LIBID(LIBID_AnimalProducerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ANIMALPRODUCER, "{115ce6f5-086b-4a28-bd1a-8aa11c23a79a}")
};

extern class CAnimalProducerModule _AtlModule;
