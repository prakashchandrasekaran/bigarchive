#include "file_system_helper.h"
#include "KfsClient.h"

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
