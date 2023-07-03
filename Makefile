# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
RULES_DIR = ./rules

# Fichiers sources

RULES_SOURCES = $(RULES_DIR)/rules.c $(RULES_DIR)/changeRules.c


# Fichiers objets
OBJDIR = .
RULES_OBJECTS = $(RULES_SOURCES:$(RULES_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = ce_matin_un_lapin

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(RULES_OBJECTS)
	$(CC)  $^ -o $@ $(LDFLAGS)


# Règle de construction des objets pour le répertoire "../rules"
$(OBJDIR)/%.o: $(RULES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	 valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=linux_sdl_gl.sup ./$(EXECUTABLE)

