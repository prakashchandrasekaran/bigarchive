#include "qfs_file_system_helper.h"

		void QFSHelper::Connect() 
		{
			Connect(string("localhost"), 40000);
		}

		void QFSHelper::Connect(string metaserverhost, int metaserverport) 
		{
			kfsClient = KFS::Connect(metaserverhost, metaserverport);
			if (! kfsClient ) {
				// logging_info("Connected to host and port ");
				// throw exception
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
			return ret;
  		}

