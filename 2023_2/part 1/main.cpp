#include <iostream>
#include <fstream>
#include <vector>

/*
returns the game number if possible, else returns 0 not to change the sum
*/

// total: 12 red cubes, 13 green cubes, and 14 blue cubes
enum Cubes{
	red=12,
	green=13,
	blue=14
};

bool check_subset(std::string& str){
	//subset -> 11 red, 19 green, 1 blue
	std::size_t start=0;
	while(start!=std::string::npos){
		//substr(pos, len);
		//size_t find (char c, size_t pos = 0) const noexcept;
		std::size_t finish=str.find(',',start+1);
		std::string color=str.substr(start+1, finish-start-1);
		
		size_t pos=color.find("red");
		if(pos!=std::string::npos){
			if(std::stoi(color.substr(0, pos-1))>Cubes::red)
				return false;
			
		}else if((pos=color.find("green"))!=std::string::npos){
			if(std::stoi(color.substr(0, pos-1))>Cubes::green)
				return false;
			
			
		}else if((pos=color.find("blue"))!=std::string::npos){
			if(std::stoi(color.substr(0, pos-1))>Cubes::blue)
				return false;
			
		}
		
		
		start=finish;
	}
	
	
	return true;
}



int is_possible(std::string& str){
	int retval=0;
	//example -> Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
	//std::vector<std::string> subsets;
	std::size_t start=str.find(':');
	while(start!=std::string::npos){
		//substr(pos, len);
		//size_t find (char c, size_t pos = 0) const noexcept;
		std::size_t finish=str.find(';',start+1);
		std::string subset=str.substr(start+1, finish-start-1);
		//subsets.push_back(subset);

		if(!check_subset(subset))
			return 0;		
		start=finish;
	}
	
	retval=std::stoi(str.substr(5, str.find(':')));

	return retval;
}


int main(){
	std::ifstream file("input");
	if(!file){
		std::cout<<"dosya açılmadı\n";
		return -1;
	}
	std::string str;
	int sum=0;
	while(getline(file, str)){

		sum+=is_possible(str);

	}
	std::cout<<sum<<std::endl;
	file.close();
}
