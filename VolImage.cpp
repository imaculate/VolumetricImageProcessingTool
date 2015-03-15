#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ios>
#include <cmath>
#include "VolImage.h"

using namespace std;

 
MSHIMA001::VolImage::VolImage(){
   width = 0; height = 0;
 
} 
MSHIMA001::VolImage::~VolImage(){
   for(int l = 0; l< slices.size(); l++){
      for(int m = 0; m< height; m++){
        /* for(int n = 0; n< width; n++){
            delete  slices[l][m][n];
         }*/
         delete [] slices[l][m];
      }
      delete slices[l];
      
      
   }
} 
bool MSHIMA001::VolImage::readImages(std::string baseName){
   int  number;
   string headerName = baseName + ".data";
   ifstream header(headerName.c_str() , ios::binary);
   string line;
   
   if (header.is_open()) {
      getline (header,line);
      istringstream iss(line);
     	
      iss >> width;
      iss >> height;
      iss >> number;
      
      //cout<<"height "<<height<<"width "<< width<<endl;
      header.close();
   }
   else{
      cout<<"Unable to open file, ensure correct filename"<<endl;	
      return false;	
   }
   unsigned char** buffer;
   for(int i = 0; i< number; i++){
      //CONVERT i TO A STRING.
      stringstream ss;
      ss << i;
      string str = ss.str();
      string fileName = baseName + str +".raw";
      
      ifstream pic(fileName.c_str(),  ios::binary);
      
      
      
     
     
      if (pic.is_open()) {
         
         
         buffer = new unsigned char*[height];
         
         unsigned char* row;
         for(int j =0; j< height; j++){
            row = new unsigned char[width];
            pic.read((char*)row, width);
            buffer[j]= row;
            
         
         }
        
          
         slices.push_back(buffer);
        
       
         pic.close();
      
      }
               
   
      
              
   }
   return true;
   

      
}
// compute difference map and write out; define in .cpp
void MSHIMA001::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
   string header = output_prefix + ".data";
   ofstream head(header.c_str(), ios::out);
   if(head.is_open()){
      head<< width<< " "<< height<< " "<< 1<< endl;
        cout<< "Created header file "<<header<<endl;
      head.close();
   }else{
      cout<<"Unable to open file"<<header<<endl;
   }
   string outName = output_prefix + ".raw";
   ofstream out(outName.c_str(), ios::binary);
   if(out.is_open()){
      for(int i=0; i< height; i++){
         
      
         for(int j=0; j< width; j++){
            char byte = abs(((float)slices[sliceI][i][j]- (float)slices[sliceJ][i][j])/2);
            out.write(&byte,1);
         }
      
      }
      out.close();
   
   }
   else{
      cout<<"Unable to open file "<<outName<<endl;
   }
}
// extract slice sliceId and write to output - define in .cpp
void MSHIMA001::VolImage::extract(int sliceId, std::string output_prefix){
    string header = output_prefix + ".data";
   ofstream head(header.c_str(), ios::out);
   if(head.is_open()){
      head<< width<< " "<< height<< " "<< 1<< endl;
      cout<< "Created header file "<<header<<endl;
      head.close();
   }else{
      cout<<"Unable to open file"<<header<<endl;
   }


   string outName = output_prefix + ".raw";
   ofstream out(outName.c_str(), ios::binary);
   if(out.is_open()){
   
      
      
      for(int j=0; j< height; j++){
         char* byte = (char*)slices[sliceId][j];
         out.write(byte,width);
      }
      
   
      out.close();
   
   }
   else{
      cout<<"Unable to open file"<<endl;
   }
}

   

// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
int MSHIMA001::VolImage::volImageSize(void){
   int number = slices.size();
   return number* height*(sizeof(unsigned char**)+ width);
}

int MSHIMA001::VolImage::volNum(void){
   return slices.size();
}
//added method for -g option
void MSHIMA001::VolImage::extractRow(int rowId, std::string output_prefix){

    string header = output_prefix + ".data";
   ofstream head(header.c_str(), ios::out);
   if(head.is_open()){
      head<< width<< " "<< height<< " "<< 1<< endl;
        cout<< "Created header file "<<header<<endl;
      head.close();
   }else{
      cout<<"Unable to open file"<<header<<endl;
   }

   string outName = output_prefix + ".raw";
   ofstream out(outName.c_str(), ios::binary);
   if(out.is_open()){
   
      
      
      for(int i=0; i< slices.size(); i++){
         char* byte = (char*)slices[i][rowId];
         out.write(byte,width);
      }
      
   
      out.close();
   
   }

   
}
