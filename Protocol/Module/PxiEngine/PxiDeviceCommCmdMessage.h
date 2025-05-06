#pragma once

class CPxiDeviceCommCmdMessage
{
public:
	CPxiDeviceCommCmdMessage(void);
	virtual ~CPxiDeviceCommCmdMessage(void);

 public:
 	virtual void OnCommCmdMessage(WPARAM wParam, LPARAM lParam) = 0;
 	virtual void OnSysMessage(WPARAM wParam, LPARAM lParam) = 0;
 	
 	//2023-2-1  Eric
 	virtual void OnEventMessage(WPARAM wParam, LPARAM lParam){};
 
     //2020-11-24  Eric LINUX  post msg to ats
     virtual void OnEngineDataDeleted(const CString &strDeviceID){};
 
 	//2023-3-5  Eric
 	virtual void OnReportMessage(WPARAM wParam, LPARAM lParam){};
};
