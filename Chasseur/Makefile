# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
AFFICHAGE_DIR = ../affichage/
MAP_DIR = ../Map/
CHASSEUR_DIR = ./
DIJKSTRA_DIR = ../dijkstra/

# Fichiers sources
AFFICHAGE_SOURCES =	$(AFFICHAGE_DIR)affichage_fct.c \
					$(AFFICHAGE_DIR)init_SDL.c \

MAP_SOURCE = $(MAP_DIR)crea_map.c

CHASSEUR_SOURCE=$(CHASSEUR_DIR)gere_chasseur.c \
				$(CHASSEUR_DIR)gere_chasseur_main.c

DIJKSTRA_SOURCE=$(DIJKSTRA_DIR)dijkstra.c

# Fichiers objets
OBJDIR = .
AFFICHAGE_OBJECTS = $(AFFICHAGE_SOURCES:$(AFFICHAGE_DIR)/%.c=$(OBJDIR)/%.o)
MAP_OBJECT = $(MAP_SOURCE:$(MAP_DIR)/%.c=$(OBJDIR)/%.o)
CHASSEUR_OBJECT = $(CHASSEUR_SOURCE:$(CHASSEUR_DIR)/%.c=$(OBJDIR)/%.o)
DIJKSTRA_OBJECT = $(DIJKSTRA_SOURCE:$(DIJKSTRA_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = gere_chasseur

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(AFFICHAGE_OBJECTS) $(MAP_OBJECT) $(CHASSEUR_OBJECT) $(DIJKSTRA_OBJECT)
	$(CC)  $^ -o $@ $(CFLAGS) $(LDFLAGS)

# Règle de construction des objets pour le répertoire "affichage"
$(OBJDIR)/%.o: $(AFFICHAGE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@	

# Règle de construction des objets pour le répertoire "Map"
$(OBJDIR)/%.o: $(MAP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction des objets pour le répertoire "Chasseur"
$(OBJDIR)/%.o: $(CHASSEUR_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction des objets pour le répertoire "Dijkstra"
$(OBJDIR)/%.o: $(DIJKSTRA_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	 valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=linux_sdl_gl.sup ./$(EXECUTABLE)

