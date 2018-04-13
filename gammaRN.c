#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_rng.h>

double gsl_ran_gamma(const gsl_rng *r, double a, double b);

int main(int argc, char** argv){
    printf("This program generates gamma random numbers using the GNU Scientific Library(GSL) implementation\n\n");
    if (argc < 4 || argv[1]=="--help" || argv[1]=="-h"){\
        printf("Usage: ./gammaRN numRN alpha beta [outfile]\n\
        This program needs three required arguments and one optional arguments in the following format:\n\
        1. numRN = Number of random numbers to generate (integer)\n\
        2. alpha = Value for the alpha parameter (float)\n\
        3. beta = Value for the beta parameter (float)\n\
        4. outfile = Name of the output file (string) [default gammaRNs.txt]\n");
        exit(0);
    }
    FILE *fout;
    if (argc == 5){
        fout = fopen(argv[4],"w");
    }
    else{
        fout = fopen("gammaRNs.txt","w");
    }

    int numRNs = atoi(argv[1]);
    double a = atof(argv[2]);
    double beta = atof(argv[3]);
    double b = 1.0/beta;
    printf("The input parameters chosen are:\n");
    printf("Number of gamma random numbers to be generated = %i\n",numRNs);
    printf("alpha = %f\n",a);
    printf("beta = %f\n",beta);
    gsl_rng * r = gsl_rng_alloc (gsl_rng_mt19937);
    double c;
    for (int i = 0; i < numRNs; i++){
        c = gsl_ran_gamma(r, a, b);
        fprintf(fout, "%f\n",c);
    }
    fclose(fout);
    return 0;
}
