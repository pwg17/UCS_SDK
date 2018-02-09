/* sk_skfakemetastruct.h

  Generated by skxml2struct from fakemeta.xml

  Please DO NOT edit unless you know exactly what you are doing.


*/

#pragma once

#include "iTLVPickle.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
	eTypeSKFakeMetaEchoInfo = Comm::eTypeSKUserDefine + 1,
	eTypeSKFakeMetaField,
	eTypeSKFakeMetaStruct,
	eTypeSKFakeMetaParam,
	eTypeSKFakeMetaFunc,
	eTypeSKFakeMetaInfo
};

enum {
	eFuncSKFakeMetaSKGetMetainfo = 9998,
	eFuncSKFakeMetaSKEcho = 9999
};

//#pragma pack(1)

typedef struct tagSKFakeMetaEchoInfo {
	unsigned int iEchoLen;
	char * pcEchoStr;
} SKFakeMetaEchoInfo_t;

typedef struct tagSKFakeMetaField {
	char * pcName;

	short hOffset;
	short hType;
	char cIsPtr;
	char cIsRequired;
	short hArraySize;
	char * pcReferTo;

	short hId;
	short hFieldSize;
	short hItemSize;
	unsigned char cStatus;
	char cReserved;
} SKFakeMetaField_t;

typedef struct tagSKFakeMetaStruct {
	short hId;
	char * pcName;

	unsigned int iSize;
	unsigned short hFieldCount;
	SKFakeMetaField_t * ptFieldList;
} SKFakeMetaStruct_t;

typedef struct tagSKFakeMetaParam {
	char * pcName;

	short hType;
	char cExistence;
} SKFakeMetaParam_t;

typedef struct tagSKFakeMetaFunc {
	char * pcName;

	short hCmdid;
	SKFakeMetaParam_t tReq;
	SKFakeMetaParam_t tResp;
} SKFakeMetaFunc_t;

typedef struct tagSKFakeMetaInfo {
	char * pcPrefix;

	char * pcName;

	int iMagic;
	short hStructCount;
	SKFakeMetaStruct_t * ptStructList;

	short hFuncCount;
	SKFakeMetaFunc_t * ptFuncList;
} SKFakeMetaInfo_t;

//#pragma pack()


namespace Comm {
	typedef struct tagSKMetaInfo SKMetaInfo_t;
}
extern const Comm::SKMetaInfo_t * g_ptSKFakeMetaMetaInfo;
extern const Comm::SKMetaInfoFinder * g_ptSKFakeMetaMetaInfoFinder;

namespace Comm {
	class SKBuffer;
}
class SKFakeMetaPickle
{
public:
	static int ToBuffer( const SKFakeMetaEchoInfo_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaEchoInfo_t * ptStruct );
	static int FreeStructField( SKFakeMetaEchoInfo_t & tStruct );
	static int DeepCopy( SKFakeMetaEchoInfo_t * pDestStruct, const SKFakeMetaEchoInfo_t * pSourceStruct );
	static int Diff( SKFakeMetaEchoInfo_t * ptStruct1, SKFakeMetaEchoInfo_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaEchoInfo_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaEchoInfo_t * ptStruct, int iPickleType, int iPickleStatus );

	static int ToBuffer( const SKFakeMetaField_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaField_t * ptStruct );
	static int FreeStructField( SKFakeMetaField_t & tStruct );
	static int DeepCopy( SKFakeMetaField_t * pDestStruct, const SKFakeMetaField_t * pSourceStruct );
	static int Diff( SKFakeMetaField_t * ptStruct1, SKFakeMetaField_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaField_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaField_t * ptStruct, int iPickleType, int iPickleStatus );

	static int ToBuffer( const SKFakeMetaStruct_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaStruct_t * ptStruct );
	static int FreeStructField( SKFakeMetaStruct_t & tStruct );
	static int DeepCopy( SKFakeMetaStruct_t * pDestStruct, const SKFakeMetaStruct_t * pSourceStruct );
	static int Diff( SKFakeMetaStruct_t * ptStruct1, SKFakeMetaStruct_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaStruct_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaStruct_t * ptStruct, int iPickleType, int iPickleStatus );

	static int ToBuffer( const SKFakeMetaParam_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaParam_t * ptStruct );
	static int FreeStructField( SKFakeMetaParam_t & tStruct );
	static int DeepCopy( SKFakeMetaParam_t * pDestStruct, const SKFakeMetaParam_t * pSourceStruct );
	static int Diff( SKFakeMetaParam_t * ptStruct1, SKFakeMetaParam_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaParam_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaParam_t * ptStruct, int iPickleType, int iPickleStatus );

	static int ToBuffer( const SKFakeMetaFunc_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaFunc_t * ptStruct );
	static int FreeStructField( SKFakeMetaFunc_t & tStruct );
	static int DeepCopy( SKFakeMetaFunc_t * pDestStruct, const SKFakeMetaFunc_t * pSourceStruct );
	static int Diff( SKFakeMetaFunc_t * ptStruct1, SKFakeMetaFunc_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaFunc_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaFunc_t * ptStruct, int iPickleType, int iPickleStatus );

	static int ToBuffer( const SKFakeMetaInfo_t * ptStruct, Comm::SKBuffer * poBuffer );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaInfo_t * ptStruct );
	static int FreeStructField( SKFakeMetaInfo_t & tStruct );
	static int DeepCopy( SKFakeMetaInfo_t * pDestStruct, const SKFakeMetaInfo_t * pSourceStruct );
	static int Diff( SKFakeMetaInfo_t * ptStruct1, SKFakeMetaInfo_t * ptStruct2 );
	static int ToBuffer( const SKFakeMetaInfo_t * ptStruct, Comm::SKBuffer * poBuffer, int iPickleType, int iPickleStatus );
	static int FromBuffer( Comm::SKBuffer * poBuffer, SKFakeMetaInfo_t * ptStruct, int iPickleType, int iPickleStatus );

	static void SetNetworkByteOrder( int iNetworkByteOrder );
	static void SetPickleType( int iPickleType );
	static int GetPickleType( );
	static void SetPickleStatus( int iPickleStatus );

private:
	static int m_iNetworkByteOrder;
	static int m_iPickleType;
	static int m_iPickleStatus;
};


#ifdef __cplusplus
}
#endif
