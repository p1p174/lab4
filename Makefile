IDIR = include
CC = g++
//CFLAGS = -std=c++98 -Wall -Wextra -I$(IDIR) -g
CFLAGS = -std=c++11 -Wall -Wextra -I$(IDIR) -g

CPPDIR = src
ODIR = obj

ARCHIVOS = Calificacion CargaDatos Conductor ControladorFechaActual ControladorUsuario CtrlViaje DTConsultaViaje DTDetalleReserva DTDetalleVehiculo DTDetalleViaje DTFecha DTListarViaje DTUsuario DTUsuarioViaje DTVehiculosConductor Fabrica IControladorFechaActual IUsuario IViaje ManejadorUsuario ManejadorVehiculo ManejadorViaje Pasajero Reserva TipoLibreta TipoUsuario TipoVehiculo Usuario Vehiculo Viaje
MODULOS = $(ARCHIVOS)

HS   = $(MODULOS:%=$(IDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)


all: programa

$(ODIR):
	mkdir -p $(ODIR)

programa: |$(ODIR) $(ODIR)/main.o $(OS)
	$(CC) -o programa $(ODIR)/main.o $(OS) $(CFLAGS)
	

$(ODIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(ODIR)/main.o

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ODIR)/*.o programa

run: all
	./programa

entrega:
	zip -r 26_lab0.zip $(IDIR) $(CPPDIR) Makefile main.cpp