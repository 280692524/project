#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gcommand.h"


int main()
{
	char p[512] = {0};
	char q[512] = {0};
	gets(p);//输入参数1
	gets(q);//输入参数2
	get_command(p,q);
	return 0;	
}
