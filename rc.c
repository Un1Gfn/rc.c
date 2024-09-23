#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

extern const int argc;
extern const char *const *const argv;

static int mmm_static(){
	puts("this function show be dropped");
	return 1;
}

int mmm_uname(){
	struct utsname u={};
	const int r=uname(&u);
	if(0!=r)
		return r;
	printf("%s\n%s\n%s\n%s\n%s\n%s\n",
		u.sysname,
		u.nodename,
		u.release,
		u.version,
		u.machine,
		u.domainname
	);
	return 0;
}

int mmm_sqrt_NUMBER(){
	if(!argv[2]){
		puts("err no arg2");
		return 1;
	}
	errno=0;
	char *e=NULL;
	double x=strtold(argv[2], &e);
	if(0!=errno){
		printf("err strtold errno %d %s\n", errno, strerror(errno));
		return errno;
	}
	if(argv[2]==e) {
		printf("err strtold no number detected in \'%s\'\n", argv[2]);
		return 1;
	}
	// man math_error
	printf("%lf\n", sqrt(x));
	return 0;
}

