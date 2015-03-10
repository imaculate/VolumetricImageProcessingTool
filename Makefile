CC=g++
CCFLAGS=-std=c++11
program.o: program.cpp functions.o student.h 
   $(CC) $(CCFLAGS)-g program.cpp
   
.cpp.o:
   $(CC) $(CCFLAGS) -c $<
   

   

   
run:
   ./program.o 
      
clean:
   rm -f *.o