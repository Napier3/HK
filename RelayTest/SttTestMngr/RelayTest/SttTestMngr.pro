QT += core network
QT -= gui

TARGET = SttTestMngr
CONFIG += console

DEFINES +=_PSX_IDE_QT_ _PSX_QT_LINUX_  _USE_NO_GUI_ NOT_USE_XLANGUAGE  XML_USE_PUGIXML USE_Custom_CDateTime _USE_IN_IED_QT5

INCLUDEPATH += ../../../Module/OSInterface
INCLUDEPATH += ../../../Module/OSInterface/QT

TEMPLATE = app
OBJECTS_DIR = ./ObjectFiles

DESTDIR = "/home/zy/Work330/TestServer_TestManger/mnt2/mnt/Stt/Bin"

QMAKE_CXXFLAGS += -Wno-unused-parameter -Wno-unused-but-set-parameter
QMAKE_CXXFLAGS += -Wno-write-strings -Wno-unused-variable

SOURCES += main.cpp \
    ../../../61850/Module/CfgDataMngr/IecCfgDataMngrGlobal.cpp \
    ../../../Module/API/HexTransApi.cpp \
    ../../../Module/API/StringConvert/String_Gbk_To_Utf8.cpp \
    ../../../Module/API/StringConvert/String_Utf8_To_Gbk.cpp \
    ../../../Module/BaseClass/BaseList.cpp \
    ../../../Module/BaseClass/BaseObject.cpp \
    ../../../Module/BaseClass/BinarySerialBuffer.cpp \
    ../../../Module/BaseClass/ExBaseList.cpp \
    ../../../Module/BaseClass/ExBaseObject.cpp \
    ../../../Module/BaseClass/SerializeBufferBase.cpp \
    ../../../Module/BaseClass/WSerializeBuff.cpp \
    ../../../Module/BaseClass/XDbBaseLib.cpp \
    ../../../Module/DataMngr/DataGroup.cpp \
    ../../../Module/DataMngr/DataMngrGlobal.cpp \
    ../../../Module/DataMngr/DataMngrTrans.cpp \
    ../../../Module/DataMngr/DataType.cpp \
    ../../../Module/DataMngr/DataTypeValue.cpp \
    ../../../Module/DataMngr/DataTypes.cpp \
    ../../../Module/DataMngr/DvmData.cpp \
    ../../../Module/DataMngr/DvmValue.cpp \
    ../../../Module/DataMngr/ShortData.cpp \
    ../../../Module/DataMngr/ShortDatas.cpp \
    ../../../Module/DataMngr/Value.cpp \
    ../../../Module/DataMngr/Values.cpp \
    ../../../Module/MemBuffer/EquationBuffer.cpp \
    ../../../Module/MemBuffer/EquationKey.cpp \
    ../../../Module/MemBuffer/StringToSystimeBuffer.cpp \
    ../../../Module/OSInterface/QT/CDateTime_QT.cpp \
    ../../../Module/xml/PugiXML/pugixml.cpp \
    ../../../Module/xml/XmlRWBase.cpp \
    ../../../Module/xml/XmlRWFactory.cpp \
    ../../../Module/xml/XmlRW_Pugi.cpp \
    ../../Module/SttCmd/SttCmdDefineGlobal.cpp \
    ../../Module/SttTestBase/SttMacroXmlKeys.cpp \
    ../../Module/SttTestBase/SttXmlSerialize.cpp \
    ../../Module/SttTestBase/SttXmlSerializeBase.cpp \
    SttTestMngr.cpp \
    ../../Module/SttSocket/Multicast/SttMulticastServerSocket.cpp \
    ../../Module/SttSocket/Multicast/SttUdpSocketDataBase.cpp \
    ../../Module/SttSocket/Multicast/SttMulticastClientSocket.cpp \
    ../../../Module/Log/LogPrint.cpp \
    ../../Module/SttProtocolBufBase.cpp \
    ../../../Module/API/GlobalConfigApi.cpp \
    ../../../Module/OSInterface/QT/CString_QT.cpp \
    ../../Module/API/NetworkInterface.cpp \
    ../../Module/API/QT/NetworkInterface_QT.cpp \
    ../../../Module/API/StringApi.cpp \
    ../../../Module/MemBuffer/ExpandMemBuf.cpp \
    ../../../Module/OSInterface/QT/CXArray_QT.cpp \
    ../../../Module/API/FileApi.cpp \
    ../../../Module/OSInterface/QT/CFile_QT.cpp \
    ../../../Module/API/GlobalApi.cpp \
    ../../../Module/OSInterface/QT/CTime_QT.cpp \
    ../../../Module/OSInterface/QT/XGlobalDefine_QT.cpp \
    ../../../Module/MemBuffer/XMemBufferBse.cpp \
    ../../../Module/OSInterface/QT/CWinThread_QT.cpp \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWnd.cpp \
    ../../../Module/MemBuffer/BufferBase.cpp \
    ../../../Module/OSInterface/QT/XMsgCycleBuffer.cpp \
    ../../Module/Protocol/SttProtocolDatas.cpp \
    ../../../Module/BaseClass/XObjectRefBase.cpp \
    ../../../Module/Socket/WinBaseSocket.cpp \
    ../../../Module/Socket/WinUdpScoket.cpp

