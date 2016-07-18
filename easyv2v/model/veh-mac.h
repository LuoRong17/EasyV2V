#ifndef VEH_MAC_H
#define VEH_MAC_H
#include "easyv2v.h"
#include "ns3/nstime.h"

namespace ns3 {

class VehMac:public AppModuleBase
{
public:
	static TypeId GetTypeId (void);

protected:
	virtual void Init();
	virtual void Start();
};

}

#endif /* VEH_MAC_H */