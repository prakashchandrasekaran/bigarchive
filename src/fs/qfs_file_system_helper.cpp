#include "qfs_file_system_helper.h"

/*
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

 // Define static logger variable
LoggerPtr logger(Logger::getLogger( "appendstore.qfs_helper"));
*/

		void QFSHelper::Connect() 
		{	
			Connect(string("localhost"), 40000);
			LOG4CXX_INFO(logger, "Connected to QFS Master Node");
		}

		void QFSHelper::Connect(string metaserverhost, int metaserverport) 
		{
			kfsClient = KFS::Connect(metaserverhost, metaserverport);
			if (! kfsClient ) {
				LOG4CXX_ERROR(logger, "Failed to Connect to QFS Master Node");
			}
		}

		bool QFSHelper::IsFileExists(const char *fname)
		{
		 return kfsClient->Exists(fname);
		}

		bool QFSHelper::IsDirectoryExists(const char *dirname)
		{
		 return kfsClient->Exists(dirname);
		}

		int QFSHelper::getSize(const char *fname)
		{
			KFS::KfsFileAttr kfsattr; // = new KfsFileAttr(); // Stat method takes reference of this object
			kfsClient->Stat(fname, kfsattr, true); // true is for computing the size
			return kfsattr.fileSize;
		}

		int QFSHelper::ListDir(const char *pathname, vector<string> &result)
		{
			return kfsClient->Readdir(pathname, result);
		}

		int QFSHelper::CreateDirectory(const char *pathname) {
			int ret = kfsClient->Mkdir(pathname); // mode is 0777 by default
			if(ret != 0) {
				LOG4CXX_ERROR(logger, "Directory Creation failed : " << pathname);
			}	
			return ret;
  		}


