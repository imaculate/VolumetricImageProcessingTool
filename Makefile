CC=g++
CCFLAGS=-std=c++11
volimage: driver.cpp VolImage.cpp VolImage.h 
	$(CC) $(CCFLAGS) -g -o volimage driver.cpp VolImage.cpp
   
.cpp.o:
	$(CC) $(CCFLAGS) -c $<
   

   

   
      
clean:
	rm -f *.o
