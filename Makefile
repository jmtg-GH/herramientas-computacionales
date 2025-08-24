# Define el compilador que vamos a usar
CXX = g++

# Define las banderas de compilación. Le estamos pidiendo al compilador que sea estricto y nos muestre todas las advertencias.
CXXFLAGS = -std=c++11 -Wall

# Define las carpetas donde están nuestros archivos
SRCDIR = src
BINDIR = bin

# Encuentra automáticamente todos los archivos .cpp en la carpeta src
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Genera una lista de los nombres de los programas que queremos crear en la carpeta bin
# (básicamente, toma los nombres de los archivos .cpp y los pone en la carpeta bin sin la extensión)
TARGETS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%,$(SOURCES))

# La primera regla es la que se ejecuta por defecto cuando escribimos "make"
# Le decimos que nuestro objetivo es construir todos los programas en la lista TARGETS
all: $(TARGETS)

# Esta es la "receta" genérica para construir cualquier programa.
# Le dice a "make" que para crear un programa en "bin/", necesita el archivo correspondiente en "src/"
$(BINDIR)/%: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR) # Crea la carpeta bin si no existe
	$(CXX) $(CXXFLAGS) -o $@ $< # Compila el archivo. $@ es el nombre del objetivo (ej: bin/programa), $< es el nombre del fuente (ej: src/programa.cpp)

# Esta regla es para limpiar nuestro proyecto. Cuando escribimos "make clean", borra todo lo que hay en la carpeta bin.
clean:
	rm -f $(BINDIR)/*