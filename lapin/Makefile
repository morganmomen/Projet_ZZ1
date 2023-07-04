# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
AFFICHAGE_DIR = ../affichage/
MAP_DIR = ../Map/
LAPIN_DIR = ./
RULES_DIR = ../rules/
DIJKSTRA_DIR = ../dijkstra/

# Fichiers sources
AFFICHAGE_SOURCES =$(AFFICHAGE_DIR)affichage_fct.c \
					$(AFFICHAGE_DIR)init_SDL.c

MAP_SOURCE = $(MAP_DIR)crea_map.c
LAPIN_SOURCE = $(LAPIN_DIR)mvt_lapin.c
RULES_SOURCE = $(RULES_DIR)rules.c $(RULES_DIR)choixRules.c
DIJKSTRA_SOURCE = $(DIJKSTRA_DIR)dijkstra.c
 

# Fichiers objets
OBJDIR = .
AFFICHAGE_OBJECTS = $(AFFICHAGE_SOURCES:$(AFFICHAGE_DIR)/%.c=$(OBJDIR)/%.o)
MAP_OBJECT = $(MAP_SOURCE:$(MAP_DIR)/%.c=$(OBJDIR)/%.o)
LAPIN_OBJECTS = $(LAPIN_SOURCE:$(LAPIN_DIR)/%.c=$(OBJDIR)/%.o)
RULES_OBJECTS = $(RULES_SOURCE:$(RULES_DIR)/%.c=$(OBJDIR)/%.o)
DIJKSTRA_OBJECTS = $(DIJKSTRA_SOURCE:$(RULES_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = lapin

# Règle par défaut
all: clean $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(AFFICHAGE_OBJECTS) $(MAP_OBJECT) $(LAPIN_OBJECTS) $(RULES_OBJECTS) $(DIJKSTRA_OBJECTS)
	$(CC)  $^ -o $@ $(LDFLAGS) $(CFLAGS)

# Règle de construction des objets pour le répertoire "affichage"
$(OBJDIR)/%.o: $(AFFICHAGE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@	

# Règle de construction des objets pour le répertoire "Map"
$(OBJDIR)/%.o: $(MAP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
#Règle de construction des objets pour le répertoire "Lapin"
$(OBJDIR)/%.o: $(LAPIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
#Règle de construction des objets pour le répertoire "Rules"
$(OBJDIR)/%.o: $(RULES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
#Règle de construction des objets pour le répertoire "Dijkstra"
$(OBJDIR)/%.o: $(DIJKSTRA_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=../linux_sdl_gl.sup ./$(EXECUTABLE)

