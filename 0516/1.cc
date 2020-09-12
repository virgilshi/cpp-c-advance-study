#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

namespace spdk{

struct Status{
	bool stat;
	bool OK() { return stat; }
}Status;
class SpdkSequentialFile{
	private:
		std::string filename;
		int ref;		
		int fd;
		
	public:
		SpdkSequentialFile(std::string &name) : ref(0) ;
		~SpdkSequentialFile(void);
		Status Read(size_t n, char *result);
		Status Write(size_t n, char *buf);
		int GetFD(void){ return fd; }
		
};

SpdkSequentialFile::SpdkSequentialFile(std::string &name){
	printf("Create SequentialFile\n");
	this.fd = ::creat(name.c_str(), 0777);	
}

SpdkSequentialFile::~SpdkSequentialFile(){
	printf("Destroy SF.\n");
}

SpdkSequentialFile::Read(size_t n, char *result){
	::read(GetFD(), result, n);
}

SpdkSequentialFile::Write(Size_t n, char* buf){
	::write(GetFD(), buf, n);
}
} // namespace spdk

int main(int argc, char **argv){
	class SpdkSequentialFile file("1.txt");
	file.Write(10, "test");
	char *buf = new char(20);
	memset(buf,0,20);
	file.Read((20, buf));
	printf("buf = %s\n", buf);
	
	
	return 0;
}











