# Nom du fichier exécutable
TARGET = Automate

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -std=c11

# Répertoire pour les fichiers objets
OBJ_DIR = obj

# Répertoire pour les fichiers header
INC_DIR = include

# Liste des fichiers source
SOURCES = FiniteAutomaton.c Etat.c main.c

# Liste des fichiers header
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Liste des fichiers objet générés à partir des sources
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

# Règle par défaut
all: $(TARGET)

# Règle de création de l'exécutable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Règle de compilation des fichiers source en fichiers objet
$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Nettoyer les fichiers temporaires
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
