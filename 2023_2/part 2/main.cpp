#include <iostream>
#include <fstream>
#include <vector>
#include <map>

std::map<std::string, int>& check_subset(std::string& str, std::map<std::string, int>& color_count){
	//subset -> 11 red, 19 green, 1 blue
	std::size_t start=0;
	while(start!=std::string::npos){
		//substr(pos, len);
		//size_t find (char c, size_t pos = 0) const noexcept;
		std::size_t finish=str.find(',',start+1);
		std::string color=str.substr(start+1, finish-start-1);
		//int num=std::strtok(color.c_str,' ');
		//std::string c=std::strtok(NULL,' ');
		size_t pos=color.find("red");
		int count=0;
		if(pos!=std::string::npos){
			count=std::stoi(color.substr(0, pos-1));
			if(count>color_count["red"])
				color_count["red"]=count;
			
		}else if((pos=color.find("green"))!=std::string::npos){
			count=std::stoi(color.substr(0, pos-1));
			if(count>color_count["green"])
				color_count["green"]=count;
			
			
		}else if((pos=color.find("blue"))!=std::string::npos){
			count=std::stoi(color.substr(0, pos-1));
			if(count>color_count["blue"])
				color_count["blue"]=count;
			
		}
		
		
		start=finish;
	}
	
	
	return color_count;
}



int get_power(std::string& str){
	int retval=0;
	std::map<std::string, int> color_count;
	color_count["red"]=0;
	color_count["green"]=0;
	color_count["blue"]=0;
	//example -> Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
	
	std::size_t start=str.find(':');
	while(start!=std::string::npos){
		//substr(pos, len);
		//size_t find (char c, size_t pos = 0) const noexcept;
		std::size_t finish=str.find(';',start+1);
		std::string subset=str.substr(start+1, finish-start-1);
		//subsets.push_back(subset);

		color_count=check_subset(subset,color_count);
		start=finish;
	}
	
	retval=color_count["red"]*color_count["green"]*color_count["blue"];
	
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
		//std::cout<<str<<std::endl;
		sum+=get_power(str);

	}
	std::cout<<sum<<std::endl;
	file.close();
}
