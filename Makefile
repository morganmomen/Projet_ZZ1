# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
RECUIT_DIR = ../recuit_simule
RULES_DIR = ../rules

# Fichiers sources

RECUIT_SOURCES = $(RECUIT_DIR)/recuit_simule.c
RULES_SOURCES = $(RECUIT_DIR)/rules.c


# Fichiers objets
OBJDIR = .
RECUIT_OBJECTS = $(RECUIT_SOURCES:$(RECUIT_DIR)/%.c=$(OBJDIR)/%.o)
RULES_OBJECTS = $(RULES_SOURCES:$(RULES_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = ce_matin_un_lapin

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(RECUIT_OBJECTS) $(RULES_OBJECTS)
	$(CC)  $^ -o $@ $(LDFLAGS)



# Règle de construction des objets pour le répertoire "../recuit_simule"
$(OBJDIR)/%.o: $(RECUIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Règle de construction des objets pour le répertoire "../rules"
$(OBJDIR)/%.o: $(RULES_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

valgrind:
	 valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=linux_sdl_gl.sup ./$(EXECUTABLE)

