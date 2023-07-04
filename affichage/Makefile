# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
AFFICHAGE_DIR = ./
MAP_DIR = ../Map/

# Fichiers sources
AFFICHAGE_SOURCES = $(AFFICHAGE_DIR)ajout_sprite.c\
					$(AFFICHAGE_DIR)affichage_main.c \
					$(AFFICHAGE_DIR)affichage_fct.c \
					$(AFFICHAGE_DIR)init_SDL.c \
					

MAP_SOURCE = $(MAP_DIR)crea_map.c

# Fichiers objets
OBJDIR = .
AFFICHAGE_OBJECTS = $(AFFICHAGE_SOURCES:$(AFFICHAGE_DIR)/%.c=$(OBJDIR)/%.o)
MAP_OBJECT = $(MAP_SOURCE:$(MAP_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = affichage

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(AFFICHAGE_OBJECTS) $(MAP_OBJECT)
	$(CC)  $^ -o $@ $(LDFLAGS)

# Règle de construction des objets pour le répertoire "affichage"
$(OBJDIR)/%.o: $(AFFICHAGE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@	

# Règle de construction des objets pour le répertoire "Map"
$(OBJDIR)/%.o: $(MAP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@



# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	 valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=linux_sdl_gl.sup ./$(EXECUTABLE)

