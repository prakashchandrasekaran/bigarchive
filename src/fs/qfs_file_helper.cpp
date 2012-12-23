#include "qfs_file_helper.h"

	QFSFileHelper::QFSFileHelper(QFSHelper *qfshelper, string fname, int mode) {
		LOG4CXX_INFO(logger, "File helper for file created : " << fname );
		this->qfshelper = qfshelper;
		this->filename = fname;
		this->mode = mode;
		this->fd = -1;
	}

	void QFSFileHelper::Create()
	{
		fd = qfshelper->kfsClient->Create(filename.c_str());
		if (fd < 0) { 
			LOG4CXX_ERROR(logger, "File Creation failed : " << filename);
			// THROW_EXCEPTION
		}
	}

	void QFSFileHelper::Open() {
		fd = qfshelper->kfsClient->Open(filename.c_str(), mode);
		if(fd < 0) { }
	}

	void QFSFileHelper::Close() {
		// flushes out all changes
		qfshelper->kfsClient->Sync(fd);
		// closes the file handle
		qfshelper->kfsClient->Close(fd);
	}

	void QFSFileHelper::Read(char *buffer, int length) {
		int bytes_read = qfshelper->kfsClient->Read(fd, buffer, length);
		if(bytes_read != length) {
			if(bytes_read < 0) {
				LOG4CXX_ERROR(logger, "Failure while reading file " << filename << " " << KFS::ErrorCodeToStr(bytes_read));
			}
		}
	}

	void QFSFileHelper::Write(char *buffer, int length) {
		qfshelper->kfsClient->Write(fd, buffer, length);
	}

	void QFSFileHelper::Seek(int offset) {
		qfshelper->kfsClient->Seek(fd, offset);
	}

	int QFSFileHelper::GetNextLogSize() {
		return -1;
        }


