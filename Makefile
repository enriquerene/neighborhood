# https://stackoverflow.com/a/8671381/5382576
# O nome das variáveis são totalmente arbitrárias mas segui um padrão de nomenclatura comum.
# CC - Compilador
CC = gcc
# BIN_FILE - nome do arquivo binário resultante
BIN_FILE = nbhd
# BIN_TEST - nome do arquivo binário de teste
BIN_TEST = run-test
# TEST_DIR - diretório para arquivos de testes
TEST_DIR = tests
# TEST_FILES - arquivos cpp para testes
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
# CC_FLAGS - opções de compilação geral
# https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
CC_FLAGS = -std=c18 -lm
# CC_TEST_FLAGS - opções de compilação para tetes
CC_TEST_FLAGS = $(CC_FLAGS)
# CC_FLAGS - opções de compilação para o app
CC_APP_FLAGS = $(CC_FLAGS)
# C_FILES - arquivos cpp
C_FILES = $(wildcard src/*.c)
# H_FILES - arquivos hpp
H_FILES = $(wildcard src/*.h)
# LIBS_HEADER - arquivos hpp
LIBS_HEADER = $(wildcard libs/*.h)
# OBJ_FILES - arquivos .o oriundas da compilação
OBJ_FILES = $(C_FILES:.c=.o)
# OBJ_DIR - diretório para arquivos de objetos .o
OBJ_DIR = obj

all: objDir $(BIN_FILE)

$(BIN_FILE): $(OBJ_FILES)
	@ echo "Construindo binário a partir do linker do GCC: $@"
	$(CC) $^ -o $@
	@ echo " "

$(OBJ_DIR)/%.o: src/%.c src/%.h
	@ echo "Construindo objetos a partir do compilador do GCC: $<"
	$(CC) $< $(CC_APP_FLAGS) -o $@
	@ echo " "

$(OBJ_DIR)/main.o: src/main.c $(LIBS_HEADER) $(H_FILES)
	@ echo "Construindo objetos a partir do compilador do GCC: $<"
	$(CC) $< $(CC_APP_FLAGS) -o $@
	@ echo " "

objDir:
	@ echo "Criando diretório $(OBJ_DIR)"
	@ mkdir -p $(OBJ_DIR)

clean:
	@ echo "Removendo arquivos em $(OBJ_DIR)"
	@ echo "Removendo arquivos de backup"
	@ echo "Removendo arquivo $(BIN_FILE)"
	@ rm -rf $(OBJ_DIR) $(BIN_FILE) *~
	@ echo "Removendo arquivos de teste"
	@ rm $(BIN_TEST)

test: $(BIN_TEST)
	@ echo "Iniciando testes"
	@ ./$(BIN_TEST) --reporter console --success

testlog: $(BIN_TEST)
	@ echo "Iniciando testes..."
	@ echo "Armazenando em $(TEST_DIR)/testlog.txt"
	@ ./$(BIN_TEST) --reporter console --success > "$(TEST_DIR)/testlog.txt"

$(BIN_TEST): $(TEST_FILES)
	@ echo "Construindo binário de teste a partir do linker do GCC: $@"
	$(CC) $^ $(CC_TEST_FLAGS) -o $@
	@ echo " "

.PHONY: all clean test testlog
