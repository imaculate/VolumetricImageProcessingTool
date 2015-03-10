#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	if(argc <2){
		cout<<"You should have at least 2 parameters, enter the name of of header file"<<endl;
		return 0;
	}
	string head;
	int width, height , number;
	string file = string(argv[1]);
		ifstream header;
		header.open (file+".dat", ios::in| ios::binary);
		if (header.is_open()) {
			getline (head,line);
			istringstream iss(head);
        	
       		iss >> width;
			iss >> height;
			iss >> number;
        
		header.close();
		}else{
			cout<<"Unable to open file"<<endl;		
		}
	
	if(argc == 2){
	
          
         	//do some magic with vectors of unsigned chars;
			cout<< "Number of images: "<< number<< endl;
			cout<< "Number of bytes required: "<< number*width*height << endl;
         
        
		

	

    
			
	}else if(argc == 4 ){
		
		
	}else if(argc == 5){
	
	}}else if(argc == 6 ){
		
	}else{
		cout<<
		}
	return 0;
    
    
}
