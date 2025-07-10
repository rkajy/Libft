# Dossiers
PATHO = build/objs/
PATHR = build/results/
PATHD = build/depends/
PATHT = test/
PATHS = src/
UNITY = unity/src/

# Fichiers objets
_OBJS = $(patsubst $(PATHS)%.c, $(PATHO)%.o, $(wildcard $(PATHS)*.c))
BUILD_PATHS = $(PATHO) $(PATHR) $(PATHD)

# Compilation
CC = cc
CFLAGS = -I. -I$(PATHD) -I$(PATHS) -I$(UNITY) -DTEST
LDFLAGS =

# Résultats des tests
TEST_SRCS = $(wildcard $(PATHT)*Test*.c)
TEST_BINS = $(patsubst $(PATHT)%.c, $(PATHR)%, $(TEST_SRCS))
RESULTS = $(addsuffix .txt, $(TEST_BINS))

# Couleurs ANSI
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m

# Règles principales
all: $(BUILD_PATHS) compile

compile: $(_OBJS)

test: $(BUILD_PATHS) $(RESULTS)
	@echo "\n$(YELLOW)================ IGNORE ================\n$(NC)"
	@grep -s IGNORE $(PATHR)*.txt || true
	@echo "\n$(RED)================ FAILURES ===============\n$(NC)"
	@grep -s FAIL $(PATHR)*.txt || true
	@echo "\n$(GREEN)================ PASSED ================\n$(NC)"
	@grep -s PASS $(PATHR)*.txt || true
	@echo "\n$(NC)================ DONE ==================\n"

install:
	@echo "No install step defined"

# Compilation des tests (exécutables)
$(PATHR)%: $(PATHT)%.c $(PATHO)unity.o $(_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Exécution des tests -> résultats dans fichiers .txt
$(PATHR)%.txt: $(PATHR)%
	@./$< > $@ 2>&1 || true

# Compilation des fichiers sources
$(PATHO)%.o: $(PATHS)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de Unity
$(PATHO)unity.o: $(UNITY)unity.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des dossiers
$(BUILD_PATHS):
	@mkdir -p $@

clean:
	rm -rf $(PATHO) $(PATHR) $(PATHD)

.PHONY: all compile test clean install