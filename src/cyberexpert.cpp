
#include "../include/cyberexpert.h"
#include <iostream>
#include <vector>
using namespace std;

CyberExpert::CyberExpert (std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
	cyber_expert_name_(cyber_expert_name_),
	cyber_expert_work_time_(cyber_expert_work_time_),
	cyber_expert_rest_time_( cyber_expert_rest_time_) ,
	cyber_expert_efficiency_(cyber_expert_efficiency_),
	efficiency_count(cyber_expert_efficiency_),
	work_count (cyber_expert_work_time_),
	rest_count (cyber_expert_rest_time_){};


std:: string CyberExpert :: getName(){
	return cyber_expert_name_;
}

int CyberExpert :: getExpertWorkTime() {
	return cyber_expert_work_time_;
}
int CyberExpert :: getExpertRestTime(){
	return cyber_expert_rest_time_;
}
int CyberExpert ::getExpertEfficiency(){

	return cyber_expert_efficiency_;
}

void CyberExpert:: Clean(CyberPC & cyber_pc) {

	cout<<"	"<<	getName()<< " examining "<< cyber_pc.getName()<< endl;
	if (cyber_pc.HaveWorm())
	   cyber_pc.Disinfect();
	if(efficiency_count == 0 && work_count ==0)
		cout<< "	"<<getName()<<" is taking a break"<< endl;



	}

std::vector<std::string>::reverse_iterator CyberExpert:: DNSclean (const CyberDNS &dns,vector<string>::reverse_iterator it,std::vector<std::string> & list){



	std::vector<std::string> ::reverse_iterator reverse= it;
	efficiency_count = getExpertEfficiency();


	for( ;reverse!= list.rend() && efficiency_count != 0; reverse++) {
	    string tempString = *reverse ;
		CyberPC &pc1 = dns.GetCyberPC(tempString);
		efficiency_count --;
		Clean(pc1);


	}

    efficiency_count = getExpertEfficiency();
	return reverse;
}

bool CyberExpert:: ableToWork() {

	if(work_count > 0){
		work_count--;

		return true;
		}


	else{
		isResting();
		    return false;

			}
		}


void CyberExpert:: isResting(){


		if (rest_count > 0 ){
				rest_count--;
				if (rest_count == 0){

				cout << "	"<< getName()<< " is back to work"<< endl;
				rest_count = getExpertRestTime();
				work_count = getExpertWorkTime();

		}
	}

}









