CC = gcc
CFlags = -W -Wall
TARGET = product
OBJECTS = product.o market.o 

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFlags) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFlags) -DDEBUG -o $@ $^

clean : 
	rm *.o $(TARGET) $(DTARGET)
