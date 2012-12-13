#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <boost/foreach.hpp>
#include <std_msgs/Int32.h>

//or just use $ rostopic echo -b file.bag -p /topic

int main(int argc, char *argv[])
{

	if (argc =!2)
	{
		
		std::cout << "Too many (or no) arguments........arg= filename.bag \n";
		std::cout << "number of args:" << argc << "\n";
		std::cout << argv[1] << "\n";
		return -1;

	}

	std::cout << "Extracting data from: " << argv[1] <<std::endl;

	std::stringstream ss;
	std::string argv_name;
	std::string argv_fullname;
	std::ofstream myfile;
	time_t rawtime;
	struct tm * timeinfo;
	char str_now [80];

	ss << argv[1];
	ss >> argv_name;
	argv_fullname=argv_name;
	argv_name.erase(argv_name.end()-4,argv_name.end());

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

  strftime (str_now,80,"%c",timeinfo);

	myfile.open ((argv_name+ ".csv").c_str(), std::ios::out | std::ios::app);
	myfile  << str_now << "," << "ROSBAG decomposition: " << argv_name ;

	rosbag::Bag bag;
	bag.open(argv_fullname, rosbag::bagmode::Read);
	rosbag::View view(bag);

	BOOST_FOREACH(rosbag::MessageInstance const m, view)
	{
		if (m.getTopic() == "/cmd_vel/x")
		{
			std_msgs::Int32::ConstPtr value = m.instantiate<std_msgs::Int32>();
			if (value != NULL)
			{	
				myfile << value->data<< std::endl;
			}
		}//if topic
		//else if (other topics) {}
	}//boost
	bag.close();
 	myfile.close();
	return 0;
}//main
