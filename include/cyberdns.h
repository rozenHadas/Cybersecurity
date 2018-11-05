

#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include "../include/cyberpc.h"
#include <iterator>

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC&> cyber_DNS_;	//Hash map to hold PC names and pointers

 
public:
    CyberDNS();
	void AddPC(CyberPC & cyber_pc_);
	CyberPC& GetCyberPC(const std::string  &cyber_pc_name)const;
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
	virtual ~CyberDNS();												// All access to PC objects should use this function
													// Do not store pointers elsewhere!
};

#endif
