         N   M        ����������N�3���sK��b^            u#include <fcntl.h>

int
dup (int fd1) {
	return (fcntl (fd1, F_DUPFD, 0));
}
