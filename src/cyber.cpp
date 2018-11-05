 
# include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include "../include/cyberworm.h"
#include "../include/cyberexpert.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

//std::map<const std::string, CyberPC&> cyber_DNS_;

int main(int argc, char *argv[]){

	CyberDNS *myMap = new CyberDNS();


	boost::property_tree::ptree ptComp;
	boost::property_tree::read_xml("./computers.xml", ptComp); // here updating computers names and OS

		BOOST_FOREACH( boost::property_tree::ptree::value_type const& v ,ptComp)
		{
			CyberPC * pc=new CyberPC(v.second.get<std::string>("os"),v.second.get<std::string>("name"));
			myMap->AddPC(*pc);

		}

		using boost::property_tree::ptree;
		ptree ptPoint;
		read_xml("./network.xml", ptPoint);// here updating network connections
		BOOST_FOREACH(ptree::value_type const& v ,ptPoint)
			{
				string p1=v.second.get<std::string>("pointA");
				string p2 = v.second.get<std::string>("pointB");
				cout<< "Connecting "<<p1<<" to " << p2 <<endl;
				(myMap->GetCyberPC(p1)).AddConnection(p2);
				(myMap->GetCyberPC(p2)).AddConnection(p1);
			}

//***************************event1


		int days = 0;
		int totalDays = days;

		std::vector<CyberExpert*>  experts;
		boost::property_tree::ptree ptEvents;
		boost::property_tree::read_xml("./events.xml", ptEvents);

		BOOST_FOREACH( boost::property_tree::ptree::value_type const& v ,ptEvents){



			if(v.first == "hack"){


						cout << "Day : "<< days<< endl;

						string compName = v.second.get<std::string>("computer");
						string wormOS = v.second.get<std::string>("wormOs");
						string wormName = v.second.get<std::string>("wormName");
                        int wormDormancy =v.second.get<int>("wormDormancy");

                        cout << "	Hack occurred on " << compName << endl;


                        CyberPC &tempPC = myMap->GetCyberPC(compName);
                        CyberWorm *cyber_worm =  new CyberWorm(wormOS,wormName,wormDormancy);
                        (tempPC).Infect(*cyber_worm);//infect with worm to PC

                        delete cyber_worm;

                        std::vector<std::string>  list = myMap->GetCyberPCList();

                        for(int i= list.size()-1 ; i>=0; i=i-1) {

                        	string tempString = list[i];
                        	CyberPC &pc1 = myMap->GetCyberPC(tempString);
                        	(pc1).Run(*myMap);
                        }

                        days = days+1;


			}



			if (v.first == "clock-in"){
						cout << "Day : "<< days<< endl;

						string expertName = v.second.get<std::string>("name");
						int workTime = v.second.get<int>("workTime");
						int restTime = v.second.get<int>("restTime");
						int efficiency = v.second.get<int>("efficiency");

						CyberExpert *tempExpert = new CyberExpert (expertName, workTime, restTime, efficiency);

						cout <<"	Clock-In: "<<expertName<<  " began working"<<endl;
						experts.push_back(tempExpert);


				    	std::vector<std::string> compcount = myMap->GetCyberPCList();//vector of all computers
						std::vector<std::string>:: reverse_iterator compcountIT= compcount.rbegin();// iterator indicates place of computer the last expert ends working
						std::vector<CyberExpert*>::iterator it;

						for(it=experts.begin();it!=experts.end();it++){ //clean for all experts
							 if((*it)->ableToWork()){
								 compcountIT =  (*it)->DNSclean(*myMap, compcountIT,compcount);

							 }

						 }

					    std::vector<std::string>  list = myMap->GetCyberPCList();

					   for(int i= list.size()-1 ; i>=0; i=i-1) {//infect all other computers

					       	string tempString = list[i];
					        CyberPC &pc1 = myMap->GetCyberPC(tempString);
					        (pc1).Run(*myMap);

					    }

					   days = days +1;

			}

			if (v.first=="termination"){
						int timeToEnd = v.second.get<int>("time"); //continue running loop up to day : runTimeLeft

						while(days<=timeToEnd){


							cout << "Day : "<< days<< endl;
							std::vector<std::string> compcount = myMap->GetCyberPCList();//vector of all computers
							std::vector<std::string>:: reverse_iterator compcountIT= compcount.rbegin();// iterator indicates place of computer the last expert ends working
							std::vector<CyberExpert*>::iterator it=experts.begin();

//******************************************************************************************************************
							 std::vector<std::string>  list = myMap->GetCyberPCList();
							for(it=experts.begin();it!=experts.end();it++){
							 		if((*it)->ableToWork()){
							 		compcountIT =  (*it)->DNSclean(*myMap, compcountIT,compcount);

							 		}
							}
							 for(int i= list.size()-1 ; i>=0; i=i-1) {
						     	string tempString = list[i];
						       	CyberPC &pc1 = myMap->GetCyberPC(tempString);
						       	(pc1).Run(*myMap);
							 }

					       days = days +1;


						}


			}

        }


delete myMap;


std::vector<CyberExpert*> ::iterator it;

for( it = experts.begin(); it!= experts.end(); it++) {
		delete (*it);

}

int p = getchar();
  return 0;
};

