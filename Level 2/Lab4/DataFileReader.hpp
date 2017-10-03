#ifndef DATAFILEREADERH
#define DATAFILEREADERH

#include <string>
#include <fstream>

template<typename T>
class DataFileReader 
{
	public:
		DataFileReader(std::string aDataFileName, std::string aErrorFileName);
		/* pre: A file named aDataFile contains values to read.
		*/
		~DataFileReader()
		{
			is.close();
			os.close();
		}
		/* post: Files are closed */
		void openFiles();
		/* post: An input stream from the file named aDataFile and
		an output stream to the file named aErrorFile are
		opened. If either of these operations fails a
		runtime_error exception is thrown. */
		bool readNextValue(T &aValue);
		/* pre: openFiles has been successfully called.
		post: If a value has been successfully read, aValue
		holds that value and true is returned.
		Else, the read operation encountered an
		end-of-file and false is returned. */
	private:
		// bool filesopen gets set to true after openFiles has been called without errors
		bool filesOpen;
		
		// String with names of the data and error files
		const std::string dataFileName;
		const std::string errorFileName;
		// declaring file streams
		std::ofstream os;
		std::ifstream is;

};
#endif 