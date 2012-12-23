#include "file_system_helper.h"
#include "KfsClient.h"

/*
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

// static logger variable
LoggerPtr logger(Logger::getLogger( "appendstore"));
*/

using std::string;

class QFSHelper : public FileSystemHelper {

	public:
		void Connect(); 
		void Connect(string metaserverhost, int metaserverport);
		bool IsFileExists(const char *fname);
		bool IsDirectoryExists(const char *dirname);
		int getSize(const char *fname);
		int ListDir(const char *pathname, vector<string> &result);
		int CreateDirectory(const char *pathname);

	public:	
	KFS::KfsClient *kfsClient;
};
