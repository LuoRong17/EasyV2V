#ifndef VEH_MOBILITY_H
#define VEH_MOBILITY_H
#include "easyv2v.h"
#include "ns3/nstime.h"
#include "ns3/vector.h"
namespace ns3 {

class VehMobility:public AppModuleBase
{
public:
	static TypeId GetTypeId (void);

protected:
	virtual void Init();
	virtual void Start();

private:
	Time m_startTime;
	Time m_firstMaxVelocityTime;
	Vector2D m_velocity;
	Vector2D m_acerrlatration;
	//Vector2D m_position;
};

}

#endif /* VEH_MOBILITY_H */