#ifndef VEH_PHY_H
#define VEH_PHY_H
#include "easyv2v.h"
#include "ns3/nstime.h"

namespace ns3 {

class VehPhy:public AppModuleBase
{
public:
	static TypeId GetTypeId (void);

protected:
	virtual void Init();
	virtual void Start();
};

}

#endif /* VEH_PHY_H */