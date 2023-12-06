# Nom du fichier exécutable
TARGET = Automaton

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g -std=c11 -fsanitize=address

# Répertoire pour les fichiers objets
OBJ_DIR = obj

# Répertoire pour les fichiers header
INC_DIR = include

SRC_DIR = src

# Liste des fichiers source (à ajouter/modifier en fonction de vos fichiers)
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard tests/*.c) main.c

# Liste des fichiers header
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Liste des fichiers objet générés à partir des sources
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:.c=.o)))


# Règle par défaut
all: $(TARGET)

# Règle de création de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Règle de compilation des fichiers source en fichiers objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Règle de compilation pour le fichier main.c
$(OBJ_DIR)/main.o: main.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Règle de compilation pour les fichiers source du dossier "tests"
$(OBJ_DIR)/%.o: tests/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	
# Nettoyer les fichiers temporaires
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

gdb: $(TARGET)
	gdb $(TARGET)