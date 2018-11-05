 
#include "../include/cyberpc.h" 
#include <vector>
#include <iostream>
#include<iterator>
using namespace std;
std::vector<std::string> cyber_pc_connections_;

 CyberPC::CyberPC(std::string cyber_pc_os,std::string cyber_pc_name): cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name),cyber_pc_connections_(),cyber_pc_time_to_infect_(-1){}



 const std:: string CyberPC::getName() {
   return  cyber_pc_name_;
   
}
 void CyberPC :: setCyberPCTime(int Time){
	 cyber_pc_time_to_infect_ = Time;
 }

 void  CyberPC::AddConnection(std::string  second_pc){
  
 cyber_pc_connections_.push_back(second_pc);
 
 std::cout << "\t" << cyber_pc_name_ << " now connected to " << second_pc << std::endl;
  
};
 
 void CyberPC::Infect(CyberWorm & worm){


	 if(cyber_pc_os_.compare(worm.getOS())==0 ){

		 if(cyber_worm_!=0)
			 delete cyber_worm_;

			 cyber_worm_ = new CyberWorm(worm);
			 cout<< "		"<<cyber_pc_name_ <<" infected by "<< cyber_worm_->getName()<<endl;
			 int time = cyber_worm_->getTime();
			 setCyberPCTime (time);



	 }
	 else{

		 cout << "		Worm "<< worm.getName()<< " is incompatible with "<< getName() << endl;

	 }

 };

 void CyberPC::Disinfect(){
	 cout<< "		Worm "<< cyber_worm_->getName()<<" successfully removed from "<< cyber_pc_name_<< endl;
	 delete(cyber_worm_);
	 cyber_worm_= NULL;
	 cyber_pc_time_to_infect_=-1;

 };

std:: string CyberPC:: getConnection(int i) {

	return cyber_pc_connections_[i];

}
int CyberPC:: getpcTimeToInfect(){
	return cyber_pc_time_to_infect_;
}

bool CyberPC::HaveWorm(){
		bool ans;
	if (cyber_worm_ != NULL){
		ans= true;
	}
	else{
		ans= false;
	}
	return ans;
}


void CyberPC :: Run(const CyberDNS & server){


	if (getpcTimeToInfect()> 0){ //if she's sleeping

		cout << "	"<<getName() << " : "<< "Worm "<< cyber_worm_->getName()<< " is dormant"<< endl;
		this->cyber_pc_time_to_infect_ = this->cyber_pc_time_to_infect_ -1;

	   }
    else if ( cyber_pc_time_to_infect_ == 0){ //else infect computers

    	      cout << "	"<<cyber_pc_name_ << " infecting..."<< endl;
	          std::vector<std::string>::iterator it;
	          for (it = this->cyber_pc_connections_.begin(); it != this->cyber_pc_connections_.end(); it++){


	        	   CyberPC & temp = server.GetCyberPC(*it);
	        	   temp.Infect(*cyber_worm_);

      }

      }


}
CyberPC::~CyberPC(){
if(cyber_worm_!=0)
	 delete cyber_worm_;

}



