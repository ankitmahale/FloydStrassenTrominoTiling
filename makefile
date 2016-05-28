strassen: mahale_pa2_stra.cpp mahale_pa2_stra.h mahale_pa2_stra1.h
	g++ mahale_pa2_stra.cpp -o first
	./first 4

tromino: mahale_pa2_tro.cpp mahale_pa2_tro.h mahale_pa2_tro1.h
	g++ mahale_pa2_tro.cpp -o second
	./second 4

floyd: mahale_pa2_floyd.cpp mahale_pa2_floyd.h mahale_pa2_floyd1.h
	g++ mahale_pa2_floyd.cpp -o third
	./third input.txt
