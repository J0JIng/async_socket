
CC = g++
FLAGS = -std=c++20 -Wall -Wextra -g
TARGET = client 
OBJS = client.o 

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS) $(TARGET)