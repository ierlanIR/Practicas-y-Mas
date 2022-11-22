CC = g++
CFLAGS = -g -Wall -Werror -std=c++17 
LDFLAGS =
SRCFILES = src/diccionario.cc src/embedding.cc src/word_embeddings.cc
TARGET = diccionario
all: $(TARGET)
$(TARGET): $(SRCFILES)
	$(CC) $(CFLAGS) -I include -o $(TARGET) $(SRCFILES) $(LDFLAGS)
clean:
	$(RM) $(TARGET)