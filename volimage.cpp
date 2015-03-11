#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ios>

using namespace std;
class VolImage
{

private:
   int width, height;
   vector<unsigned char**>* slices;
public: 
   VolImage(){
      width = 0; height = 0;
      slices = new vector<unsigned char**>();
   } 
   ~VolImage(){
      std::vector<unsigned char**> slices;
   } // destructor - define in .cpp file
// populate the object with images in stack and
//set member variables define in .cpp
   bool readImages(std::string baseName){
      int  number;
      string headerName = baseName + ".dat";
      ifstream header(headerName.c_str() , ios::binary);
      string line;
      
      if (header.is_open()) {
         getline (header,line);
         istringstream iss(line);
        	
         iss >> width;
         iss >> height;
         iss >> number;
        
         header.close();
      }
      else{
         cout<<"Unable to open file, ensure correct filename"<<endl;	
         return false;	
      }
      
      for(int i = 0; i< number; i++){
         //CONVERT i TO A STRING.
         stringstream ss;
         ss << i;
         string str = ss.str();
         string fileName = baseName + str +".raw";
         
         ifstream pic(fileName.c_str(),  ios::binary);
         
         
         
         string lines;
         unsigned char byte;
         if (pic.is_open()) {
            
            
          
        	
         
         

         
            for(int j = 0; j< height; j++){
               getline (pic,lines);
               istringstream iss(lines);
               for(int k = 0; k< width; k++){
                    iss >> byte;
                     unsigned char ** ptr = *(*slices[i]);
               }
            
            }  
         }         
      }
      return true;
      
   
         
   }
// compute difference map and write out; define in .cpp
   void diffmap(int sliceI, int sliceJ, std::string output_prefix);
// extract slice sliceId and write to output - define in .cpp
   void extract(int sliceId, std::string output_prefix);
// number of bytes uses to store image data bytes
//and pointers (ignore vector<> container, dims etc)
   int volImageSize(void); // define in .cpp
};