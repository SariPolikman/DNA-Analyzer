#include "view/IIO.h"
#include "controller/dna_analyzer.h"


int main()
{
    register_prototypes();
	CLI ioDevice;
	IIO* iio;
	iio = &ioDevice;
	DnaAnalyzerProject dnaAnalyzerProject(iio);

	dnaAnalyzerProject.run();

    return 0;
}
