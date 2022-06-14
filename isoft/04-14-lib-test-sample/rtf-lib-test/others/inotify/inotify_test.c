#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <linux/inotify.h>
 
#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )
 
int main( )
{
	int length, i = 0;
	int fd;
	int wd;
	char buffer[EVENT_BUF_LEN];
 
	/*creating the INOTIFY instance*/
	fd = inotify_init();
 
	/*checking for error*/
	if (fd < 0) {
		perror("inotify_init");
	}
 
	/*adding the “/tmp” directory into watch list. Here, the suggestion is to validate the existence of the directory before adding into monitoring list.*/
	wd = inotify_add_watch(fd, "/tmp", IN_CREATE | IN_DELETE);
	inotify_add_watch(fd, "/tmp/dir1", IN_CREATE | IN_DELETE);  //添加了一个子目录进行监听，默认是不会监听子目录的
	/*read to determine the event change happens on “/tmp” directory. Actually this read blocks until the change event occurs*/
 
	for ( ; ;)  // 在外面加了一个循环，防止监听完一个事件后就退出了
	{
		i = 0;
		length = read(fd, buffer, EVENT_BUF_LEN);
 
		/*checking for error*/
		if (length < 0) {
			perror("read");
		}
 
		/*actually read return the list of change events happens. Here, read the change event one by one and process it accordingly.*/
		while (i < length) {
			struct inotify_event *event = (struct inotify_event *) &buffer[i];
			if (event->len) {
				if (event->mask & IN_CREATE) {
					if (event->mask & IN_ISDIR) {
						printf("New directory %s created.\n", event->name);
					} else {
						printf("New file %s created.\n", event->name);
					}
				} else if (event->mask & IN_DELETE) {
					if (event->mask & IN_ISDIR) {
						printf("Directory %s deleted.\n", event->name);
					} else {
						printf("File %s deleted.\n", event->name);
					}
				}
			}
			i += EVENT_SIZE + event->len;
		}
 
	}
	/*removing the “/tmp” directory from the watch list.*/
	inotify_rm_watch(fd, wd);
	/*closing the INOTIFY instance*/
	close(fd);
	return 0;
}
