#ifndef VEHICLE_H
#define VEHICLE_H
#include "ns3/application.h"
#include <string>
namespace ns3 {

class Vehicle:public Application
{
public:
	static TypeId GetTypeId();
	std::string GetVehID();
private:
	virtual void StartApplication();

	std::string m_vehicleID;
};

}

#endif /* VEHICLE_H */
