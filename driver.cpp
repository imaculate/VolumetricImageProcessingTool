#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "VolImage.h"

using namespace std;

int main(int argc, char** argv) {
	if(argc <2){
		cout<<"You should have at least 2 parameters, enter the name of of header file"<<endl;
		return 0;
	}
	
	 VolImage volume ;
      
	
	if(argc == 2){
         volume.readImages(argv[1]);
	
          
         	//do some magic with vectors of unsigned chars;
			cout<< "Number of images: "<< volume.volNum()<< endl;
			cout<< "Number of bytes required: "<< volume.volImageSize()<< endl;
         
        
		

	

    
			
	}else if(argc == 4 ){
		
		
	}else if(argc == 5){
	
	}else if(argc == 6 ){
		
	}else{
		
	}
	return 0;
    
    
}
