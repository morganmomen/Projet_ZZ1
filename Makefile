# Variables
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS =-lSDL2 -lSDL2_image -lm -lSDL2_ttf

# Répertoires
RECUIT_DIR = ../recuit_simule

# Fichiers sources

RECUIT_SOURCES = $(RECUIT_DIR)/*.c

# Fichiers objets
OBJDIR = .
RECUIT_OBJECTS = $(RECUIT_SOURCES:$(RECUIT_DIR)/%.c=$(OBJDIR)/%.o)


# Exécutable
EXECUTABLE = ce_matin_un_lapin

# Règle par défaut
all: $(EXECUTABLE)

# Règle de construction de l'exécutable
$(EXECUTABLE): $(RECUIT_OBJECTS)
	$(CC)  $^ -o $@ $(LDFLAGS)



# Règle de construction des objets pour le répertoire "../recuit_simule"
$(OBJDIR)/%.o: $(RECUIT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)

