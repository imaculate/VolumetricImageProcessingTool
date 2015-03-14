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
	
	 MSHIMA001::VolImage volume ;
    volume.readImages(argv[1]);
	
	if(argc == 2){
        
	
          
         	//do some magic with vectors of unsigned chars;
			cout<< "Number of images: "<< volume.volNum()<< endl;
			cout<< "Number of bytes required: "<< volume.volImageSize()<< endl;
         
        
		

	

    
			
	}else if(argc == 6){
      if(string(argv[2]).compare("-d")==0){
         int i,j;
         istringstream iss(argv[3]);
         istringstream jss(argv[4]);
         iss>>i; jss>>j;
         
         volume.diffmap(i,j,argv[5]);
         
         cout<<"The difference between images "<< i <<" and "<<j<<" has been stored in "<< argv[5]<< ".raw"<<endl;
         
      }else{
         //error handling.
          cout<<"Enter correct arguments."<<endl;
          cout<< "volimage <imageBase> -d i j output_file_name"<<endl;
      }
	
	}else if(argc == 5 ){
      if(string(argv[2]).compare("-x")==0){
         int i;
         istringstream iss(argv[3]);
         iss>>i;
         volume.extract(i,argv[4]);
         cout<< "The image at "<< i<< " has been extracted to "<< argv[4]<<".raw"<<endl;
         
         
      }else if(string(argv[2]).compare("-g")==0){
         int i;
         istringstream iss(argv[3]);
         iss>>i;
         volume.extractRow(i,argv[4]);
         cout<< "The row at "<< i<< " of all slices has been extracted to "<< argv[4]<<".raw"<<endl;

         
         
      }else{
         cout<<"Enter correct arguments."<<endl;
         cout<< "volimage <imageBase> -x i output file name OR"<<endl;
         cout<<"volimage <imagebase> -g i output_file_name"<<endl;
         
      }
      
      
     }else{
		   cout<<"Enter correct format of commands"<<endl;
         cout<<"volimage <imageBase>"<<endl;
         cout<<"volimage <imagebase> -g i utput_file_name"<<endl;
         cout<<"volimage <imageBase> -x i output file name:"<<endl;
         cout<<"volimage <imageBase> -d i j output_file_name"<<endl;
	}
	return 0;
    
    
}
