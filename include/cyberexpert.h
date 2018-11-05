 
#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"
#include <iterator>

class CyberExpert
{
private:
	const std::string cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int efficiency_count;
    int work_count;
    int rest_count;
    CyberExpert(); // Prevent the use of an empty constructor
	// Add your own variables here
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
    void Clean(CyberPC & cyber_pc);
 	std :: string getName();
  	int getExpertWorkTime() ;
 	int getExpertRestTime();
 	int getExpertEfficiency();
 	std::vector<std::string>::reverse_iterator DNSclean (const CyberDNS &dns,std::vector<std::string>::reverse_iterator it ,std::vector<std::string> &list);
    bool ableToWork() ;
    void isResting();


 	// Add your own functions here
};


#endif
