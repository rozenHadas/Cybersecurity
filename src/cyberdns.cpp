/*
 * cyberdns.cpp
 *
 *  Created on: Nov 14, 2015
 *      Author: shidlhad
 */
#include "../include/cyberdns.h"
#include <string>
#include <set>
#include <exception>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;



CyberDNS::CyberDNS() : cyber_DNS_() {};

  CyberDNS::~CyberDNS(){

	std::map<std::string, CyberPC&>::iterator it;
	for( it = cyber_DNS_.begin(); it!= cyber_DNS_.end(); it++) {

			delete &((*it).second);

	}

};


void CyberDNS::AddPC(CyberPC & cyber_pc_){
	cyber_DNS_.insert(  std::pair<std::string ,CyberPC&> (cyber_pc_.getName(),cyber_pc_)  );
	cout<< "Adding to server:" <<  cyber_pc_.getName() <<endl;
	cout<< cyber_pc_.getName()<< " connected to server"<<endl;

};


CyberPC & CyberDNS::GetCyberPC(const std::string  &cyber_pc_name) const{
    return (cyber_DNS_.find(cyber_pc_name) ->second);
	}


std::vector<std::string> CyberDNS::GetCyberPCList(){

	   std::map<const std::string,CyberPC &>::iterator it;
	   std:vector<std::string> pcList;

	   for(it = cyber_DNS_.begin(); it != cyber_DNS_.end(); it++)
	   {
		  string name = it->first;
		  pcList.push_back(name);

	   }
return pcList;

};




