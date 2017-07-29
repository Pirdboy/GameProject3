﻿#ifndef __GLOBAL_DATA_OBJECT_H__
#define __GLOBAL_DATA_OBJECT_H__
#include "serverStruct.h"
#include "SharedMemory.h"
struct GlobalDataObject : public ShareObject
{
	GlobalDataObject()
	{
		m_dwServerID		= 0;			//服务器ID
		m_u64Guid			= 0;			//全局GUID
	}
	
	UINT32 m_dwServerID;        //服务器ID
	UINT64 m_u64Guid;			//全局GUID
	
	BOOL Save(IDataBase *pDB)
	{ 
		char szSql[1024];
		sprintf(szSql, "REPLACE INTO globaldata (serverid, maxguid) VALUES(%d, %lld);", \
			m_dwServerID, m_u64Guid);

		pDB->Execut(szSql);

		return TRUE;
	}

	BOOL Delete(IDataBase *pDB)
	{
	

		return TRUE;
	}
};


#endif //__GLOBAL_DATA_OBJECT_H__