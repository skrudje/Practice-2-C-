CC = g++
CFLAGS = -Wall -std=c++17 -I include
LDFLAGS = -lgmpxx -lgmp
SRC_DIR = src
OBJ_DIR = build

OBJS = $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/crypto_math.o \
       $(OBJ_DIR)/task1.o \
       $(OBJ_DIR)/task2.o \
       $(OBJ_DIR)/task3.o \
       $(OBJ_DIR)/task4.o \
       $(OBJ_DIR)/task5.o \
       $(OBJ_DIR)/task6.o

TARGET = pract2

all: $(TARGET)

# сборка всех кусочков в одну программу
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJ_DIR)/main.o

# компиляция остальных файлов из src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)