HEADERS += \
    ../../../61850/Module/CfgDataMngr/IecCfgDataMngrGlobal.h \
    ../../../Module/API/HexTransApi.h \
    ../../../Module/API/StringConvert/String_Gbk_To_Utf8.h \
    ../../../Module/API/StringConvert/String_Utf8_To_Gbk.h \
    ../../../Module/BaseClass/BaseList.h \
    ../../../Module/BaseClass/BaseObject.h \
    ../../../Module/BaseClass/BinarySerialBuffer.h \
    ../../../Module/BaseClass/ExBaseList.h \
    ../../../Module/BaseClass/ExBaseObject.h \
    ../../../Module/BaseClass/SerializeBufferBase.h \
    ../../../Module/BaseClass/WSerializeBuff.h \
    ../../../Module/BaseClass/XDbBaseLib.h \
    ../../../Module/DataMngr/DataGroup.h \
    ../../../Module/DataMngr/DataMngrGlobal.h \
    ../../../Module/DataMngr/DataMngrTrans.h \
    ../../../Module/DataMngr/DataType.h \
    ../../../Module/DataMngr/DataTypeValue.h \
    ../../../Module/DataMngr/DataTypes.h \
    ../../../Module/DataMngr/DvmData.h \
    ../../../Module/DataMngr/DvmValue.h \
    ../../../Module/DataMngr/ShortData.h \
    ../../../Module/DataMngr/ShortDatas.h \
    ../../../Module/DataMngr/Value.h \
    ../../../Module/DataMngr/Values.h \
    ../../../Module/MemBuffer/EquationBuffer.h \
    ../../../Module/MemBuffer/EquationKey.h \
    ../../../Module/MemBuffer/StringToSystimeBuffer.h \
    ../../../Module/OSInterface/QT/CDateTime_QT.h \
    ../../../Module/xml/PugiXML/pugiconfig.hpp \
    ../../../Module/xml/PugiXML/pugixml.hpp \
    ../../../Module/xml/XmlRWBase.h \
    ../../../Module/xml/XmlRWFactory.h \
    ../../../Module/xml/XmlRWInterface.h \
    ../../../Module/xml/XmlRW_Pugi.h \
    ../../Module/SttCmd/SttCmdDefineGlobal.h \
    ../../Module/SttTestBase/SttMacroXmlKeys.h \
    ../../Module/SttTestBase/SttXmlSerialize.h \
    ../../Module/SttTestBase/SttXmlSerializeBase.h \
    SttTestMngr.h \
    ../../Module/SttSocket/Multicast/SttGlobalMulticastDef.h \
    ../../Module/SttSocket/Multicast/SttMulticastServerSocket.h \
    ../../Module/SttSocket/Multicast/SttUdpSocketDataBase.h \
    ../../../Module/OSInterface/OSInterface.h \
    ../../../Module/OSInterface/QT/stdafx.h \
    ../../Module/SttSocket/Multicast/SttMulticastClientSocket.h \
    ../../../Module/Log/LogPrint.h \
    ../../Module/SttProtocolBufBase.h \
    ../../../Module/API/GlobalConfigApi.h \
    ../../../Module/OSInterface/QT/CString_QT.h \
    ../../Module/API/NetworkInterface.h \
    ../../../Module/API/StringApi.h \
    ../../../Module/MemBuffer/ExpandMemBuf.h \
    ../../../Module/OSInterface/QT/CXArray_QT.h \
    ../../../Module/API/FileApi.h \
    ../../../Module/OSInterface/QT/CFile_QT.h \
    ../../../Module/API/GlobalApi.h \
    ../../../Module/OSInterface/QT/CTime_QT.h \
    ../../../Module/OSInterface/QT/XGlobalDefine_QT.h \
    ../../../Module/MemBuffer/XMemBufferBse.h \
    ../../../Module/OSInterface/QT/CWinThread_QT.h \
    ../../../Module/OSInterface/QT/CXCtrl_QT_CWnd.h \
    ../../../Module/MemBuffer/BufferBase.h \
    ../../../Module/OSInterface/QT/XMsgCycleBuffer.h \
    ../../Module/Protocol/SttProtocolDatas.h \
    ../../../Module/BaseClass/XObjectRefBase.h \
    ../../../Module/Socket/WinBaseSocket.h \
    ../../../Module/Socket/WinUdpScoket.h

