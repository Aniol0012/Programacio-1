
TARGET=filtrar-vacunes finestra-vacunes

all: $(TARGET)

filtrar-vacunes : filtrar-vacunes.cc

finestra-vacunes : finestra-vacunes.cc

clean:
	$(RM) $(TARGET)

test: $(TARGET)
	@for fitxer in tests/*.csv; do \
		echo Testing $$fitxer; \
		cat $$fitxer | ./filtrar-vacunes | ./finestra-vacunes; \
	done
