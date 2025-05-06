#pragma once


//int drv_reg_open(char *pszFileName, int nLine, char *file, unsigned int flag);
//int drv_reg_read(char *pszFileName, int nLine, int nFile, char* buf, int cmd);
//int drv_reg_write(char *pszFileName, int nLine, int nFile, char* buf, int count);
//long drv_reg_ioctl(char *pszFileName, int nLine, int nFile, unsigned int cmd, unsigned long arg);

int drv_reg_open(char *pszFileName, int nLine, char *file, unsigned int flag);
int drv_reg_read(char *pszFileName, int nLine, int nFile, void* buf, int cmd);
int drv_reg_write(char *pszFileName, int nLine, int nFile, void* buf, int count);
long drv_reg_ioctl(char *pszFileName, int nLine, int nFile, unsigned int cmd, unsigned long arg);
