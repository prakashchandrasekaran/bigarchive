#ifndef APPENDSTORE_EXCEPTION_H
#define APPENDSTORE_EXCEPTION_H

#include <string>
#include <exception>
#include <tr1/memory>


#define DEFINE_EXCEPTION(ExClass, Base)          \
    ExClass(const std::string& strMsg="") throw()       \
        : Base(strMsg)                                  \
    {}                                                  \
                                                        \
    ~ExClass() throw(){}                                      \
                                                              \
    /* override */ std::string GetClassName() const           \
    {                                                         \
        return #ExClass;                                      \
    }                                                         \
                                                              \
    /* override */ std::tr1::shared_ptr<ExceptionBase> Clone() const    \
    {                                                                   \
        return std::tr1::shared_ptr<ExceptionBase>(new ExClass(*this)); \
    }


#define THROW_EXCEPTION(ExClass, args...)                                  \
    do                                                                  \
    {                                                                   \
        ExClass tmp_3d3079a0_61ec_48e6_abd6_8a33b0eb91f0(args);         \
        tmp_3d3079a0_61ec_48e6_abd6_8a33b0eb91f0.Init(__FILE__, __PRETTY_FUNCTION__, __LINE__); \
        throw tmp_3d3079a0_61ec_48e6_abd6_8a33b0eb91f0;                 \
    } while (false)


class ExceptionBase : public std::exception
{
public:
    ExceptionBase(const std::string& message = "") throw();
    virtual ~ExceptionBase() throw();
protected:
    std::string mMessage;
private:
    mutable std::string mWhat;
};

class AppendStoreExceptionBase : public  ExceptionBase
{
public:
    AppendStoreExceptionBase(const std::string& message = "") throw ()
        : ExceptionBase(message)
    {}
};

class AppendStoreWriteException : public AppendStoreExceptionBase
{
public:
    AppendStoreWriteException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreReadException : public AppendStoreExceptionBase
{
public:
    AppendStoreReadException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreInvalidIndexException : public AppendStoreExceptionBase
{
public:
    AppendStoreInvalidIndexException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreInvalidChunkException : public AppendStoreExceptionBase
{
public:
    AppendStoreInvalidChunkException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreCompressionException : public AppendStoreExceptionBase
{
public:
    AppendStoreCompressionException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreCodecException : public AppendStoreExceptionBase
{
public:
    AppendStoreCodecException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreMisMatchedVerException: public AppendStoreExceptionBase
{
public:
    AppendStoreMisMatchedVerException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreNotExistException: public AppendStoreExceptionBase
{
public:
    AppendStoreNotExistException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};

class AppendStoreFactoryException: public AppendStoreExceptionBase
{
public:
    AppendStoreFactoryException(const std::string& message = "") throw ()
        : AppendStoreExceptionBase(message)
    {}
};


class StorageExceptionBase : public ExceptionBase
{
public:
    DEFINE_EXCEPTION(StorageExceptionBase, ExceptionBase);
};


class FileExistException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(FileExistException, StorageExceptionBase);
};

// when open/delete/rename/... an non-exist file
class FileNotExistException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(FileNotExistException, StorageExceptionBase);
};

class DirectoryExistException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(DirectoryExistException, StorageExceptionBase);
};

class DirectoryNotExistException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(DirectoryNotExistException, StorageExceptionBase);
};

class SameNameEntryExistException : public StorageExceptionBase
{
    public:
        DEFINE_EXCEPTION(SameNameEntryExistException, StorageExceptionBase);
};

// when append/delete a file that being appended
class FileAppendingException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(FileAppendingException, StorageExceptionBase);
};

// when opening a file that cannot be overwritten
class FileOverwriteException: public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(FileOverwriteException, StorageExceptionBase);
};

class PangunNotEnoughChunkserverExcepion : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(PangunNotEnoughChunkserverExcepion, StorageExceptionBase);
};

// when read, data is unavailable due to internal error
class DataUnavailableException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(DataUnavailableException, StorageExceptionBase);
};

// when append/commit, data stream is corrupted due to internal error
class StreamCorruptedException : public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(StreamCorruptedException, StorageExceptionBase);
};

// when end of stream comes unexpected
class UnexpectedEndOfStreamException: public StorageExceptionBase
{
public:
    DEFINE_EXCEPTION(UnexpectedEndOfStreamException, StorageExceptionBase);
};





#endif
