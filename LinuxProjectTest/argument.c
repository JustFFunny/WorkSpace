
//主要功能是： 长参数和短参数

//int getopt_long(int argc, char * const argv[],const char *optstring, const struct option *longopts,int *longindex);
//函数中的argc和argv通常直接从main()的两个参数传递而来。optsting是选项参数组成的字符串：
//字符串optstring可以下列元素:
//1.单个字符，表示选项，
//2.单个字符后接一个冒号：表示该选项后必须跟一个参数。参数紧跟在选项后或者以空格隔开。该参数的指针赋给optarg。
//3 单个字符后跟两个冒号，表示该选项后可以有参数也可以没有参数。如果有参数，参数必须紧跟在选项后不能以空格隔开。该参数的指针赋给optarg。（这个特性是GNU的扩张）。



/*
optstring是一个字符串，表示可以接受的参数。例如，"a:b:cd"，表示可以接受的参数是a,b,c,d，其中，a和b参数后面跟有更多的参数值。(例如：-a host -b name)
参数longopts，其实是一个结构的实例：
struct option {
const char *name; //name表示的是长参数名
int has_arg； //has_arg有3个值，no_argument(或者是0)，表示该参数后面不跟参数值
// required_argument(或者是1),表示该参数后面一定要跟个参数值
// optional_argument(或者是2),表示该参数后面可以跟，也可以不跟参数值
int *flag;
//用来决定，getopt_long()的返回值到底是什么。如果flag是null(通常情况)，则函数会返回与该项option匹配的val值;如果flag不是NULL，则将val值赋予flag所指向的内存，并且返回值设置为0。
int val; //和flag联合决定返回值
}
*/
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char * program_name;

void print_usage(FILE * stream,int exit_code)
{
	fprintf(stream,"usage:%s option \n",program_name);
	fprintf(stream,
"-h --help Display the info.\n" 
"-o --output filename Write out to file.\n"
"-v --Verbose Print the Message.\n");
exit(exit_code);
}
int main(int argc,char *argv[])
{
int next_option;
const char* const short_options="ho:v";
const struct option long_options[]=
{
{"help",0,NULL,'h'},
{"output",1,NULL,'o'},
{"verbose",0,NULL,'v'},
{NULL,0,NULL,0}
};
const char *output_filename=NULL;

int verbose=0;

program_name=argv[0];
do
{next_option=getopt_long(argc,argv,short_options,long_options,NULL);
switch(next_option)
{

case 'h':

print_usage (stdout,0);
case 'o':
output_filename = optarg;
printf("this file name %s\n",optarg);
break;
case 'v':
verbose = 1;
break;
case '?':
print_usage (stderr, 1);
case -1: 
break;
default: 
abort ();
}
}
while (next_option != -1);

if (verbose) 
{
int i;
for (i = optind; i < argc; ++i)
printf ("Argument: %s\n", argv[i]);
}

return 0;

}
