CC=g++
CCFLAGS=-std=c++11
volimage: driver.cpp VolImage.o VolImage.h 
   $(CC) $(CCFLAGS)-g -o volimage driver.cpp
   
.cpp.o:
   $(CC) $(CCFLAGS) -c $<
   

   

   
      
clean:
   rm -f *.o