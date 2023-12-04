#include <iostream>
#include <fstream>
#include <vector>


int get_int(std::string str){
	int sum=0;
	std::string numbers="0123456789";
	std::vector<std::string> digit_strings{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
													
	//std::cout<<str<<" -> ";
	
	for(size_t start=0;start<str.size();++start){

		for(size_t i=1;i<digit_strings.size();++i){
			std::string sub_str=str.substr(start,digit_strings[i].size());
			size_t index=sub_str.find(digit_strings[i]);
			if(index!=std::string::npos){
				/*
					The right calibration values for string "eighthree" is 83 and for "sevenine" is 79.
					The examples do not cover such cases.
				*/
				str.replace(start+index,1,std::to_string(i));
				break;
			}
		}
	}
	
	//std::cout<<str<<" -> ";
	
	for(char ch : str){
		size_t i=numbers.find(ch);
		if(i!=std::string::npos){
			sum+=10*i;
			break;
		}
		
	}
	
	for(auto index=str.size();index>=0;--index){
		char ch=str[index];
		size_t i=numbers.find(ch);
		if(i!=std::string::npos){
			sum+=i;
			break;
		}
	}
	
	//std::cout<<sum<<"\n";
	return sum;
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
		sum+=get_int(str);
	}
	std::cout<<sum<<std::endl;
	file.close();
}

