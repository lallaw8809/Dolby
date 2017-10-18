/*----------Start of mycall.c----------*/
#include <linux/linkage.h>
asmlinkage long sys_mycall(int i, int j)
{
return(i+j);
}
/*-----------End of mycall.c-----------*/

