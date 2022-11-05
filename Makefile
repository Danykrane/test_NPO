TARGET = lunchTM
COMPILE = g++

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC_F = src/
OBJ_F = obj/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
	$(COMPILE) $(OBJ) -o $(TARGET)

# $(OBJ_F)main.o: $(SRC)main.cpp 
# 	$(COMPILE) -c $(SRC_F)main.cpp -o $(OBJ_F)main.o 

# $(OBJ_F)my_func.o: $(SRC_F)my_func.cpp 
# 	$(COMPILE) -c $(SRC_F)my_func.cpp -o $(OBJ_F)my_func.o 
	
# my_func.o : my_func.cpp
# 	$(COMPILE) -c my_func.cpp -o my_func.o

# main.o : main.cpp
# 	$(COMPILE) -c main.cpp -o main.o
 
$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(COMPILE) -c $< -o $@

clean : 
	rm 	$(TARGET) $(PREF_OBJ)*.o



