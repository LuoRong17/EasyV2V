#ifndef MOBILITY_MANAGER_H
#define MOBILITY_MANAGER_H
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "ns3/nstime.h"
#include "ns3/vector.h"
#include <map>

using namespace rapidxml;

namespace ns3 {

class VehMobilityInfo
{
public:
	VehMobilityInfo(double maxVeclocity,double acerrlatration);
	void SetRun();
	void Update();
private:
	bool m_isRun;
	Time m_lastUpdate;
	Time m_startTime;
	Time m_firstMaxVeclocityTime;
	double m_maxVelocity;
	double m_acerrlatration;
	double m_currentVelocity;
	double m_position;
};

struct VehInitInfo
{
	friend std::ostream & operator << (std::ostream & os, const VehInitInfo & info);
public:
	VehInitInfo(std::string category,double velocity,double acerrlatration,int num);
	std::string m_category;
	double m_velocity;
	double m_acerrlatration;
	int m_num;
};

class MobilityManager
{
	typedef std::map<std::string,VehMobilityInfo> VehMobilityMap;
public:
	std::vector<VehInitInfo> GetVehInitInfoList();
	void ReadXml(std::string file_name);
	void VehInformStartRun(const std::string& vehID);
private:
	VehMobilityMap m_vehMobilityMap;
	std::vector<VehInitInfo> m_vehInitInfoList;
};

}

#endif /* MOBILITY_MANAGER_H */