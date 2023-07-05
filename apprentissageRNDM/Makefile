# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf -lpthread

# Répertoires
AFFICHAGE_DIR = ../affichage/
MAP_DIR = ../Map/
CHASSEUR_DIR = ../Chasseur/
DIJKSTRA_DIR = ../dijkstra/
RULES_DIR = ../rules/
LAPIN_DIR = ../lapin/
GESTION_JEU_DIR = ../gestion_jeu/
APPRENTISSAGERNDM = ./



# Fichiers sources
AFFICHAGE_SOURCES =	$(AFFICHAGE_DIR)affichage_fct.c \
					$(AFFICHAGE_DIR)ajout_sprite.c \
					$(AFFICHAGE_DIR)init_SDL.c

RULES_SOURCE = $(RULES_DIR)rules.c \
				$(RULES_DIR)choixRules.c

MAP_SOURCE = $(MAP_DIR)crea_map.c

CHASSEUR_SOURCE=$(CHASSEUR_DIR)gere_chasseur.c 

LAPIN_SOURCE=$(LAPIN_DIR)mvt_lapin.c

DIJKSTRA_SOURCE=$(DIJKSTRA_DIR)dijkstra.c

GESTION_JEU_SOURCE=$(GESTION_JEU_DIR)gestion_jeu.c 

APPRENTISSAGERNDM_SOURCE=$(APPRENTISSAGERNDM)apprentissageRNDM.c \
							$(APPRENTISSAGERNDM)apprentissageRNDM_main.c

# Fichiers objets
OBJDIR = .
AFFICHAGE_OBJECTS = $(AFFICHAGE_SOURCES:$(AFFICHAGE_DIR)/%.c=$(OBJDIR)/%.o)
MAP_OBJECT = $(MAP_SOURCE:$(MAP_DIR)/%.c=$(OBJDIR)/%.o)
CHASSEUR_OBJECT = $(CHASSEUR_SOURCE:$(CHASSEUR_DIR)/%.c=$(OBJDIR)/%.o)
LAPIN_OBJECT = $(LAPIN_SOURCE:$(LAPIN_DIR)/%.c=$(OBJDIR)/%.o)
DIJKSTRA_OBJECT = $(DIJKSTRA_SOURCE:$(DIJKSTRA_DIR)/%.c=$(OBJDIR)/%.o)
GESTION_JEU_OBJECT = $(GESTION_JEU_SOURCE:$(GESTION_JEU_DIR)/%.c=$(OBJDIR)/%.o)
RULES_OBJECTS = $(RULES_SOURCE:$(RULES_DIR)/%.c=$(OBJDIR)/%.o)
APPRENTISSAGERNDM_OBJECTS = $(APPRENTISSAGERNDM_SOURCE:$(APPRENTISSAGERNDM)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = apprentissageRNDM

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(AFFICHAGE_OBJECTS) $(MAP_OBJECT) $(CHASSEUR_OBJECT) $(DIJKSTRA_OBJECT) $(GESTION_JEU_OBJECT) $(RULES_OBJECTS) $(LAPIN_OBJECT) $(APPRENTISSAGERNDM_OBJECTS)
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

# Règle de construction des objets pour le répertoire "Gestion_jeu"
$(OBJDIR)/%.o: $(GESTION_JEU_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction des objets pour le répertoire "Rules"
$(OBJDIR)/%.o: $(RULES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de construction des objets pour le répertoire "Lapin"
$(OBJDIR)/%.o: $(LAPIN_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#regle de construction des objets pour le repertoire "apprentissageRNDM"
$(OBJDIR)/%.o: $(APPRENTISSAGERNDM)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	 valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=linux_sdl_gl.sup ./$(EXECUTABLE)

