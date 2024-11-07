fpEx1:
	gcc -o fpEx1 fpEx1.s -mfpu=vfpv3 -lc
	
nfac:
	gcc -o nfactorial nfactorial.s -mfpu=vfpv3 -lc
	
nexp:
	gcc -o nexponential nexponential.s -mfpu=vfpv3 -lc
	
eulersNumber: clean object
	gcc -c -o eulersNumber.o eulersNumber.c
	gcc -o eulersNumber eulersNumber.o nfactorialCCALL.o nexponentialCCALL.o

taylorSeries: clean
	gcc -o SinTaylorSeries SinTaylorSeries.s -mfpu=vfpv3 -lc
	
object:
	as -g -o nfactorialCCALL.o nfactorialCCALL.s -mfpu=vfpv3
	as -g -o nexponentialCCALL.o nexponentialCCALL.s -mfpu=vfpv3 
	
clean:
	rm -f fpEx1
	rm -f nfactorial
	rm -f nexponential
	rm -f eulersNumber
	rm -f SinTaylorSeries
