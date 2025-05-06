#include "stdafx.h"
#include "XDriverFuncDef.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>	//SIGIO
#include<sys/syscall.h>
#include <sys/types.h>
#include <sys/mman.h>


#include <QDebug>


int drv_reg_open(char *pszFileName, int nLine, char *file, unsigned int flag)
{
	qDebug() << pszFileName << nLine << ": open=" <<file << "  flag=" << flag;
	return open(file, flag);
}

int drv_reg_read(char *pszFileName, int nLine, int nFile, void* buf, int cmd)
{
	qDebug() << pszFileName << nLine << ": read=" <<nFile << "  buf=" << (unsigned int)buf << "  cmd=" << QString::number(cmd, 16).toUpper();
    return read(nFile, buf, cmd);
}

int drv_reg_write(char *pszFileName, int nLine, int nFile, void* buf, int count)
{
    qDebug() << pszFileName << nLine << ": write=" <<nFile << "  buf=" << (unsigned int)buf << "  count=" << count;
    return write(nFile, buf, count);
}

long drv_reg_ioctl(char *pszFileName, int nLine, int nFile, unsigned int cmd, unsigned long arg)
{
    qDebug() << pszFileName << nLine << ": ioctl=" << nFile << "  cmd=" << QString::number(cmd, 16).toUpper() << "  arg=" << QString::number(arg, 16).toUpper();
    return ioctl(nFile, cmd, arg);
}
