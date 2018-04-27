 
all: json finix_format finix_exporter finix_capture finix_config finix

finix: source/finix.cc 
	g++ -o bin/finix source/finix.cc finix_config.o finix_exporter.o finix_format.o \
	    finix_capture.o json11.o -O3 -std=gnu++11 -lpthread -lzmq -ltins

finix_config: source/finix_config.cc 
	g++ -o finix_config.o -c source/finix_config.cc -std=gnu++11 

finix_capture: source/finix_capture.cc 
	g++ -o finix_capture.o -c source/finix_capture.cc -std=gnu++11 

finix_exporter: source/finix_exporter.cc 
	g++ -o finix_exporter.o -c source/finix_exporter.cc -std=gnu++11 

finix_format: source/finix_format.cc 
	g++ -o finix_format.o -c source/finix_format.cc -std=gnu++11 

json: source/json11/json11.cpp
	g++ -o json11.o -c source/json11/json11.cpp -std=gnu++11

clean:
	rm -f bin/finix finix_exporter.o finix_capture.o finix_config.o json11.o \
		finix_format.o

