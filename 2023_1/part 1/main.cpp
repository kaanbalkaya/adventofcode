#include <iostream>
#include <fstream>

int get_int(std::string str){
	int sum=0;
	std::string numbers="0123456789";
	for(char ch : str){
		int i=numbers.find(ch);
		if(i!=-1){
			sum+=10*i;
			break;
		}
		
	}
	
	for(auto index=str.size();index>=0;--index){
		char ch=str[index];
		int i=numbers.find(ch);
		if(i!=-1){
			sum+=i;
			break;
		}
	}
	return sum;
}


int main(){
	std::ifstream file("input.txt");
	if(!file){
		std::cout<<"dosya açılmadı\n";
		return -1;
	}
	std::string str;
	int sum=0;
	while(getline(file, str)){
		//std::cout<<str<<std::endl;
		sum+=get_int(str);
	}
	std::cout<<sum<<std::endl;
	file.close();
}
