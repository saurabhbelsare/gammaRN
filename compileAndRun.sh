# This code requires GSL to be installed and assumes that gsl is installed in /usr/local/include/gsl, and libgsl.so.23 is located in /usr/local/lib. If these are located in different locations, that can be adjusted by changing the corresponding paths in lines 2 and 3. A list of arguments required for the program can be found by running 
# ./gammaRN --help or ./gammaRN -h 

export LD_LIBRARY_PATH=/usr/local/lib # Path to libgsl.so.23
gcc -I/usr/local/include -o gammaRN gammaRN.c -lgsl -lgslcblas -lm
./gammaRN 100 3.0 1.0 gammaRNs.txt
