#include <RInside.h>
#include <iomanip>

int main(int argc, char *argv[]) {
	try {	
		RInside R(argc, argv);

		R["csv_file"] = "TR_unemployment_rates.csv";
		std::string csv_import_script = "data <- read.csv(csv_file, header=TRUE, sep=',', stringsAsFactors=TRUE)";	
		R.parseEvalQ( csv_import_script );

		// summary with rxSummary
		std::string summary_script = 	"df <- rxDataStep(inData=data, rowSelection = (UnemploymentTotal > 10.0));";
		R.parseEvalQ(summary_script);
		std::string output = "print(df)";
		R.parseEvalQ(output);
	} catch(std::exception& ex) {
        	std::cerr << "Exception caught: " << ex.what() << std::endl;
    	} catch(...) {
        	std::cerr << "Unknown exception caught" << std::endl;
    	}
	return(0);
}

